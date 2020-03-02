#pragma once
class Dot
{
public:
	Dot(float x, float y, float z):x_(x), y_(y), z_(z){};
	Dot operator+(Dot & B){
		return Dot(x_ + B.x_, y_ + B.y_, z_ + B.z_);
	}
	Dot operator-(Dot & B){
		return Dot(x_ - B.x_, y_ - B.y_, z_ - B.z_);
	}
	~Dot(){};
	const float get_x() const{
		return x_;
	}
	const float get_y() const{
		return y_;
	}
	const float get_z() const{
		return z_;
	}
	private:
	float x_, y_, z_;
};