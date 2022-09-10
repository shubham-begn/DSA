long long countTriplets(long long arr[], int n, long long sum)
	{
	    sort(arr,arr+n);
	    int cnt=0;
	    for(int i=0;i<n;i++)
	    {
	        int temp=sum-arr[i];
	        int j=i+1,k=n-1;
	        
	        while(j<k)
	        {
	            if(arr[j]+arr[k]>=temp)
	            k--;
	            
	            else
	            {
	                cnt+=k-j;
	                j++;
	            }
	        }
	    }
	    return cnt;
	}
