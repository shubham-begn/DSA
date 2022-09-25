ListNode* solve(ListNode* l1,ListNode* l2)
    {
        ListNode* st1=l1;
        ListNode* st2=l2;
        ListNode* pr=st1;
        int carry=0,temp=0;
        while(st1!=NULL)
        {   
            temp=carry;
            temp+=st1->val+st2->val;
            if(temp>=10)
            {
                st1->val=temp%10;
                carry=1;
            }
            else
            {
                carry=0;
                st1->val=temp;
            }
            pr=st1;
            st1=st1->next;
           if(st2->next)
           {
               st2=st2->next;
           }
            else st2->val=0;
            
        }
         if(carry==1)
         {
        if(st1==NULL)
        {
            ListNode * nw=new ListNode(1);
            pr->next=nw;
           // return st1;
        }
        else 
        {
            if(st1->val==9)
            {
                st1->val=0;
                pr=st1;
                ListNode * nw=new ListNode(1);
                 pr->next=nw;
                 // return nw;
                
            }
            else 
            {
                st1->val++;
              //  return l1;
            }
        }
        }
    return l1;
    }
    ListNode* rev(ListNode* l,int &n)
    {
        if(l==NULL) return NULL;
        if(l->next==NULL)
        {
            n=1;
            return l;
        }
        ListNode *pr=NULL;
        while(l!=NULL)
        {   n++;
            ListNode* nxt=l->next;
            l->next=pr;
            
            pr=l;
            l=nxt;
        }
        
        return pr;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1->val==0) return l2;
        if(l2->val==0) return l1;
        
        int n1=0,n2=0;
        
        l1=rev(l1,n1);
        l2=rev(l2,n2);
        
        ListNode* ans;
        if(n1>=n2) 
        {
           ans=solve(l1,l2);
            
        }
        else 
        {
            ans=solve(l2,l1);
            //ans=l2;
        }
        int n3=0;
        ans=rev(ans,n3);
        return ans;
        
    }
