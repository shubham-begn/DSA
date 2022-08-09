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

bool pathfind(node *root,vector<int> &ans,int n)
{
    if( root== NULL) return false;
    ans.push_back(root->data);
    if(root->data==n) return true;
    if((pathfind((root->left),ans,n))||pathfind((root->right),ans,n)) return true;

    ans.pop_back();
    return false;
}
int lca(node *root,int n1,int n2)
{
    
    vector<int > ans1,ans2;
    pathfind(root,ans1,n1); 
    pathfind(root,ans2,n2);

    for(int i=0;i<ans1.size();i++)
    {
        if(ans1[i+1]!=ans2[i+1])
       { return ans1[i];
        break;}
    }
}
int lca2(node *root,int n1,int n2)
{
    if(root==NULL) return 0;
    if(root->data==n1||root->data==n2) return root->data;
    int lca1=lca2(root->left,n1,n2);
    int lca3=lca2(root->right,n1,n2);
    if(lca1!=0L&&lca3!=0) return root->data;
    else if(lca1==0) return lca3;
    else return lca1;
}
int main()
{
    node * root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
    int n1=30,n2=50;
   // cout<<lca(root,n1,n2);
    cout<<lca2(root,n1,n2);
    return 0;
}