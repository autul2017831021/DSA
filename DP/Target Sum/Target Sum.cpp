#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<pair<ll,ll> > vp;
typedef vector<ll> vc;
typedef map<ll,ll> ml;
typedef ostringstream OS ;
typedef stringstream SS ;
typedef double dl;
#define pb push_back
#define bg begin()
#define en end()
#define rbg rbegin()
#define ren rend()
#define sz size()
#define nl printf("\n")
#define sp printf(" ")
#define yes printf("YES\n")
#define no printf("NO\n")
#define mone printf("-1\n")
#define ne cin>>
#define de cout<<
#define r0 return 0;
#define F first
#define S second
#define its (*it).S
#define itf (*it).F
#define inf 1000000000000000000
#define ninf -1000000000
#define hoynai cout<<"hoynai"<<endl;
#define mod 1000000007
#define pi acos(-1.0)
#define FAST_FUCK ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
bool is_target_sum_possible(vector<int> v,int target,int i){
    if(target == 0)return true;
    if(target<0 || i>=v.size())return false;
    return is_target_sum_possible(v,target-v[i],i+1) or is_target_sum_possible(v,target,i+1);
}
int num_of_ways(vector<int> v,int target,int i){
    if(target == 0){
        return 1;
    }
    if(target<0 || i>=v.size())return 0;
    return num_of_ways(v,target-v[i],i+1) + num_of_ways(v,target,i+1);
}
int numbers(vector<int> v,int target,int i){
    if(target == 0){
            //cout<<endl;
        return i;
    }
    else if(target<0 || i>=v.size())return -1;

    int leftIndex = numbers(v,target-v[i],i+1);
    int rightIndex = numbers(v,target,i+1);

    if(max(leftIndex,rightIndex)==-1)return -1;
    if(leftIndex != -1)cout<<v[leftIndex]<<" ";
    if(rightIndex != -1)cout<<v[rightIndex]<<" ";
    nl;
    return i;
}
main()
{
    int n,t;
    cin>>n>>t;
    vector<int> v;

    for(int i=0;i<n;i++){
        int c;cin>>c;
        v.push_back(c);
    }
    if(is_target_sum_possible(v,t,0)){
        cout<<"Target Reached!!"<<endl;
        cout<<num_of_ways(v,t,0)<<" Ways To Reach Target"<<endl;
        numbers(v,t,0);
    }
    else cout<<"Not Possible To Reach Target"<<endl;
}


