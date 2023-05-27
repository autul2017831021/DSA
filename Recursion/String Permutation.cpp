#include<bits/stdc++.h>
using namespace std;

void permutation_void_oneWay(string s, set<string> &st, int in){
    if(in+1==s.size())return ;
    st.insert(s);
    in++;
    for(int i=in;i<s.size();i++){
        string t = s;
        swap(t[in],t[i]);
        //cout<<t<<endl;
        permutation_void_oneWay(t,st,in);
    }
}

vector<string>permutation_vec_oneWay(string s)
{
    vector<string>v;
    sort(s.begin(), s.end());
    do {
        v.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    return v;
}

int main(){
    string s;
    cin>>s;
    set<string> st;
    set<string> ::iterator it;
    permutation_void_oneWay(s,st,-1);
    cout<<st.size()<<endl;
    for(it=st.begin();it!=st.end();it++){
        cout<<*it<<endl;
    }
}
