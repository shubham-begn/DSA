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

void preorder(node * root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    } 
}
void invertree(node * root)
{
 if(root->left!=NULL && root->right!=NULL) swap(root->left,root->right);
 else return ;
 invertree(root->left);
 invertree(root->right);

}
int main()
{
    node * root=new node(4);
    root->left=new node(2);
    root->right=new node(7);
    root->left->left=new node(1);
    root->left->right=new node(3);
    root->right->left=new node(6);
    root->right->right=new node(9);
    preorder(root);
    cout<<"\n";
    invertree(root);
    preorder(root);
}