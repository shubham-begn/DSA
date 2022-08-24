 bool check1(Node*root,int ht,int lvl)
    {
       if(root==NULL) return true;
       if(root->left==NULL && root->right==NULL)
       {
       return ht==lvl;
       }
       
       return check1(root->left,ht,lvl+1) && check1(root->right,ht,lvl+1);
    }
    int height(Node*root)
    {
        if(root==NULL) return 0;
        
        return max(height(root->left),height(root->right))+1;
        
    }
    bool check(Node *root)
    {   if(root==NULL) return true;
    
        int ht=height(root);
        return check1(root,ht,1);
    }
