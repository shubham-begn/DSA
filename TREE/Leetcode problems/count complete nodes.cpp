  int countNodes(TreeNode* root) {
     int lh=0,rh=0;
      TreeNode*curr=root;
        while(curr!=NULL)
        {
            lh++;
            curr=curr->left;
        }curr=root;
        while(curr!=NULL)
        {
            rh++;
            curr=curr->right;
        }
        
        if(lh==rh)
        {
            return pow(2,lh)-1;
        }
        else return 1+countNodes(root->left)+countNodes(root->right);
    }
