#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*left,*right;

    node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};
void inorder(node *root)
{
    if(root==NULL)
    return ;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}



int preindex=0;
node * makeit(int in[],int pre[],int st,int en)       //pre=1 2 3 4 5     in=2 1 4 3 5
{  
    //if(root==NULL) return NULL;
   if(st>en) return NULL;
   node*root=new node(pre[preindex++]);

   int index,temp=root->data;

   for(int i=st;i<=en;i++)
   {
       if(pre[i]==temp)
       {
        index=i;
        break;
       }
   }

   root->left=makeit(in,pre,st,index-1);
   root->right=makeit(in,pre,index+1,en);

   return root;
}

int main()
{
    int n;
    cin>>n;
    int in[]={2,1,4,3,5};
    int pre[]={2,1,3,4,5};

    node *root=makeit(in,pre,0,4);
     cout<<root->data<<"\n";
    inorder(root);
}