int solve(Node* root,int x,int & cnt)
{
    if(root==NULL) return 0;
    //if(root->left==NULL && root->right==NULL) return root->data;
    
    int lh=solve(root->left,x,cnt);
    int rh=solve(root->right,x,cnt);
    
    if(x==lh+rh+root->data) cnt++;
    
    return root->data+lh+rh;
    
    
    
}

int countSubtreesWithSumX(Node* root, int x)
{
	int cnt=0;
	int temp=solve(root,x,cnt);
	return cnt;
}
