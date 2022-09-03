   bool flag=true;
    TreeNode* nr=NULL;
    ListNode * middle(ListNode * head,ListNode* tail)
    {   if(head==NULL) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=tail && fast->next!=tail)
        {
          slow=slow->next;
          fast=fast->next->next;
        
        }
        return slow;
    }
    TreeNode* solve(ListNode* head,ListNode* tail)
    {   if(head==tail) return NULL;
     
        ListNode * mid=middle(head,tail);
        
        TreeNode * root=new TreeNode(mid->val);
        if(flag)
        {
            nr=root;
            flag=false;
        }
        root->left=solve(head,mid);
        root->right=solve(mid->next,tail);
     
        return root;
        
   }
    TreeNode* sortedListToBST(ListNode* head)
    {   //TreeNode * nr=middle(head); 
        if(head==NULL) return NULL;
        TreeNode * temp=solve(head,NULL);
        return nr;
    }
