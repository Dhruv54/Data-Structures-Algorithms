#include<iostream>

using namespace std;

struct DEQueue *f=NULL;
struct DEQueue *r=NULL;

struct DEQueue
{
    int data;
    struct DEQueue *next;
};

void printDEQueue(struct DEQueue *ptr)
{
    while(ptr!=NULL)
    {
        cout<<ptr->data<<"  ";
        ptr=ptr->next;
    }cout<<endl;
}
void enqueueF(int val)
{
    struct DEQueue *node = (struct DEQueue *)malloc(sizeof(struct DEQueue));
    if (node == NULL)
    {
        cout << "Queue is full!!" << endl;
    }
    else
    {
        node->data = val;
        node->next = f;
        f=node;
    }
}
void enqueueR(int val)
{
    struct DEQueue *node = (struct DEQueue *)malloc(sizeof(struct DEQueue));
    if (node == NULL)
    {
        cout << "Queue is full!!" << endl;
    }
    else
    {
        node->data = val;
        node->next = NULL;
        if (f == NULL)
        {
            f = r = node;
        }
        else
        {
            r->next = node;
            r = node;
        }
    }
}
int dequeueF()
{
    int val=-1;
    struct DEQueue *ptr=f;
    if(f==NULL)
    {
        cout<<"Queue is full!!!"<<endl;
    }else{
        f=f->next;
        val=ptr->data;
        free(ptr);
    }
    return val;
}
int dequeueR()
{
    int val=-1;
    struct DEQueue *ptr=f;
    if(f==NULL)
    {
        cout<<"Queue is full!!!"<<endl;
    }else{
        f=f->next;
        val=ptr->data;
        free(ptr);
    }
    return val;
}

int main()
{
    enqueueR(10);
    enqueueR(20);
    enqueueR(30);
    enqueueR(40);
    enqueueF(50);
    enqueueF(60);
    enqueueF(70);
    printDEQueue(f);
    return 0;
}