
#include "stdafx.h"
#include "Complex.h"
#include <math.h>
using namespace std;

 fractals::Complex fractals::Complex::operator/(const Complex &com2)const{
	Complex conjugate=Complex(com2.x,-(com2.y));
	Complex div=Complex(conjugate*(*this));
	return div/((conjugate.x*conjugate.x)+(conjugate.y*conjugate.y));
}

fractals::Complex fractals::Complex::operator%(double d) const {
	if(d>=4.0){
	double abs=sqrt(x*x+y*y),alpha=atan(y/x);
	return fractals::Complex(cos(d*alpha),sin(d*alpha))*(pow(abs,d));
	}
	else{
	Complex com2=Complex(1,0),com3=Complex(*this);
	for(int i=0;i<0+d;i++)
	com2=com2*com3;

		return com2;
	}
}
