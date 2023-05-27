/// Tutorial -> https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lowerBound(vector<int>&v,int l,int r,int key){
        while(r>l){
            int m = (l+r)/2;
            if (v[m] >= key)r = m;
            else l = m+1;
        }
        return r;
    }
    int LIS(vector<int>& v){
        if(v.size()==0)return 0;
        int length = 1;
        vector<int>tail(v.size(),0);
        tail[0] = v[0];
        for(int i=0;i<v.size();i++){
            if(v[i]<tail[0]){
                tail[0] = v[i];
            }
            else if(v[i]>tail[length-1]){
                tail[length] = v[i];
                length++;
            }
            else{
                tail[lowerBound(tail,0,length-1,v[i])] = v[i];
            }
        }
        return length;
    }
};

int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        v.push_back(x);
    }
    cout<<obj.LIS(v);
}
