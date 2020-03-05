#include<stdio.h>
typedef struct btree
{
    int data;
    struct btree *left, *right;
}btree;
btree *root;

typedef struct queue
{
    btree * node;
    int front,rear;
    int size;
}queue;


btree *createNode(int data)
{
    btree * temp=(btree*)malloc(sizeof(btree));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
btree * insert(btree *root,int data)
{
    if(root==NULL)
    {
        root=createNode(data);
        return root;
    }
}


int main()
{
    int key;
    for(int i=0;i<5;i++)
    {
        key=rand()%100;
        root=insert(root,key);
    }

}
