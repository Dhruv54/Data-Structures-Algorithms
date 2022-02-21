#include<iostream>
using namespace std;

struct CircularQueue
{
    int size;
    int f;
    int r;
    int *arr; 
};

void printCircularQueue(struct CircularQueue *q)
{
    cout<<"hello"<<endl;
    int f=(q->f+1)%q->size;
    int r=(q->r+1)%q->size;
    while(f!=r)
    {
        cout<<q->arr[f]<<" ";
        f=(f+1)%q->size;
    }
    cout<<endl;
}

int isFull(struct CircularQueue *q)
{
    if((q->r+1)%q->size==q->f)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct CircularQueue *q)
{
    if(q->f==q->r)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct CircularQueue *q,int val)
{
    if(isFull(q))
    {
        cout<<"CircularQueue is  full!!!"<<endl;
    }
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
    }
}

int dequeue(struct CircularQueue *q)
{
    int a=-1;
    if(isEmpty(q))
    {
        cout<<"CircularQueue is  Empty!!!"<<endl;
    }
    else{
        q->f=(q->f+1)%q->size;
        a=q->arr[q->f];
    }
    return a;
}

int main()
{
    struct CircularQueue *q=(struct CircularQueue *)malloc(sizeof(struct CircularQueue));
    q->size=5;
    q->f=q->r=0;
    q->arr=(int *)malloc(q->size*sizeof(int));

    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    // enqueue(q,40);
    // enqueue(q,50);
    // enqueue(q,60);
    printCircularQueue(q);
    cout<<dequeue(q)<<endl;
    cout<<dequeue(q)<<endl;
    printCircularQueue(q);
    enqueue(q,40);
    enqueue(q,50);
    enqueue(q,60);
    printCircularQueue(q);
    // cout<<dequeue(q)<<endl;
    // cout<<dequeue(q)<<endl;
    // cout<<dequeue(q)<<endl;
    // cout<<dequeue(q)<<endl;

    return 0;
}