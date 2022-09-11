 int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> s(arr.begin(),arr.end());
        int ans;
        for(int i=1;i<=INT_MAX;i++)
        {
            if(s.find(i)==s.end())
            {
                k--;
                if(k==0)
                {
                    ans=i;
                    break;
                }
            }
        }
        return ans;
    }
