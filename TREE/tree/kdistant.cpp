#include<bits/stdc++.h>
using namespace std;
struct node
{
   int data;
   node * left;
   node * right;
   node(int x)
   {
       data=x;
       left=right=NULL;
   }
};
void kdistant(node * root,int k)
{
    if(root== NULL) return;
    if(k==0) cout<<root->data<<" ";
    kdistant(root->left,k-1);
    kdistant(root->right,k-1);
}

int main()
{
    node * root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
    kdistant(root,4);
    return 0;
}