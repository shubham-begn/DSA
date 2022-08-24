 class info
{    public:

    int maxi;
    int mini;
    int size;
    bool isbst;
};
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    info solve(Node* root,int &ans)
    {
       if(root==NULL)
       {
        return {INT_MIN,INT_MAX,0,true};
       }
       info lhs=solve(root->left,ans);
       info rhs=solve(root->right,ans);

       info curr;

       curr.size=lhs.size+rhs.size+1;
       curr.mini=min(root->data,lhs.mini);
       curr.maxi=max(root->data,rhs.maxi);

       if(lhs.isbst && rhs.isbst && root->data>lhs.maxi && root->data<rhs.mini)
       curr.isbst=true;

       else curr.isbst=false;

       if(curr.isbst)
       ans=max(ans,curr.size);

       return curr;

    }
    int largestBst(Node *root)
    {
    	if(root==NULL) return 0;
        int ans=0;
        info temp=solve(root,ans);
        return ans;
    }
};


//BABBAR SOLUTION
