int solve(Node* root)
    {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return root->data;
        
        int lh=solve(root->left); if(lh==-1) return -1;
        int rh=solve(root->right); if(rh==-1) return -1;
        
        if(root->data==lh+rh)
        return root->data+lh+rh;
        
        return -1;
        
        
    }
    bool isSumTree(Node* root)
    {
         int temp=solve(root);
         if(temp==-1) return false;
         return true;
    }
