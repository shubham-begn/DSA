void solve(Node*root,int l,int h ,int &ans)
{
    if(root==NULL) return;
    
    solve(root->left,l,h,ans);
    if(root->data>=l && root->data<=h) ans+=1;
    
    solve(root->right,l,h,ans);
}
    int getCount(Node *root, int l, int h)
    {
      int ans=0;
      solve(root,l,h,ans);
      return ans;
    }
};
