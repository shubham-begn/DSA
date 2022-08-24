void solve(Node*root,int k,int &ans)
	{   
	    Node*curr=root;
	    int temp=INT_MAX;
	    while(curr!=NULL)
	    {
	        if(temp>abs(curr->data-k))
	        temp=abs(curr->data-k);
	        
	        if(curr->data>k)
	        curr=curr->left;
	        
	        else curr=curr->right;
	    }
	    ans=temp;
	    
	   
	}
    int minDiff(Node *root, int k)
    {
        int ans=INT_MAX;
        solve(root,k,ans);
        return ans;
    }
