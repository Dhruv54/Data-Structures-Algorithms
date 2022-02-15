#include <iostream>

using namespace std;

int comparison=0;
//  Print Array element 
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

//  partition the array and return partition Index..
int partition(int A[], int low, int high)
{
    //  Rndomize Quick Sort..
    int random = low + rand()%(high-low);
    int tmp;

    //  swap A[low] with A[random] bcz of pivot element start with low position...
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
        // printArray(A, 10);
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

    for (int i = 0; i < size; i++)
    {
        A[i]=i+1;
    }
    // printArray(A, size);
    quickSort(A, 0, size - 1); //   Alos a Randomize Quick Sort..
    // printArray(A, size);
    cout<<"Sorted  Input  Comparisons : "<<comparison<<endl;
    comparison=0;

    int count=size;
    for (int i = 0; i<size; i++)
    {
        A[i]=count;
        count--;
    }
    // printArray(A, size);
    quickSort(A, 0, size - 1); //   Alos a Randomize Quick Sort..
    // printArray(A, size);
    cout<<"Reversed Order Comparisons : "<<comparison<<endl;
    comparison=0;

    for (int i = 0; i<size; i++)
    {
        A[i]=1+rand()%size;
    }
    // printArray(A, size);
    quickSort(A, 0, size - 1); //   Alos a Randomize Quick Sort..
    // printArray(A, size);
    cout<<"Randomly Input Comparisons : "<<comparison<<endl;
    comparison=0;

    return 0;
}