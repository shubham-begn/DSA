 int height(TreeNode* root)
    {
        if(root==NULL) return 0;
        return max(height(root->left),height(root->right))+1;
        
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root==NULL) return NULL;
        
        int lh=height(root->left);
        int rh=height(root->right);
        
        if(lh==rh) return root;
        
        if(rh>lh) return lcaDeepestLeaves(root->right);
        else return lcaDeepestLeaves(root->left);
        
        
        
    }
