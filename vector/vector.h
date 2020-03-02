#include <iostream>
#include "dot.h"
#include <math.h>
#include <iomanip>

class Vector
{
public:
	Vector(const Dot & start, const Dot & end):start_(start), end_(end){
		vector_length_ = sqrt(pow((start_.get_x() - end_.get_x()),2) + pow((start_.get_y() - end_.get_y()),2) + pow((start_.get_z()- end_.get_z()),2));
	};
	Vector operator+(Vector & B){
		return Vector(start_ + B.start_, end_ + B.end_);
	}
	Vector operator-(Vector &B){
		Dot new_start(start_ - B.start_);
		Dot new_end(end_ - B.end_);
		return Vector(new_start, new_end);
	}
	float dotproduct(Vector &B, float angle_rad){
		return vector_length_ * B.vector_length_ * cos(pi * angle_rad / 180);
	}

	 friend std::ostream & operator<<(std::ostream &a, const Vector &A){
		a<<"Vector coords: "<<std::endl
		<<std::setw(15)<<"start point -> "
		<<std::setw(2)<<A.start_.get_x()
		<<std::setw(2)<<A.start_.get_y()
		<<std::setw(2)<<A.start_.get_z()
		<<std::endl
		<<std::setw(15)<<"end point -> "
		<<std::setw(2)<<A.end_.get_x()
		<<std::setw(2)<<A.end_.get_y()
		<<std::setw(2)<<A.end_.get_y()
		<<std::endl
		<<"Vector length: "<<A.vector_length_<<std::endl;
		return a;
	}
	~Vector(){};
private:
	const float pi = 3.1415;
	float vector_length_;
	Dot start_;
	Dot end_;
};