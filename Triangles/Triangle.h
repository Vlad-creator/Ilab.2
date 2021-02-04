#include <float.h>
#include <math.h>
#include <iostream>
#include <vector>

struct point
{
	float x_ , y_ , z_;

	void print() const;
	point& operator=(const point& p);
	point(float x , float y , float z): x_(x) , y_(y) , z_(z) {};
	point(): x_(0) , y_(0) , z_(0) {};
};

float dot_product(point& p1 , point& p2)
{
	float res = p1.x_ * p2.x_ + p1.y_ * p2.y_ + p1.z_ * p2.z_;
	return res;
}

point vec_product(point& p1 , point& p2)
{
	point res;
	res.x_ = p1.y_ * p2.z_ - p1.z_ * p2.y_;
	res.y_ = p1.z_ * p2.x_ - p1.x_ * p2.z_;
	res.z_ = p1.x_ * p2.y_ - p1.y_ * p2.x_;
	return res;
}

point make_vec(point& p1 , point& p2)
{
	point vec;
	vec.x_ = p2.x_ - p1.x_;
	vec.y_ = p2.y_ - p1.y_;
	vec.z_ = p2.z_ - p1.z_;
	return vec;
}

point& point::operator=(const point& p)
{
	x_ = p.x_;
	y_ = p.y_;
	z_ = p.z_;
	return *this;
}

void point::print() const
{
	std::cout << "point (" << x_ << ' ' << y_ << ' ' << z_ << ')' << std::endl;
}

struct triangle
{
	point p1_ , p2_ , p3_;

	void print() const;
	point find_norm();
	triangle(point p1 , point p2 , point p3);
};

triangle::triangle(point p1 , point p2 , point p3)
{
	p1_ = p1;
	p2_ = p2;
	p3_ = p3;
}

point triangle::find_norm()
{
	point vec1 = make_vec(p1_ , p2_);
	point vec2 = make_vec(p1_ , p3_);
	point normal = vec_product(vec1 , vec2);
	return normal;
}

void triangle::print() const
{
	std::cout << "p1 - ";
	p1_.print();
	std::cout << "p2 - ";
	p2_.print();
	std::cout << "p3 - ";
	p3_.print();
}

std::istream& operator>>(std::istream& stream, point& a) {
	stream >> a.x_ >> a.y_ >> a.z_;
	return stream;
}

bool proect_cross(triangle t1 , triangle t2 , point line)
{
	int counter = 0;
	std::vector<float> lines_t1 = {};
	std::vector<float> lines_t2 = {};
	lines_t1.push_back(dot_product(t1.p1_ , line));
	lines_t1.push_back(dot_product(t1.p2_ , line));
	lines_t1.push_back(dot_product(t1.p3_ , line));
	lines_t2.push_back(dot_product(t2.p1_ , line));
	lines_t2.push_back(dot_product(t2.p2_ , line));
	lines_t2.push_back(dot_product(t2.p3_ , line));

	for (int i = 0 ; i < 3 ; ++i)
		for (int j = 0 ; j < 3 ; ++j)
			if (lines_t1[i] < lines_t2[j])
				counter++;
	if (counter == 9)
		return false;

	counter = 0;

	for (int i = 0 ; i < 3 ; ++i)
		for (int j = 0 ; j < 3 ; ++j)
			if (lines_t1[i] > lines_t2[j])
				counter++;
	if (counter == 9)
		return false;

	return true;
}

bool is_cross(triangle t1 , triangle t2)
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

	point norm_t1 = t1.find_norm();
	res = proect_cross(t1 , t2 , norm_t1);
		if (res == false)
			return res;

	point norm_t2 = t2.find_norm();
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
		};
	return res;
}



