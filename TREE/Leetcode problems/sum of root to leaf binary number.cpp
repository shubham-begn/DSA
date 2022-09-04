void solve(TreeNode* root,int temp,int &ans)
    {
        
       if(root==NULL) return;
        temp=temp*2 +root->val;
        
        if(root->left==NULL && root->right==NULL)
            ans+=temp;
        
        solve(root->left,temp,ans);
        solve(root->right,temp,ans);
        
        
    }
    int sumRootToLeaf(TreeNode* root) {
        int temp=0;
        int ans=0;
        solve(root,temp,ans);
        return ans;
    }
