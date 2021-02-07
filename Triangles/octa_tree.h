
class octa_tree;
struct region;
struct tree_node;

bool check_point_in_region(point per , region space);

struct region
{
	float edge;
	point center;

	region operator=(const region& rhs);

	float find_edge(std::vector<triangle> TRs_);
	void print();
};

struct tree_node
{
	region space;
	std::vector<triangle> TRs_;
	octa_tree* children[8];
	//int zone;
	//int crosses;

	tree_node();
	void print();
};

class octa_tree
{
		tree_node node_t;

		std::vector<region> make_region();
		std::vector<triangle> sort_triangles(std::vector<region> regions , int zone);
	public:
		octa_tree(std::vector<triangle> TRs) {node_t.TRs_ = TRs;};
		void make_tree(int* count_cross);
};

region region::operator=(const region& rhs)
{
	center = rhs.center;
	edge = rhs.edge;
	return *this;
}

float region::find_edge(std::vector<triangle> TRs_)
{
	float edge = 0;
	float per;
	for (auto it = TRs_.begin() ; it != TRs_.end() ; ++it)
		if (edge < (per = (*it).max_point().get_max()))
			edge = per;
	return edge;
}

void region::print()
{
	std::cout << "edge - " << edge << std::endl;
	std::cout << "center - ";
	center.print();
}

tree_node::tree_node()
{
	for (int i = 0 ; i < 8 ; ++i)
		children[i] = nullptr;
}

std::vector<region> octa_tree::make_region()
{
	region parent = node_t.space;
	std::vector<region> children;
	for (int i = 0 ; i < 8 ; ++i)
	{
		if ((i == 0) || (i == 1) || (i == 2) || (i == 3))
			children[i].center.y_ = children[i].center.y_ + parent.edge / 2;
		else
			children[i].center.y_ = children[i].center.y_ - parent.edge / 2;

		if ((i == 1) || (i == 2) || (i == 5) || (i == 7))
			children[i].center.x_ = children[i].center.x_ + parent.edge / 2;
		else
			children[i].center.x_ = children[i].center.x_ - parent.edge / 2;

		if ((i == 0) || (i == 1) || (i == 4) || (i == 5))
			children[i].center.z_ = children[i].center.z_ + parent.edge / 2;
		else
			children[i].center.z_ = children[i].center.z_ - parent.edge / 2;
	}

	return children;
}

std::vector<triangle> octa_tree::sort_triangles(std::vector<region> regions , int zone)
{
	std::vector<triangle> child;
	region space = regions[zone];
	for (auto it = node_t.TRs_.begin() ; it != node_t.TRs_.end() ; ++it)
	{
		if ((check_point_in_region((*it).p1_ , space)) && 
		    (check_point_in_region((*it).p2_ , space)) && 
		    (check_point_in_region((*it).p3_ , space)))
		    child.push_back(*it);
	}

	return child;
}

void octa_tree::make_tree(int* count_cross)
{
	if ((node_t.TRs_.size() >= 3) && (node_t.space.edge > 3))
	{
		std::vector<region> regions = make_region();
		for (int i = 0 ; i < 8 ; i++)
		{
			std::vector<triangle> TRs = sort_triangles(regions , i);
			octa_tree node(TRs);
			node_t.children[i] = &node;
			(node_t.children[i])->node_t.space = regions[i];
			(node_t.children[i])->make_tree(count_cross);
		}
	}
	else
	{
		for (auto it_1 = node_t.TRs_.begin() ; it_1 != node_t.TRs_.end() ; ++it_1)
			for (auto it_2 = node_t.TRs_.begin() ; it_2 != node_t.TRs_.end() ; ++it_2)
				if ((it_1 != it_2) && (is_cross((*it_1) , (*it_2))))
				{
					(*count_cross)++;
					(*it_2).print();
					(*it_1).print();	
				}
	}
}

bool check_point_in_region(point per , region space)
{
	point center = space.center;
	float edge = space.edge;
	if ((per.x_ > center.x_ + edge / 2) || (per.x_ < center.x_ - edge / 2))
		return false;
	else
		if ((per.y_ > center.y_ + edge / 2) || (per.y_ < center.y_ - edge / 2))
			return false;
		else
			if ((per.z_ > center.z_ + edge / 2) || (per.z_ < center.z_ - edge / 2))
				return false;
			else
				return true;
}
