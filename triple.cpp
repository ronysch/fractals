#include "StdAfx.h"
#include "Drawer.h"
#include "Form1.h"
#include "Complex.h"
using namespace fractals;
void fractals::triple::drawMandel(int x){
	int count=0;
	Complex z=Complex(0,0),c=Complex(0,0);
	for(int i=0;i<400;i++)
		for(int k=x-1;k<480;k+=8){
			z=Complex(form->xCoordinate+k*Form1->zoom,Form1->yCoordinate-i*Form1->zoom);
			c=Complex(z);
			count=0;
			while(count<128 && c++<2){
				c=c%2+z;
				count++;
			
			}
			count--;
			count=count*2;
			count=255-count;
			Form1->mBmp->setPixel(k,i,Color::FromArgb(count/2,count,count/3))
		}
}
