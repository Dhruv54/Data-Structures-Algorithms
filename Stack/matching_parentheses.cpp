#include<iostream>

using namespace std;

struct stack
{
    int top;
    int size;
    char *arr;
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

void push(struct stack *s,char exp)
{
    if(isFull(s) == 1)
    {
        return;
    }
    else
    {
        s->top++;
        s->arr[s->top]=exp;
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

int parenthesis_matching(struct stack *sp,string exp)
{
    for(int i=0; exp[i]!='\0';i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
        {
            push(sp,exp[i]);
        }
        else if(exp[i]==')')
        {
            if(sp->arr[sp->top]=='(')
            {
                pop(sp);
            }
            else
            {
                return -1;
            }
            
        }
        else if(exp[i]==']')
        {
            if(sp->arr[sp->top]=='[')
            {
                pop(sp);
            }
            else
            {
                return -1;
            }
            
        }
        else if(exp[i]=='}')
        {
            if(sp->arr[sp->top]=='{')
            {
                pop(sp);
            }
            else
            {
                return -1;
            }
            
        }

    }
    if(isEmpty(sp))
    {
        return 0;
    }
    return -1;
}


int main()
{
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size*sizeof(char));
    string exp="[(1=2){(2+5)(4+5)}]";

    int result=parenthesis_matching(sp,exp);
    
    if(result==0)
    {
        cout<<"matching!!"<<endl;
    }else{
        cout<<"Not matching!!"<<endl;
    }
    stackTraversal(sp);
    return 0;
}