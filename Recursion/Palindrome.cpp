#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s,int i){
    if(s[i]!=s[s.size()-1-i])return false;
    if(i>(s.size()/2))return true;
    cout<<s[i]<<" "<<s[s.size()-1-i]<<endl;
    return isPalindrome(s,i+1);
}
main()
{
    string s;
    cin>>s;
    /// aabaa
    if(isPalindrome(s,0)) cout<<"Palindrome"<<endl;
    else cout<<"Not Palindrome"<<endl;
}

