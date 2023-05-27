#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s,int i){
    if(s[i]!=s[s.size()-1-i])return false;
    if(i>(s.size()/2))return true;
    return isPalindrome(s,i+1);
}
string longestPalindrome(string s) {
    vector<string>v;
    for(int i=0;i<s.size();i++){
        string t;
        t.push_back(s[i]);
        v.push_back(t);
        for(int j=i+1;j<s.size();j++){
            t.push_back(s[j]);
            v.push_back(t);
        }
    }
    string a = v[0];
    int ans = 1;
    for(int i=0;i<v.size();i++){
        if(ans<v[i].size()){
            if(isPalindrome(v[i],0)){
                ans=v[i].size();
                a = v[i];
            }
        }
    }
    return a;
}
main()
{
    string s;
    cin>>s;
    cout<<longestPalindrome(s);
}


