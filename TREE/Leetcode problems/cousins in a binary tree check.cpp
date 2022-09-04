void height(TreeNode* root,int x,int &p,int &h,int cnt)
    {
        if(root==NULL) return;
        if((root->left && root->left->val==x) || (root->right&& root->right->val==x))
        {
            h=cnt+1;
            p=root->val;
            return;
        }
        
        height(root->left,x,p,h,cnt+1);
        height(root->right,x,p,h,cnt+1);
        
    }
    bool isCousins(TreeNode* root, int x, int y) {
        
        int h1,h2;
        int p1;
        int p2;
      
        height(root,x,p1,h1,0);
        
        height(root,y,p2,h2,0);
        
       //cout<<h1<<" "<<h2<<" "<<p1->val<<" "<<p2->val;
        if(h1==h2 && p1!=p2) return true;
        else return false;
    }
