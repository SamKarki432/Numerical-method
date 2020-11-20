#include<iostream>
#include<math.h>
#include<stdio.h>
#include<conio.h>
void display_matrix(float[10][10],int);
void calculate_values(float[10][10],int);

int main()
{ float arr[10][10],temp;  int i,j,k,x,l,n;
	std::cout<<"enter the number of unknown variables:";
	std::cin>>n;
	std::cout<<"\nenter the elments of augmented matrix row by row:\n";
	for(i=0;i<n;i++)
	{	std::cout<<"row"<<i+1<<":";
		for(j=0;j<n+1;j++)
			{ std::cin>>arr[i][j];
			}
	}
	std::cout<<"\ninput matrix:\n";
	display_matrix(arr,n);std::cout<<"\n\n";

	 for(j=0; j<n+1; j++) //converting the input matrix into upper tiangular form 
    {
        for(i=0; i<n; i++)
        {
            if(i>j)
            {
                temp=arr[i][j]/arr[j][j];
                for(k=0; k<n+1; k++)
                {
                    arr[i][k]=arr[i][k]-temp*arr[j][k];
                }
            }
        }
    }
        calculate_values(arr,n);
}

void display_matrix(float arr[10][10],int n) // displays the matrix
{
	int i,j;
	for(i=0;i<n;i++)
	{	for(j=0;j<n+1;j++)
		{if (j==n)
			std::cout<<":"<<arr[i][j]<<" ";
		 else
		 	std::cout<<arr[i][j]<<" ";
		}
		std::cout<<"\n";
	}
}

void calculate_values(float arr[10][10],int n) // calculates the values of variables and stores them serially in an array and displays them
{ 	float x1,x2,x3,ans[n],temp;int i,j;
	
	for(i=0;i<n;i++) //initializing array containing answers.
	{ ans[i]=0;
	}
	
	for(i=n-1;i>=0;i--)
	{ temp=arr[i][n];
		for(j=n-1;j>=0;j--)
		{	temp-=(arr[i][j]*ans[j]);
		}
	ans[i]=temp/arr[i][i];
	}
	
	for(i=0;i<n;i++) // displaying values of unknown variables from the answer array
	{ std::cout<<"x"<<i+1<<":"<<ans[i]<<"\t";
	}
}
