#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<math.h>
float x1(float,float,float);
float x2(float,float,float);
float x3(float,float,float);
float x4(float,float,float);
void jacobi(float,float,float,float);
void gauss_seidal(float,float,float,float);

float x1(float x2, float x3, float x4)
{ return((10-2*x2+3*x3+0*x4)/9);
}
float x2(float x1, float x3, float x4)
{ return((15-2*x1+0*x3+2*x4)/8);
}
float x3(float x1, float x2, float x4)
{ return((30-5*x1-2*x4)/11);
}
float x4(float x1, float x2, float x3)
{ return((25-x2-3*x3)/7);
}

void jacobi(float a, float b, float c, float d)
{float e=0.001;
	float a1,b1,c1,d1;
	int count=0;
	a1=a; b1=b; c1=c;d1=d;
	a= x1(b1,c1,d1); b= x2(a1,c1,d1); 
	c= x3(a1,b1,d1); d=x4(a1,b1,c1);
	std::cout<<"jacobi method :: \n\n";
	do{
		count++;
		a1=a; b1=b; c1=c;d1=d;
		a= x1(b1,c1,d1); b= x2(a1,c1,d1); 
		c= x3(a1,b1,d1);d=x4(a1,b1,c1);
		std::cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\n";
	}while(fabs(a1-a)>e && fabs(b1-b)>e && fabs(c1-c)>e && fabs(d1-d)>e && count<12);
	std::cout<<"\nFinal answer using jacobi method:\n";
	std::cout<<"x1:"<<a<<"\t"<<"x2:"<<b<<"\t"<<"x3:"<<c<<"\t"<<"x4:"<<d<<"\n\n\n";
}

void gauss_seidal(float a , float b , float c , float d)
{float e=0.001,a1,b1,c1,d1; 
	int count=0;
	a= x1(b,c,d); b= x2(a,c,d); 
	c= x3(a,b,d);d=x4(a,b,c);
	std::cout<<"gauss-seidal method :: \n\n";
	std::cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\n";
	
	do{
		count++;
		a1=a; b1=b; c1=c;d1=d;
		a= x1(b,c,d); b= x2(a,c,d); 
		c= x3(a,b,d);d=x4(a,b,c);
		std::cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\n";
	}while(fabs(a1-a)>e && fabs(b1-b)>e && fabs(c1-c)>e && fabs(d1-d)>e && count<12);
	
	std::cout<<"\nFinal answer using gauss_seidal:\n";
	std::cout<<"x1:"<<a<<"\t"<<"x2:"<<b<<"\t"<<"x3:"<<c<<"\t"<<"x4:"<<d<<"\n";
}

int main(){
	float a,b,c,d;
	std::cout<<"enter the initial guesses, x1 x2 x3 x4. in that order:\n";
	std::cin>>a>>b>>c>>d;
	jacobi(a,b,c,d);
	gauss_seidal(a,b,c,d);
}
