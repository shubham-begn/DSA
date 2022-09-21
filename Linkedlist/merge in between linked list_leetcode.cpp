 ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *st=NULL;
        ListNode* en=NULL;
        
        ListNode* curr=list1;
        int i=0;
        for(i=0;i<a;i++)
        {
            st=curr;
            curr=curr->next;
        }
        for(;i<=b;i++)
        {
            curr=curr->next;
        }
        en=curr;
        
        //cout<<st->val<<" "<<en->val;
        st->next=list2;
        curr=list2;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=en;
        return list1;
        
    }
