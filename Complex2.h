#pragma once

namespace fractals {

using namespace std;

	public class Complex {

		public Complex(double xe,double ye){this->x=xe;this->y=ye}
		public Complex(const Complex &com){this->x=com->x;this->y=com->y;}
	private:
		double x,y;





	public:

		//comp+comp
		Complex operator+(const Complex &com2) const {
			return Complex (this->x+com2->x,this->y+com2->y);
		}
		//comp+real
		Complex operator+(double d) const {
			return Complex (this->x+d,this->y);
		}
		//comp-comp
		Complex operator-(const Complex &com2) const {
			return Complex (this->x-com2->x,this->y-com2->y);
		}
		//comp-real
		Complex operator-(double d) const {
			return Complex (this->x-d,this->y);
		}
		//comp*comp
		Complex operator*(const Complex &com2) const {
			return Complex ((this->x*com2->x)-(this->y*com2->y),(this->x*com2->y)+(this->y*com2->x));
		}
		//comp*real
		Complex operator*( double d) const {
			return Complex (this->x*d,this->y*d);
		}
		//comp/comp
		Complex operator/(const Complex &com2) const ;
		//comp/real
		Complex operator/(double d) const {
			return Complex (this->x/d,this->y/d);
		}
		//comp^real
		Complex operator%(double d) const ;


	}
}

	