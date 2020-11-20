#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<iostream>
float fxn(float);
float derfxn(float);
float nr(float);

float fxn(float a)
{ return(a*sin(a)+cos(a));
}

float derfxn(float a)
{ return(a*cos(a));
}

float nr(float x1)
{ float xo,xo1;
	int count=0;
	xo= x1 - fxn(x1)/derfxn(x1);
	if (fxn(xo)==0)
		return xo;
	
	do{
		xo1=xo;
		x1=xo;
		xo= x1 - fxn(x1)/derfxn(x1);
		count++;
	}while((fabs(xo1-xo)>=0.0001) && count<12);
	return xo;
}

int main(){
	float a;
	std::cout<<"Enter initial guess:";
	std::cin>>a;
	std::cout<<"output using newton raphson method:"<<nr(a);
}
