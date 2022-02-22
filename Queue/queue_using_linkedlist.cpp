#include <iostream>
using namespace std;

struct linkedList *f=NULL;
struct linkedList *r=NULL;

struct linkedList
{
    int data;
    struct linkedList *next;
};

void printQueuell(struct linkedList *ptr)
{
    while (ptr != NULL)
    {
        cout<<"Element = "<<ptr->data<<endl;
        ptr=ptr->next;
    }
    
}

void enqueue(int val)
{
    struct linkedList *node = (struct linkedList *)malloc(sizeof(struct linkedList));
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
int dequeue()
{
    int val=-1;
    struct linkedList *ptr=f;
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
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    // enqueue(f, r, 30);
    // enqueue(f, r, 40);
    // enqueue(f, r, 50);
    printQueuell(f);
    cout<<"Delete Element : "<<dequeue()<<endl;
    cout<<"Delete Element : "<<dequeue()<<endl;
    cout<<"Delete Element : "<<dequeue()<<endl;
    cout<<"Delete Element : "<<dequeue()<<endl;
    printQueuell(f);
    // enqueue(f,r,20);
    // enqueue(f,r,30);
    // enqueue(f,r,40);
    // enqueue(f,r,50);
    return 0;
}