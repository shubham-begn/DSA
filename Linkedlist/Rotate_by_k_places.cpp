 ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        
        int n=0;
        ListNode* curr=head,*lst=NULL;
        while(curr!=NULL)
        {
            n++;
            lst=curr;
            curr=curr->next;
        }
        
        k=k%n;
        if(k==0) return head;
        curr=head;
        ListNode* temp=NULL,*mid=NULL;
       for(int i=0;i<n-k;i++)
       {
           temp=curr->next;
           mid=curr;
           curr=curr->next;
       }
        
      //  cout<<mid->val<<" "<<temp->val<<" "<<lst->val<<" ";
        mid->next=NULL;
        ListNode* nh=temp;
        lst->next=head;
        
        return nh;
        
        
    }
