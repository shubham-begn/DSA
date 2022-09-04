 bool identical(TreeNode* r1,TreeNode* r2)
    {
        if(r1==NULL && r2==NULL) return true;
        if(r1==NULL || r2==NULL) return false;
        
        return ((r1->val==r2->val) && identical(r1->left,r2->left) && identical(r1->right,r2->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return false;
        if(identical(root,subRoot)) return true;
        
        if((isSubtree(root->left,subRoot)) || isSubtree(root->right,subRoot))
            return true;
        
        return false;
        
    }
