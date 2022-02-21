#include<iostream>
using namespace std;

struct Queue
{
    int size;
    int f;
    int r;
    int *arr; 
};

void printQueue(struct Queue *q)
{
    int i=0;
    for (int i = 0; i <= q->size-1; i++)
    {
        cout<<q->arr[i]<<" ";
    }
    cout<<endl;
}

int isFull(struct Queue *q)
{
    if(q->r==q->size-1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue *q)
{
    if(q->f==q->r)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct Queue *q,int val)
{
    if(isFull(q))
    {
        cout<<"Queue is  full!!!"<<endl;
    }
    else{
        q->r++;
        q->arr[q->r]=val;
    }
}

int dequeue(struct Queue *q)
{
    int a;
    if(isEmpty(q))
    {
        cout<<"Queue is  Empty!!!"<<endl;
    }
    else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}

int main()
{
    struct Queue *q=(struct Queue *)malloc(sizeof(struct Queue));
    q->size=5;
    q->f=q->r=-1;
    q->arr=(int *)malloc(q->size*sizeof(int));

    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    enqueue(q,50);
    enqueue(q,60);
    printQueue(q);
    cout<<dequeue(q)<<endl;
    cout<<dequeue(q)<<endl;
    cout<<dequeue(q)<<endl;
    cout<<dequeue(q)<<endl;
    cout<<dequeue(q)<<endl;
    cout<<dequeue(q)<<endl;

    return 0;
}