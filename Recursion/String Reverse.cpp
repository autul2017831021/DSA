#include<bits/stdc++.h>
using namespace std;

void reverse_no_extra_space_void(string &s, int &i){
    if(i >= s.size()/2)return;
    swap(s[i],s[s.size()-i-1]);
    i++;
    reverse_no_extra_space_void(s,i);
    return;
}
string reverse_str(string s, int i){
    if(i < s.size()/2){
        swap(s[i],s[s.size()-i-1]);
        i++;
        return reverse_str(s,i);
    }
    else return s;
}

int main(){
    string s;
    cin>>s;
    int i = 0, j =0;
    reverse_no_extra_space_void(s,i);
    cout<<s<<endl;
    string t = reverse_str(s,j);
    cout<<t<<endl;
}
