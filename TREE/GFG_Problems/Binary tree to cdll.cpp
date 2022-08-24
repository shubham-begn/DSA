Node * prev=NULL;
    Node *h=NULL;
    void abc(Node *root)
    {
        if(root==NULL) return;
        abc(root->left);
        if(prev==NULL)
        {
            h=root;
        }
        else
        {
            root->left=prev;
            prev->right=root;
        }
        prev=root;
        
        abc(root->right);
    }
    Node *bTreeToCList(Node *root)
    {
    abc(root);
    Node *curr=h;
    while(curr->right!=NULL) curr=curr->right;
    curr->right=h;
    h->left=curr;
    return h;
    }
