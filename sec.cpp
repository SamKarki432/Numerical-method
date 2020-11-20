#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<iostream>
float fxn(float);
float seca(float,float);

float fxn(float a)
{ return(a*sin(a)+cos(a));
}

float seca(float x1, float x2)
{ float xo,xo1;
	int count=0;
	xo= x2-(x2-x1)*fxn(x2)/(fxn(x2)-fxn(x1));
	if (fxn(xo)==0)
	return xo;
	
	do{
		xo1=xo;
		x1=x2;
		x2=xo;
		xo= x2-(x2-x1)*fxn(x2)/(fxn(x2)-fxn(x1));
		count++;
	}while((fabs(xo1-xo)>=0.0001) && count<12);
	return xo;
}

int main(){
	float a ,b;
	std::cout<<"Enter intitial guesses:";
	std::cin>>a>>b;
	std::cout<<seca(a,b);
}
