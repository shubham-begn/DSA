 int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        for(int i=1;i<n;i++)
        {
            arr[i]+=arr[i-1];
        }
        int ans=0;
        for(int i=1;i<=n;i+=2)
        {
            int gap=i;
            ans+=arr[gap-1];
            
            for(int j=gap;j<n;j++)
            {
                ans+=arr[j]-arr[j-gap];
            }
        }
        return ans;
    }
