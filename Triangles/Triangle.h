struct point
{
	float x_ , y_ , z_;

	void print() const;
	point& operator=(const point& p);
	float get_max();
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

float point::get_max()
{
	if ((x_ >= y_) && (x_ >= z_))
		return x_;

	if ((y_ >= x_) && (y_ >= z_))
		return y_;

	if ((z_ >= y_) && (z_ >= x_))
		return z_;

	return -1;
}

struct triangle
{
	point p1_ , p2_ , p3_;

	void print() const;
	point find_norm_tr();
	point find_norm_ln(point line);
	point max_point();
	triangle(point p1 , point p2 , point p3);
	triangle();
};

triangle::triangle()
{
	point p1 , p2 , p3;
	p1_ = p1;
	p2_ = p2;
	p3_ = p3;
}

triangle::triangle(point p1 , point p2 , point p3)
{
	p1_ = p1;
	p2_ = p2;
	p3_ = p3;
}

point triangle::max_point()
{
	point max;
	if ((abs(p1_.x_) >= abs(p2_.x_)) && (abs(p1_.x_) >= abs(p3_.x_)))
		max.x_ = abs(p1_.x_);
	else
		if ((abs(p2_.x_) >= abs(p1_.x_)) && (abs(p2_.x_) >= abs(p3_.x_)))
			max.x_ = abs(p2_.x_);
		else
			max.x_ = abs(p3_.x_);


	if ((abs(p1_.y_) >= abs(p2_.y_)) && (abs(p1_.y_) >= abs(p3_.y_)))
		max.y_ = abs(p1_.y_);
	else
		if ((abs(p2_.y_) >= abs(p1_.y_)) && (abs(p2_.y_) >= abs(p3_.y_)))
			max.y_ = abs(p2_.y_);
		else
			max.y_ = abs(p3_.y_);


	if ((abs(p1_.z_) >= abs(p2_.z_)) && (abs(p1_.z_) >= abs(p3_.z_)))
		max.z_ = abs(p1_.z_);
	else
		if ((abs(p2_.z_) >= abs(p1_.z_)) && (abs(p2_.z_) >= abs(p3_.z_)))
			max.z_ = abs(p2_.z_);
		else
			max.z_ = abs(p3_.z_);
	return max;
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

std::istream& operator>>(std::istream& stream, triangle& a) {
	stream >> a.p1_ >> a.p2_ >> a.p3_;
	return stream;
}




