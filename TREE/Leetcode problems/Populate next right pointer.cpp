 void abc(Node * root)
    {
      if(root==NULL) return;
        queue<Node* > q;
        q.push(root);
        q.push(NULL);
        while(q.size()>1)
        {
           Node *temp=q.front();
            q.pop(); 
            
            if(temp==NULL) 
            {
              q.push(NULL);
            }
            else{
            temp->next=q.front();
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
            }
        }
    }
    Node* connect(Node* root) {
        abc(root);
        return root;
    }
