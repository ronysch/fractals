#pragma once
#include <math.h>
namespace fractals {

using namespace std;
using namespace System;
	public  class Complex {

	public: Complex(double xe,double ye){x=xe;y=ye;}
	public: Complex(const Complex &com){x=com.x;y=com.y;}
	private:
		double x,y;





	public:
		//getters
		double getX() const {return x;}
		double getY() const {return y;}
		//setters
		double setX(double d){x=d;}
		double setY(double d){y=d;}
		//comp+comp
		fractals::Complex operator+(const Complex &com2) const  {
			return Complex (x+com2.x,y+com2.y);
		}
		//comp+real
		Complex operator+(double d) const {
			return Complex (x+d,y);
		}
		//comp-comp
		Complex operator-(const Complex &com2) const {
			return Complex (x-com2.x,y-com2.y);
		}
		//comp-real
		Complex operator-(double d) const {
			return Complex (x-d,y);
		}
		//comp*comp
		Complex operator*(const Complex &com2) const {
			return Complex ((x*com2.x)-(y*com2.y),(x*com2.y)+(y*com2.x));
		}
		//comp*real
		Complex operator*(double d) const {
			return Complex (x*d,y*d);
		}
		//comp/comp
		Complex operator/(const Complex &com2) const ;
		//comp/real
		Complex operator/(double d) const {
			return Complex (x/d,y/d);
		}
		//comp^real
		Complex operator%(double d) const ;
		//postfix abs operator
		double operator++(int) const {
			return sqrt(x*x+y*y);
		}
		operator String^() {
			return System::Convert::ToString(x)+","+System::Convert::ToString(y)+"i";
		}

	}
;}

	