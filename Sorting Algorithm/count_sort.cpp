#include <iostream>
using namespace std;

void printArray(int *A, int n)
{
    cout << "Array Elemets" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
int findMax(int A[],int n)
{
    int max=0;
    for (int i=0; i<n; i++)
    {
        if(A[i]>max)
        {
            max=A[i];
        }
    }
    return max;
}
void CountSort(int A[],int n)
{
    int max=findMax(A,n);
    int *countArr=(int *)malloc(max*sizeof(int));
    for (int i = 0; i <=max; i++)
    {
        countArr[i]=0;
    }
    for (int i = 0; i < n; i++)
    {
        countArr[A[i]]=countArr[A[i]]+1;
    }
    int i=0,j=0;
    while (i<=max)
    {
        if(countArr[i]>0)
        {
            A[j]=i;
            countArr[i]--;
            j++;
        }else{
            i++;
        }
    }
}
int main()
{
    int A[] = {4,3,6,20};
    int n = 4;
    printArray(A, n);
    cout << "Count Sort" << endl;
    CountSort(A, n);
    printArray(A, n);
    return 0;
}