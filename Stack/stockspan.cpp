#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=8;
    //cin>>n;
    int a[n];
    for(int i=0;i<n;i++) 
    cin>>a[i];
    stack <int> st;
    st.push(INT_MAX);
    st.push(0);
    cout<<"1 ";
    for(int j=1;j<n;j++)
    {   
        while(a[j] > a[st.top()] && !st.empty())
       { 
           st.pop();}

      if(st.top()==INT_MAX) cout<<j+1<<" ";
      else cout<<j-st.top()<<" ";
       
        st.push(j);
    }
    return 0;
}