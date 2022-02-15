#include <iostream>

using namespace std;
int comparison=0;

int partition(int A[], int low, int high)
{
    int random = low + rand()%(high-low);
    int tmp;

    tmp=A[random];
    A[random]=A[low];
    A[low]=tmp;

    int pivot = A[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (A[i] <= pivot)
        {
            comparison++;
            i++;
        }
        while (A[j] > pivot)
        {
            comparison++;
            j--;
        }
        if (i < j)
        {
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    } while (i < j);

    tmp = A[low];
    A[low] = A[j];
    A[j] = tmp;

    return j;
}

void quickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);
        quickSort(A, partitionIndex + 1, high);
    }
}

int main()
{
    int size;
    cout<<"Enter the size of An Array : ";
    cin>>size;
    int A[size];
    //  Sorted  Input Array..
    for (int i = 0; i < size; i++)
    {
        A[i]=i+1;
    }
    quickSort(A, 0, size - 1);
    cout<<"Sorted  Input  Comparisons : "<<comparison<<endl;
    comparison=0;
    //  Reversed order Input Array..
    int count=size;
    for (int i = 0; i<size; i++)
    {
        A[i]=count;
        count--;
    }
    quickSort(A, 0, size - 1);
    cout<<"Reversed Order Comparisons : "<<comparison<<endl;
    comparison=0;
    //  Random elements Array..
    for (int i = 0; i<size; i++)
    {
        A[i]=1+rand()%size;
    }
    quickSort(A, 0, size - 1);
    cout<<"Randomly Input Comparisons : "<<comparison<<endl;
    comparison=0;

    return 0;
}