#include<iostream>
#include<string.h>
// #include<csstring.h>
using namespace std;

struct stack 
{
    int size;
    int top;
    char *arr;
};

int isFull(struct stack *s)
{
    if (s->top== s->size-1)
    {
        cout<<"Stack is Full"<<endl;
        return 1;
    }
    return 0;
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

int pop(struct stack *s)
{
    if(isEmpty(s) == -1)
    {
        return s->arr[s->top];
    }
    else
    {
        s->top--;
    }
}

void push(struct stack *s,char element)
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

char stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

int isOperator(char ch)
{
    if(ch=="+" || ch=="-" || ch=="/" || ch=="*")
    {
        return 1;
    }else{
        return 0;
    }
}

int precedence(char ch)
{
    if(ch=="/" || ch=="*")
    {
        return 5;
    }
    else if(ch=="+" || ch=="-"){
        return 2;
    }
    else
        return 0;
}

string infixTopostfix(string infix)
{
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size*sizeof(char));
    char *postfix=(char *)malloc((infix.length()+1)*sizeof(char));
    int i=0;    //infix traversal
    int j=0;    //postfix fill
    while(infix[i]!='\0')
    {
        if(!isOperator(infix[i]))
        {
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else
        {
            if(precedence(infix[i])>precedence(stackTop(sp)))
            {
                push(sp,infix[i]);
                i++;
            }
            else{
                postfix[j]=pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}

int main()
{
    string infix="x+y";
    cout<<infixTopostfix(infix)<<endl;


    return 0;
}