 vector<vector<int> > fourSum(vector<int> &arr, int k) {

        set<vector<int>> finalans;
        int temp,n=arr.size();
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n-3;i++)
        {  
            for(int j=i+1;j<n-2;j++)
            {
                temp=arr[i]+arr[j];
                int sm=k-temp;
                
                int st=j+1,en=n-1;
                while(st<en)
                {
                    
                    
                    if(arr[st]+arr[en] < sm) st++;
                    else if(arr[st]+arr[en] > sm) en--;
                    else
                    {   vector<int> ans;
                        ans.push_back(arr[i]);
                        ans.push_back(arr[j]);
                        ans.push_back(arr[st]);
                        ans.push_back(arr[en]);
                        
                        finalans.insert(ans);
                        
                        st++;
                        en--;
                    }
                }
            }
           
        }
        vector<vector<int>> fans;
        if(finalans.empty()) return fans;
        
        for(auto it:finalans)
        fans.push_back(it);
        
        return fans;
    }
