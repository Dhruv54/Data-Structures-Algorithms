#include<iostream>

using namespace std;

struct stack
{
    int size;
    int top;
    int *arr;
};

void stackTraversal(struct stack *s)
{
    for (int i = 0; i <= s->top; i++)
    {
        cout<<s->arr[i]<<" ";
    }
    cout<<endl;
}

int isEmpty(struct stack *s)
{
    if (s->top==-1)
    {
        cout<<"Stack is Empty"<<endl;
        return -1;
    }
    return 0;
}

int isFull(struct stack *s)
{
    if (s->top== s->size-1)
    {
        cout<<"Stack is Full"<<endl;
        return 1;
    }
    return 0;
}

void push(struct stack *s,int element)
{
    if(isFull(s) == 1)
    {
        return;
    }
    else
    {
        s->top++;
        s->arr[s->top]=element;
    }
}

void pop(struct stack *s)
{
    if(isEmpty(s) == -1)
    {
        return;
    }
    else
    {
        s->top--;
    }
}

int main()
{
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->size=10;
    s->top=-1;
    s->arr=(int *)malloc(s->size*sizeof(int));

    // isEmpty(s);
    // s->top=s->size-1;
    // isFull(s);

    // push(s,10);
    // push(s,20);
    // pop(s);
    // pop(s);
    stackTraversal(s);

    return 0;
}