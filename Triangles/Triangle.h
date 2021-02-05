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
	point find_norm_tr();
	point find_norm_ln(point line);
	triangle(point p1 , point p2 , point p3);
};

triangle::triangle(point p1 , point p2 , point p3)
{
	p1_ = p1;
	p2_ = p2;
	p3_ = p3;
}

point triangle::find_norm_tr()
{
	point vec1 = make_vec(p1_ , p2_);
	point vec2 = make_vec(p1_ , p3_);
	point norm_tr = vec_product(vec1 , vec2);
	return norm_tr;
}

point triangle::find_norm_ln(point line)
{
	point norm_tr = find_norm_tr();
	point norm_ln = vec_product(norm_tr , line);
	return norm_ln;
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



