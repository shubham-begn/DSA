void solve(TreeNode* root,int k,int &ans)
    {
        if(root==NULL) return;
        if(k==1) ans+=root->val;
        
        solve(root->left,k-1,ans);
        solve(root->right,k-1,ans);
    }
    int height(TreeNode*root)
    {
        if(root==NULL) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int deepestLeavesSum(TreeNode* root) {
       int ht=height(root);
        int ans=0;
        solve(root,ht,ans);
        return ans;
    }
