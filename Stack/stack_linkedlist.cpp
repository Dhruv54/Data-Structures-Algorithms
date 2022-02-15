#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void stackTraversal(struct Node *top)
{
    cout<<"<--- Stack Traversal Start--->"<<endl;
    while (top!=NULL)
    {
        cout<<"Element :"<<top->data<<endl;
        top=top->next;
    }
}

int isEmpty(struct Node* top){
    if(top == NULL)
    {
        cout<<"Stack Underflow!!"<<endl;
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct Node* top){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    if(n==NULL)
    {
        cout<<"Stack Overflow!!"<<endl;
        return 1;
    }else{
        return 0;
    }
}

struct Node* push(struct Node* top,int data){
    
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    if(n==NULL)
    {
        cout<<"Stack Overflow!!"<<endl;
        return top;
    }
    else{
        n->data=data;
        n->next=top;
        top=n;
        return top;
    }
}
struct Node* pop(struct Node* top){

    if (isEmpty(top))  
    {
        return top;
    }
    else{
        struct Node *n=top;
        top=top->next;
        cout<<"Node Deleted :"<<n->data<<endl;
        free(n);
        return top;
    }
}


int peek(struct Node* top,int i){
    while (i!=0)
    {
        top=top->next;
        if(top != NULL){
            i--;
        }else{
            cout<<"Index is out-of Bound!!"<<endl;
            return 0;
        }
    }
    return top->data;
}

int main()
{
    struct Node *top;
    top=push(top,10);
    top=push(top,20);
    top=push(top,30);
    top=push(top,40);
    top=push(top,50);
    top=push(top,60);
    top=push(top,70);
    // stackTraversal(top);
    // top=pop(top);
    // top=pop(top);
    // top=pop(top);
    // top=pop(top);
    // top=pop(top);
    // top=pop(top);
    // top=pop(top);
    // top=pop(top);
    // top=pop(top);
    stackTraversal(top);
    int index=19;
    int peek_data=peek(top,index);

    cout<<"peek element at index : "<<index<<" data : "<<peek_data<<endl;

    return 0;
}