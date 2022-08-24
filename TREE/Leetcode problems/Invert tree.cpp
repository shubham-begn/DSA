  void abc(TreeNode * root)
    {
       if(root==NULL) return;
        else{
        abc(root->left);
        abc(root->right);
            swap(root->left,root->right);}
    }
    TreeNode* invertTree(TreeNode* root) {
        abc(root);
        return root;
    }
