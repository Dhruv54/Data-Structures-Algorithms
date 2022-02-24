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
void  mergeArray(int A[],int low,int mid,int high)
{
    int i=low,j=mid+1,k=low,B[10];
    while (i<=mid && j<=high)
    {
        if(A[i]<A[j])
        {
            B[k]=A[i];
            k++;
            i++;
        }else{
            B[k]=A[j];
            k++;
            j++;
        }
    }
    while (i<=mid)
    {
        B[k]=A[i];
        i++;
        k++;
    }
    while (j<=high)
    {
        B[k]=A[j];
        j++;
        k++;
    }
    for (int i = low; i <=high; i++)
    {
        A[i]=B[i];
    }
}

void mergeSort(int A[], int low, int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeSort(A,low,mid);
        mergeSort(A,mid+1,high);
        mergeArray(A,low,mid,high);
    }
}

int main()
{
    int A[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = 10;
    printArray(A, n);
    cout << "Merge Sort" << endl;
    mergeSort(A, 0, n-1);
    printArray(A, n);
    return 0;
}