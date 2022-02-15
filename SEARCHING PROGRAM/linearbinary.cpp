#include<iostream>

using namespace std;

int linearSearch(int arr[],int element,int size)
{
    for (int i = 0; i < size; i++)
        if(arr[i]==element)
            return i;
    return -1;
}
int binarySearch(int arr[],int element,int size)
{
    int low=0,mid,high=size-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==element)
            return mid;
        if(element<arr[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}

int main()
{
    //  linear search for un-ordered arrray.. 
    // int arr[]={2,56,821,680,234,59,576,24,98,70,435,2341};
    // int size = sizeof(arr)/sizeof(int);
    // int element = 2341;
    // int searchIndex = linearSearch(arr,element,size);

    //  Binary search for sorted(ordered) arrray.. 
    int arr[]={2,6,21,68,74,89,96,124,198,200,435,2341};
    int size = sizeof(arr)/sizeof(int);
    int element = 21;
    int searchIndex = binarySearch(arr,element,size);

    cout<<"element : "<<element<<" is found at index no :"<<searchIndex<<endl;
    return 0;
}
