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
    string s;
    int ans=0;

    
void abc(node* root)
{
  if(root==NULL)
  {
   ans+=stoi(s, 0, 2);
      return;
  }
    s.push_back(char(root->data));
    abc(root->left);
    s.pop_back();
    abc(root->right);
}

int sum(node * root)
{
    abc(root);
    return ans;
}

int main()
{
    node * root=new node(1);
    root->left=new node(0);
    root->right=new node(1);
    root->left->left=new node(0);
    root->left->right=new node(1);
    root->right->left=new node(0);
    root->right->right=new node(1);
    cout<<sum(root);
    return 0;
}