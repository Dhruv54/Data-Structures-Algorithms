#include<stdio.h>
#include<malloc.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data)
{
    struct Node* n;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

struct  Node* Search(struct Node* root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(key==root->data)
    {
        return root;
    }
    else if(key<root->data)
    {
        return Search(root->left,key);
    }
    else if(key>root->data)
    {
        return Search(root->right,key);
    }
}

int main()
{
    struct Node* p;struct Node* p1;struct Node* p2;struct Node* p3;struct Node* p4;struct Node* p5;struct Node* p6;
    p =createNode(11);
    p1=createNode(5);
    p2=createNode(15);
    p3=createNode(4);
    p4=createNode(6);
    p5=createNode(12);
    p6=createNode(16);

    //   11
    //  /  \
    //  5  15
    // /\  /\
    //4 6 12 16

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->left=p5;
    p2->right=p6;

    struct Node *n=Search(p,12);
    if(n!=NULL)
    {
        printf("Found %d :",n->data);
    }else{
        printf("Not found");
    }
    return 0;
}