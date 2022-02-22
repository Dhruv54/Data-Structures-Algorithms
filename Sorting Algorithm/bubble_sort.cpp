#include<iostream>
using namespace std;

void printArray(int *A,int n)
{
    cout<<"Array Elemets"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }cout<<endl;
}

void bubbleSort(int *A,int n)
{
    int tmp;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if(A[j]>A[j+1])
            {
                tmp=A[j];
                A[j]=A[j+1];
                A[j+1]=tmp;
            }
        }
    }
}
int main()
{
    int A[]={10,9,8,7,6,5,4,3,2,1};
    int n=10;
    printArray(A,n);
    cout<<"Bubble Sort"<<endl;
    bubbleSort(A,n);
    printArray(A,n);
    return 0;
}