#include<bits/stdc++.h>
using namespace std;
void nextgreater(int a[],int n)
{   int ans[n];
    stack<int > s;
    s.push(INT_MAX);
    s.push(a[n-1]);
    ans[n-1]=-1;
    for(int i=n-2;i>=0;i--)
    {
       while(a[i] > s.top()) s.pop();
       if(s.top()==INT_MAX) ans[i]=-1;
       else ans[i]=s.top();

       s.push(a[i]);
    }

    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    nextgreater(a,n);
}