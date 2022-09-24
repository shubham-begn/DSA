 ListNode* rev(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* pr=NULL;
        while(head!=NULL)
        {
            ListNode* nxt=head->next;
            head->next=pr;
            
            pr=head;
            head=nxt;
        }
        
        return pr;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        
        vector<int> ans;
        if(head==NULL || head->next==NULL)
        {
            ans.push_back(0);
            return ans;
        }
        
        stack<int> s;
        ListNode* h=rev(head);
        //stack<int> s;
        
        //s.push(h->val);
        while(h!=NULL)
        {
           while(!s.empty() && s.top()<=h->val)
               s.pop();
            
            if(s.empty()) ans.push_back(0);
            else ans.push_back(s.top());
            
            s.push(h->val);
            h=h->next;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
