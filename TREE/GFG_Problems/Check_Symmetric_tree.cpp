bool same(Node*r1 ,Node*r2)
    {
        if(r1==NULL && r2==NULL ) return true;
        if(r1==NULL || r2==NULL)  return false;
        
        if((r1->data==r2->data)&& same(r1->left,r2->right)&& same(r1->right,r2->left))
        return true;
         
        return false;
        
         
    }
    bool isSymmetric(struct Node* root)
    {
	    return same(root,root);
	    
    }
