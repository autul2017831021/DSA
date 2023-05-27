#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,vi;
    cin>>n;
    vector<int>v;
    int a[n+1],b[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=1;
        cout<<b[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j] && b[j]+1>b[i])
                b[i]=b[j]+1;

        }
        for(int k=0;k<n;k++)
        cout<<b[k]<<" ";
        cout<<endl;
    }
    cout<<*max_element(b,b+n)<<endl;
    int res=*max_element(b,b+n);
    for(int i=n-1;i>=0;i--)
    {
        if(b[i]==res)
        {
            if(res>0)
                res--;
            else
                break;
            vi=a[i];v.push_back(vi);
        }
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
}
