 int ans=INT_MIN;
    void solve(TreeNode* root,int mx,int mn)
    {
        if(root==NULL) return;
        mx=max(mx,root->val);
        mn=min(root->val,mn);
        
        ans=max(ans,mx-mn);
        
        solve(root->left,mx,mn);
        solve(root->right,mx,mn);
    }
    int maxAncestorDiff(TreeNode* root) {
        int mx=INT_MIN;
        int mn=INT_MAX;
        
        solve(root,mx,mn);
        return ans;
    }
};
