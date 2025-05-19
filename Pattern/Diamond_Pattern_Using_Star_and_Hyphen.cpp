#include <iostream>
using namespace std;
void print(int n)
{
    for(int i=0;i<n;i++)
    {
        int space;
        if(i>n/2)
        {
            space = i-n/2; 
        }
        else
        {
            space =n/2-i;
        }
        
        if(i%2==0)
        {
            //space
            for(int j=0;j<space;j++)
            {
                cout<<" ";
            }
            //star
            for(int j=0;j<n-2*space;j++)
            {
                cout<<"*";
            }
            //space
            for(int j=0;j<space;j++)
            {
                cout<<" ";
            }
            
        }
        else
        {
            //space
            for(int j=0;j<space;j++)
            {
                cout<<" ";
            }
            //star
            for(int j=0;j<n-2*space;j++)
            {
                cout<<"-";
            }
            //space
            for(int j=0;j<space;j++)
            {
                cout<<" ";
            }
        }
        
        cout<<endl;
    }
}
int main() {
    int n=17;
    print(n);
    return 0;
}