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

void levelorder(node* root)
{
    if(root==NULL) return;
    queue<node *> q;
    q.push(root);
    while(q.empty()==false)
    {
        node * curr=q.front();
        q.pop();
        cout<<curr->data<<" ";

        if(curr->left!=NULL) q.push(curr->left);
        if(curr->right!=NULL) q.push(curr->right);
    }
}
void linebyline(node * root)
{
    if(root==NULL) return;
    queue<node*> q1;
    q1.push(root);
    q1.push(NULL);
    while(q1.size()>1)
    {
        node * curr=q1.front();
        q1.pop();
        if(curr==NULL) {cout<<"\n"; q1.push(NULL); continue;}
        
        else{cout<<curr->data<<" ";

        if(curr->left!=NULL) q1.push(curr->left);
        if(curr->right!=NULL) q1.push(curr->right);}

    }
}
void linebyline2(node * root)
{
    if(root==NULL) return ;
    queue<node*> q2;
    q2.push(root);
    while(q2.empty()==false)
    {  
        int cnt=q2.size();
        for(int i=0;i<cnt;i++)
        {node * curr=q2.front();
            cout<<curr->data<<" ";
            q2.pop();
         if(curr->left!=NULL) q2.push(curr->left);
        if(curr->right!=NULL) q2.push(curr->right);
        }
        cout<<"\n";
       
    }
}
int main()
{
    node * root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
   // levelorder(root);
    linebyline2(root);
    
    return 0;
}