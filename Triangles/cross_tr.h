
bool proect_cross(triangle& t1 , triangle& t2 , point& line)
{
	int counter = 0;
	std::vector<float> lines_t1 = {};
	std::vector<float> lines_t2 = {};
	//line.print();
	lines_t1.push_back(dot_product(t1.p1_ , line));
	lines_t1.push_back(dot_product(t1.p2_ , line));
	lines_t1.push_back(dot_product(t1.p3_ , line));
	lines_t2.push_back(dot_product(t2.p1_ , line));
	lines_t2.push_back(dot_product(t2.p2_ , line));
	lines_t2.push_back(dot_product(t2.p3_ , line));

	for (int i = 0 ; i < 3 ; ++i)
		for (int j = 0 ; j < 3 ; ++j)
			if (lines_t1[i] < lines_t2[j])
			{
				//std::cout << lines_t1[i] << ' ' << lines_t2[j] << std::endl;
				counter++;
			}
	if (counter == 9)
		return false;

	counter = 0;

	for (int i = 0 ; i < 3 ; ++i)
		for (int j = 0 ; j < 3 ; ++j)
			if (lines_t1[i] > lines_t2[j])
				counter++;
	//std::cout << counter << std::endl;
	if (counter == 9)
		return false;

	return true;
}

bool is_pair_flat(triangle& t1 , triangle& t2)
{
	point zero;
	if ((t1.p1_ == zero) && (t2.p1_ == zero))
		return true;
	if ((t1.p2_ == zero) && (t2.p2_ == zero))
		return true;
	if ((t1.p3_ == zero) && (t2.p3_ == zero))
		return true;
	return false;
}

bool is_cross(triangle& t1 , triangle& t2)
{
	bool res = true;
	std::vector<point> lines_t1 = {};
	std::vector<point> lines_t2 = {};
	lines_t1.push_back(make_vec(t1.p1_ , t1.p2_));
	lines_t1.push_back(make_vec(t1.p1_ , t1.p3_));
	lines_t1.push_back(make_vec(t1.p2_ , t1.p3_));
	lines_t2.push_back(make_vec(t2.p1_ , t2.p2_));
	lines_t2.push_back(make_vec(t2.p1_ , t2.p3_));
	lines_t2.push_back(make_vec(t2.p2_ , t2.p3_));

	if (is_pair_flat(t1 , t2))
		for (int i = 0 ; i < 3 ; ++i)
		{
			point line_1 = t1.find_norm_ln(lines_t1[i]);
			res = proect_cross(t1 , t2 , line_1);
				if (res == false)
					return res;
			point line_2 = t2.find_norm_ln(lines_t2[i]);
			res = proect_cross(t1 , t2 , line_2);
				if (res == false)
					return res;
		}
		else
		{
			point norm_t1 = t1.find_norm_tr();
			res = proect_cross(t1 , t2 , norm_t1);
				if (res == false)
					return res;

			point norm_t2 = t2.find_norm_tr();
			res = proect_cross(t1 , t2 , norm_t2);
				if (res == false)
					return res;

			for (int i = 0 ; i < 3; ++i)
				for (int j = 0 ; j < 3 ; ++j)
				{
					point line = vec_product(lines_t1[i] , lines_t2[j]);
					res = proect_cross(t1 , t2 , line);
					if (res == false)
						return res;
				}
		}

	return res;
}