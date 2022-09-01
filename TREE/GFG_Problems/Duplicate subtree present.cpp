unordered_set<string> st;
    bool ans=false;
    void traverse(Node* root,string &s)
    {
        if(root==NULL) return;
        s.push_back(char(root->data));
        traverse(root->left,s);
        traverse(root->right,s);
        
    }
    void solve(Node* root)
    {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) return;
        string s;
        traverse(root,s);
        
        if(!s.empty() && st.find(s)!=st.end()) ans=true;
        else st.insert(s);
        
        solve(root->left);
        solve(root->right);
    }
    int dupSub(Node *root) {
      solve(root->left);
      solve(root->right);
      if(ans) return 1;
      else return 0;
    }
