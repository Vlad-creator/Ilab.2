struct region;
struct tree_node;
class octo_tree;

struct region
{
private:
	float edge;
	point center;

public:
	region();
	~region();

	void set_edge(float edge_){edge = edge_;}
	float get_edge(){return edge;}
	point get_center(){return center;}
	bool check_point(point for_check);

	friend class tree_node;
	friend class octo_tree;
};

struct tree_node
{
private:
	region space;
	std::vector<triangle> TRs_;
	tree_node* children[8];

public:
	tree_node();
	tree_node(std::vector<triangle> TRs);
	~tree_node();

	friend class octo_tree;
};

class octo_tree
{
	tree_node* node_t;

public:
	void set_edge();
	std::vector<region> make_regions(region parent);
	std::vector<triangle> sort_triangles(std::vector<triangle> parent , region space_);
	void make_tree(tree_node* parent , tree_node* node , int zone);
	void generate_tree();
	//void print();

	octo_tree();
	octo_tree(std::vector<triangle> TRs);
	~octo_tree();
};

region::region()
{
	center.x_ = 0;
	center.y_ = 0;
	center.z_ = 0;
	edge = 0;
}

region::~region()
{
	center.x_ = 0;
	center.y_ = 0;
	center.z_ = 0;
	edge = 0;
}

bool region::check_point(point for_check)
{
	if ((for_check.x_ > center.x_ + edge) || (for_check.x_ < center.x_ - edge))
		return false;
	else
		if ((for_check.y_ > center.y_ + edge) || (for_check.y_ < center.y_ - edge))
			return false;
		else
			if ((for_check.z_ > center.z_ + edge) || (for_check.z_ < center.z_ - edge))
				return false;
			else
				return true;
}

tree_node::tree_node()
{
	space.center.x_ = 0;
	space.center.y_ = 0;
	space.center.z_ = 0;
	space.edge = 0;

	for (int i = 0 ; i < 8 ; ++i)
	{
		children[i] = nullptr;
	}
}

tree_node::tree_node(std::vector<triangle> TRs)
{
	space.center.x_ = 0;
	space.center.y_ = 0;
	space.center.z_ = 0;
	space.edge = 0;

	TRs_ = TRs;

	for (int i = 0 ; i < 8 ; ++i)
	{
		children[i] = nullptr;
	}
}

tree_node::~tree_node()
{
	/*for (int i = 0 ; i < 8 ; ++i)
	{
		free(children[i]);
	}*/
}

octo_tree::octo_tree()
{
	node_t = new tree_node;

	node_t->space.center.x_ = 0;
	node_t->space.center.y_ = 0;
	node_t->space.center.z_ = 0;
	node_t->space.edge = 0;

	for (int i = 0 ; i < 8 ; ++i)
	{
		node_t->children[i] = nullptr;
	}
}

octo_tree::octo_tree(std::vector<triangle> TRs)
{
	node_t = new tree_node;

	node_t->space.center.x_ = 0;
	node_t->space.center.y_ = 0;
	node_t->space.center.z_ = 0;
	node_t->space.edge = 0;

	node_t->TRs_ = TRs;

	for (int i = 0 ; i < 8 ; ++i)
	{
		node_t->children[i] = nullptr;
	}
}

octo_tree::~octo_tree()
{
	tree_node* node = nullptr;
	std::queue<tree_node*> per;
	per.push(node_t);

	while (per.empty() == false)
	{
		node = per.front();
		per.pop();

		for (int i = 0 ; i < 8 ; ++i)
		{
			if (node->children[i] != nullptr)
				per.push(node->children[i]);
		}
		delete node;
	}
}

std::vector<region> octo_tree::make_regions(region parent)
{
	region children[8];
	std::vector<region> res;
	for (int i = 0 ; i < 8 ; ++i)
	{
		if ((i == 0) || (i == 1) || (i == 2) || (i == 3))
			children[i].center.y_ = parent.center.y_ + parent.edge / 2;
		else
			children[i].center.y_ = parent.center.y_ - parent.edge / 2;

		if ((i == 1) || (i == 2) || (i == 5) || (i == 6))
			children[i].center.x_ = parent.center.x_ + parent.edge / 2;
		else
			children[i].center.x_ = parent.center.x_ - parent.edge / 2;

		if ((i == 0) || (i == 1) || (i == 4) || (i == 5))
			children[i].center.z_ = parent.center.z_ + parent.edge / 2;
		else
			children[i].center.z_ = parent.center.z_ - parent.edge / 2;

		children[i].edge = parent.edge / 2;
	}

	for (int i = 0 ; i < 8 ; ++i)
		res.push_back(children[i]);

	/*for (auto it = res.begin() ; it != res.end() ; ++it)
	{
		std::cout << "center - ";
		it->center.print();
		std::cout << "edge - " << it->edge << std::endl;
	}*/

	return res;
}

