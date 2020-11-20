#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<iostream>
float fxn1(float);
float absol(float);
float bisection(float,float);
float reg_falsi(float, float);
int main(){
	int a,b;
	std::cout<<"Enter initial guesses x1 and x2:";
	std::cin>>a>>b;
	std::cout<<bisection(a,b)<<"\n";
	std::cout<<reg_falsi(a,b);
}

float fxn1(float a){
	return (a*a*a-2*a-5);
}

float absol(float x)
{ return (x>0?x:(-1)*x);
}

float bisection(float x1 , float x2)
{float xo,e,xo1;
	xo=(x1+x2)/2;
	if ((fxn1(x1)*fxn1(x2))>0)
		return 0;
	if (fxn1(xo)==0)
		return xo;
	
	
	do{
	xo1=xo;	
	if ((fxn1(xo)*fxn1(x1))<0)
	{	x2=xo;
		}
	else
	{x1=xo;
		}
	xo=(x1+x2)/2;
	
	}while(absol((xo1-xo))>=0.00001);
	return xo;
}

float reg_falsi(float x1, float x2)
{	float xo,e,xo1,h;
		xo=x1-(x2-x1)*fxn1(x1)/(fxn1(x2)-fxn1(x1));
	if ((fxn1(x1)*fxn1(x2))>0)
		return 0;
	if (fxn1(xo)==0)
		return xo;
	
	do{
	xo1=xo;	
	
	if ((fxn1(xo)*fxn1(x1))<0)
	{	x2=xo;
		}
	else
	{x1=xo;
		}
	xo=(x1+x2)/2;
	h= xo1-xo;
	
	}while(absol((xo1-xo))>=0.00001);
	return xo;
}
	

