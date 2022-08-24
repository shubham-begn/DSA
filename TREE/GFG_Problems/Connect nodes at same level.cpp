 Node *prev=NULL;
    void connect(Node *root)
    {
      if(root==NULL) return;
      queue<Node*> q;
      q.push(root);
      while(!q.empty())
      { int cnt=q.size();
      prev=NULL;
       for(int i=0;i<cnt;i++)
       {
          Node *f=q.front();
          f->nextRight=prev;
          prev=f;
          q.pop();
          if(f->right!=NULL) q.push(f->right);
          if(f->left!=NULL) q.push(f->left);
      }
    }    
    }
