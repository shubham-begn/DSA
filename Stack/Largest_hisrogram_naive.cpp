// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    void leftsmaller(long long arr[], int n,vector<long long> &left)
    {
       stack<long long> s;
       s.push(0);
       left.push_back(-1);
       
       for(int i=1;i<n;i++)
       {
           while(s.empty()==false && arr[s.top()]>=arr[i])
           s.pop();
           
           if(s.empty()) left.push_back(-1);
           else left.push_back(s.top());
           
           s.push(i);
       }
    }
    void rightsmaller(long long arr[], int n,vector<long long> &right)
    {
       stack<long long> s;
       right.push_back(n);
       s.push(n-1);
       
       for(int i=n-2;i>=0;i--)
       {
           while(s.empty()==false && arr[s.top()]>=arr[i])
           s.pop();
           
           if(s.empty()) right.push_back(n);
           else right.push_back(s.top());
           
           s.push(i);
       }
       reverse(right.begin(),right.end());
       
    }
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long> left;
        vector<long long> right;
        
        leftsmaller(arr,n,left);
        rightsmaller(arr,n,right);
        
        long long ans=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            long long length=arr[i];
            long long width=right[i]-left[i]-1;
            
            ans=max(ans,length*width);
        }
        
        return ans;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends
