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

void insertionSort(int *A,int n)
{
    int key,j,tmp;
    for (int i = 1; i <= n-1; i++)
    {
        key=i;
        j=0;
        while (j!=n)
        {
            if(A[key]<A[j])
            {
                cout<<"Swap ";
                tmp=A[key];
                A[key]=A[j];
                A[j]=tmp;
            }
            j++;
        }
    }
}
int main()
{
    int A[]={5,1,3,2,1};
    int n=5;
    printArray(A,n);
    cout<<"Insertion Sort"<<endl;
    insertionSort(A,n);
    printArray(A,n);
    return 0;
}