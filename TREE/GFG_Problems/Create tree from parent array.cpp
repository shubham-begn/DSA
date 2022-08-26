Node *createTree(int parent[], int n)
    {
        vector<Node*> v;
        for(int i=0;i<n;i++)
        {
        v.push_back(new Node(i));
        }
        Node* root=NULL;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==-1)
            root=v[i];
        }
        for(int i=0;i<n;i++)
        {
            if(parent[i]==-1) continue;
            if(v[parent[i]]->left==NULL)
            {
                v[parent[i]]->left=v[i];   
            }
            
            else v[parent[i]]->right=v[i];
            
        }
        return root;
        }
        
