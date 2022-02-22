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

void selectionSort(int *A,int n)
{
    int indexOfMin,tmp;
    for (int i = 0; i < n-1; i++)
    {
        indexOfMin=i;
        for (int j = i+1; j < n; j++)
        {
            if(A[j]<A[indexOfMin])
            {
                indexOfMin=j;
            }
        }
        tmp=A[i];
        A[i]=A[indexOfMin];
        A[indexOfMin]=tmp;
    }
}
int main()
{
    int A[]={12,10,1,2,3,44};
    int n=6;
    printArray(A,n);
    selectionSort(A,n);
    printArray(A,n);
    return 0;
}