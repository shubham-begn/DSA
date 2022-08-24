#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode*left,*right;

    TreeNode(int x)
    {
        val=x;
        left=NULL;
        right=NULL;
    }
};
TreeNode* build(vector<int> in,int st,int en)
    {   if(st>en) return NULL;
        int mid=(st+en)/2;
        TreeNode* root=new TreeNode(in[mid]);
        root->left=build(in,st,mid-1);
        root->right=build(in,mid+1,en);
        
        return root;
    }
    void traverse(TreeNode* root,vector<int> &in)
    {
        if(root==NULL) return;
        traverse(root->left,in);
        in.push_back(root->val);
        traverse(root->right,in);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        traverse(root,in);
        return build(in,0,in.size()-1);
    }
void prnt(TreeNode* root)
{
    if(root==NULL) return;
    cout<<root->val<<" ";
    prnt(root->left);
    prnt(root->right);
}
int main()
{
    TreeNode* root=new TreeNode(10);
    root->right=new TreeNode(20);
    root->right->right=new TreeNode(30);
    root->right->right->right=new TreeNode(40);
    root->right->right->right->right=new TreeNode(50);

    TreeNode* rt=balanceBST(root);
    prnt(rt);
}