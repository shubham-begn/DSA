 bool isgood(vector<int>& weights, int days,int ans)
    {
        int req=1;
        int n=weights.size();
        int temp=0;
        for(int i=0;i<n;i++)
        {
           if(temp+weights[i]>ans)
           {
               req++;
               temp=weights[i];
           }
            else temp+=weights[i];
        }
        return (req<=days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=0,high=0,ans;
        int n=weights.size();
        for(int i=0;i<n;i++)
        {
            low=max(low,weights[i]);
            high+=weights[i];
        }
        int mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(!isgood(weights,days,mid))
                low=mid+1;
            else 
            {   ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
