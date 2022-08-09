#include<bits/stdc++.h>
using namespace std;
struct node
{
    node *left,*right;
    int data;

    node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};
bool path(node*root,int n,vector<int> &p)
{
    if(root==NULL) return false;
    
    p.push_back(root->data);
    if(root->data==n) return true;

    if(path(root->left,n,p) || path(root->right,n,p)) return true;

    p.pop_back();
    return false;

    

}
int lca(node *root,int n1,int n2)
{   vector<int> p1,p2;
    bool temp=path(root,n1,p1);
    if(temp==false) return -1;

    bool temp2=path(root,n2,p2);
    if(temp2==false) return -1;

    int i=0,ans;
    while(1)
    {
      if(p1[i]==p2[i])
      ans=p1[i];
       
      else break;

      i++;
    }
    
return ans;
}
int main()
{
    node *root=new node(10);
	root->left=new node(20);
	root->right=new node(30);
	root->right->left=new node(40);
	root->right->right=new node(50);
	int n1=60,n2=50;
	
	int ans=lca(root,n1,n2);
    cout<<ans;
}