import math

x=[10,20,30,40,50]
y=[0.1736,0.3420,0.5,0.6428,0.7660]

def create_diff_table(x,y): #create a difference table for two sets of related data
    temp=len(x)-1
    delys=[[] for i in range(temp)]
    delys.insert(0,y)
    for i in range(0,temp):
        for j in range(0,temp-i):
            delys[i+1].append(delys[i][j+1]-delys[i][j])
    return delys

def display_diff_table(table_array): # display the difference table
    a=len(x)
    for i in range(0,len(x)):
        print(x[i],end="\t")
        for j in range(0,a):
            print(table_array[j][i],end="\t")
        a=a-1
        print(end="\n")

def find_xo(x,x_input): #a function that returns xo for an input x
    temp_list=[]
    for value in x:
        if (x_input >= value):
            temp_list.append(x_input-value)
    idx= temp_list.index(min(temp_list))
    return x[idx]

def forward_interpolation(diff_table,x):
    x_input=25
    xo= find_xo(x,x_input)
    h=x[1]-x[0]
    p = (x_input-xo)/h
    idx= x.index(xo)
    fxn_value = diff_table[0][idx]
    for i in range(1,(len(x)-idx)):
        term=p
        for j in range(1,i):
            term= term * (term-j)
        fxn_value+= ((term/math.factorial(i))*diff_table[i][idx])
    print(fxn_value)


if __name__=='__main__':
    if(len(x)!=len(y)):
        print("invalid data set.\nThere should be ONE y value corresponding to ONE x value.")
    else:
        created_diff_table=create_diff_table(x,y)
        display_diff_table(created_diff_table)
        #print(created_diff_table)
        forward_interpolation(created_diff_table,x)
