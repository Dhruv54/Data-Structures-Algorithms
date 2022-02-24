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
int partition(int A[], int low, int high)
{
    int i = low + 1;
    int pivot = A[low];
    int j = high;
    int tmp;
    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            tmp=A[i];
            A[i]=A[j];
            A[j]=tmp;
            // swap(A[i], A[j]);
        }
    } while (i < j);
    // swap(A[low], A[j]);
    tmp=A[low];
    A[low]=A[j];
    A[j]=tmp;
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
    int A[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = 10;
    printArray(A, n);
    cout << "Quick Sort" << endl;
    quickSort(A, 0, n-1);
    printArray(A, n);
    return 0;
}