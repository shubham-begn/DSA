Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.



int cnt=0;
    void solve(TreeNode* root,int mx)
    {
        if(root==NULL) return;
        
        if(root->val>=mx) cnt++;
        mx=max(root->val,mx);
        
        solve(root->left,mx);
        solve(root->right,mx);
    }
    int goodNodes(TreeNode* root) {
        int mx=root->val;
        solve(root,mx);
        return cnt;
    }