std::vector<triangle> octo_tree::sort_triangles(std::vector<triangle> parent , region space_)
{	
	std::vector<triangle> TRs;
	for(auto it = parent.begin() ; it != parent.end() ; ++it)
	{
		/*std::cout << "test write" << std::endl;
		std::cout << space_.edge << std::endl;
		space_.center.print();
		it->print();
		std::cout << "end of test write" << std::endl;*/
		if ((space_.check_point(it->p1_)) || (space_.check_point(it->p2_)) || (space_.check_point(it->p3_)))
		{
			TRs.push_back(*it);
		}
	}

	/*std::cout << "centet - ";
	space_.center.print();

	for(auto it = TRs.begin() ; it != TRs.end() ; ++it)
	{
		std::cout << "triangle - ";
		it->print();
	}*/

	return TRs;
}

void octo_tree::set_edge()
{
	float edge_res = 0;
	for (auto it = node_t->TRs_.begin() ; it != node_t->TRs_.end() ; ++it)
		if (edge_res < it->max_point())
			edge_res = it->max_point();

	node_t->space.edge = edge_res;

	//std::cout << "edge - " << edge_res << std::endl;
}

void octo_tree::make_tree(tree_node* parent , tree_node* node , int zone)
{	
	assert(node != nullptr);
	int zone_count = 0;
	if ((node->TRs_.size() >= 4) && (node->space.edge > 1))
	{
		parent->children[zone] = node;
		std::vector<region> regions = make_regions(parent->space);
		/*for (auto it = regions.begin() ; it != regions.end() ; ++it)
		{
			std::cout << "edge - " << it->get_edge() << std::endl;
			std::cout << "center - ";
			(it->get_center()).print();
		}*/
		for (auto it = regions.begin() ; it != regions.end() ; ++it)
		{
			tree_node* new_node = new tree_node;
			std::vector<triangle> zones_triangles = sort_triangles(node->TRs_ , *it);

			new_node->space = *it;
			new_node->TRs_ = zones_triangles;

			make_tree(parent->children[zone] , new_node , zone_count);

			zone_count++;
		}
	}
	else
	{
		/*std::cout << std::endl << "this is new node" << std::endl;
		std::cout << "edge - " << node->space.edge << std::endl;
		std::cout << "center - ";
		node->space.center.print();
		for (auto it = node->TRs_.begin() ; it != node->TRs_.end() ; ++it)
		{
			std::cout << "triangle:" << std::endl;
			it->print();
		}*/
		for (auto it_1 = node->TRs_.begin() ; it_1 != node->TRs_.end() ; ++it_1)
			for (auto it_2 = node->TRs_.begin() ; it_2 != node->TRs_.end() ; ++it_2)
				if ((it_1 != it_2) && (is_cross(*it_1 , *it_2)))
				{
					std::cout << "this triagles are crossed:" << std::endl;
					it_1->print();
					std::cout << std::endl;
					it_2->print();
				}
	}
	/*std::cout << std::endl << "this is new node" << std::endl;
	std::cout << "edge - " << node->space.edge << std::endl;
	std::cout << "center - ";
	node->space.center.print();*/
	/*for (auto it = node->TRs_.begin() ; it != node->TRs_.end() ; ++it)
	{
		std::cout << "triangle:" << std::endl;
		it->print();
	}*/
}

void octo_tree::generate_tree()
{
	std::vector<region> regions = make_regions(node_t->space);
	/*for (auto it = regions.begin() ; it != regions.end() ; ++it)
	{
		std::cout << "edge - " << it->get_edge() << std::endl;
		std::cout << "center - ";
		(it->get_center()).print();
	}*/
	if ((node_t->TRs_.size() >= 4) && (node_t->space.edge > 0.1))
	{
		for (int i = 0 ; i < 8 ; ++i)
		{
			tree_node* new_node = new tree_node;

			new_node->space = regions[i];
			new_node->TRs_ = sort_triangles(node_t->TRs_ , regions[i]);

			make_tree(node_t , new_node , i);
		}
	}
	else
	{
		/*std::cout << std::endl << "this is new node" << std::endl;
		std::cout << "edge - " << node_t->space.edge << std::endl;
		std::cout << "center - ";
		node_t->space.center.print();
		for (auto it = node_t->TRs_.begin() ; it != node_t->TRs_.end() ; ++it)
		{
			std::cout << "triangle:" << std::endl;
			it->print();
		}*/
		for (auto it_1 = node_t->TRs_.begin() ; it_1 != node_t->TRs_.end() ; ++it_1)
			for (auto it_2 = node_t->TRs_.begin() ; it_2 != node_t->TRs_.end() ; ++it_2)
				if ((it_1 != it_2) && (is_cross(*it_1 , *it_2)))
				{
					std::cout << "this triagles are crossed:" << std::endl;
					it_1->print();
					std::cout << std::endl;
					it_2->print();
				}
	}
	/*std::cout << std::endl << "this is new node" << std::endl;
	std::cout << "edge - " << node_t->space.edge << std::endl;
	std::cout << "center - ";
	node_t->space.center.print();
	for (auto it = node_t->TRs_.begin() ; it != node_t->TRs_.end() ; ++it)
	{
		std::cout << "triangle:" << std::endl;
		it->print();
	}*/
}