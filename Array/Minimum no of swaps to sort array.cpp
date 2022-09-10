int minSwaps(vector<int>&nums)
	{
	    int swaps=0;
	    int n=nums.size();
	    
	    vector<pair<int,int>> v;
	    
	    for(int i=0;i<n;i++)
	    v.push_back(make_pair(nums[i],i));
	    
	    sort(v.begin(),v.end());
	    
	    for(int i=0;i<n;i++)
	    {
	        pair<int,int > temp=v[i];
	        int val=temp.first;
	        int idx=temp.second;
	        
	        if(idx!=i)
	        {
	            swaps++;
	            swap(v[i],v[idx]);
	            i--;
	        }
	    }
	    return swaps;
	}
