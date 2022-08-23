 int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 0;
        int sm=0;
        
        if(root->val%2==0)
        {
        if(root->left!=NULL)
        {
          if(root->left->left!=NULL) sm+=root->left->left->val;
          if(root->left->right!=NULL) sm+=root->left->right->val;
        }
        if(root->right!=NULL)
        {
          if(root->right->left!=NULL) sm+=root->right->left->val;
          if(root->right->right!=NULL) sm+=root->right->right->val;
        }
        }
        
        sm+=sumEvenGrandparent(root->left);
        sm+=sumEvenGrandparent(root->right);
        
        return sm;
    }
