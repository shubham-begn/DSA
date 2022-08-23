 int cnt=0;
    pair<int,int> solve(TreeNode* root)
    {
        if(root==NULL) return {0,0};
        
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        
        int sm=0;
        sm+=(left.first==NULL)?0:left.first;
        sm+=(right.first==NULL)?0:right.first;
        sm+=root->val;
        
        int sz=left.second+right.second+1;
        
        if(root->val==sm/sz) cnt++;
        return {sm,sz};
        
        
    }
    int averageOfSubtree(TreeNode* root) {
        
        pair<int,int> abc=solve(root);
        return cnt;
    }
