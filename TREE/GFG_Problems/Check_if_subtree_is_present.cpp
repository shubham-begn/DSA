 bool identical(Node*t,Node*s)
    {
        if(t==NULL && s==NULL) return true;
        if((t==NULL && s!=NULL)|| (t!=NULL &&s==NULL)) return false;
        else if(t!=NULL && s!=NULL){
        if((t->data==s->data)&& identical(t->left,s->left) && identical(t->right,s->right))
        return true;
        
        return false;
        }
        return false;
    }
    bool isSubTree(Node* T, Node* S) 
    {
       if( S==NULL) return true;
       if(T==NULL) return false;
       
       if(identical(T,S)) return true;
       return isSubTree(T->left,S)|| isSubTree(T->right,S);
        
        
    }

//There is a optimised tecgnique in o(n) time and and O(n) space
//just find out inorder and preorder of given tree and subtree if they have have same substring present then subtree is present
