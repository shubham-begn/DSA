#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node * left,*right;
    node(int x)
    {
        data=x;
       left=NULL;
       right=NULL;
    }
};int res=0;
int burntime(node * root,int leaf,int &dist)
{
     if(root==NULL) return 0;
     if(root->data==leaf)
     {
         dist=0;
         return 0;
     }

     int ldist=-1,rdist=-1;
     int lh=burntime(root->left,leaf,ldist);
     int rh=burntime(root->right,leaf,rdist);

     if(ldist!=-1)
     {  ldist++;
         res=max(res,ldist+rh);
     }

     if(rdist!=-1)
     {   rdist++;
         res=max(res,lh+rdist);
     }
     return 1+max(lh,rh);
}
int main()
{
    	
	node *root=new node(10);
	root->left=new node(20);
	root->right=new node(30);
	root->left->left=new node(40);
	root->left->right=new node(50);
	root->left->left->left=new node(60);
	root->left->left->left->left=new node(70);
	int dist=-1;int leaf=50;
	burntime(root,leaf,dist);
    cout<<res;
}