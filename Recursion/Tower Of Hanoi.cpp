#include <bits/stdc++.h>
using namespace std;
int i=1;
void TOH(int n, string src, string dest, string helper, vector<pair<int,pair<string,string>>> &steps){
    if(n==0) return;
    TOH(n-1,src,helper,dest,steps);
    cout<<"Step "<<i++<<" -> "<<"Move Disk '"<<n<<"' from "+src+" to "+dest<<endl;
    steps.push_back(make_pair(n,make_pair(src,dest)));
    TOH(n-1,helper,dest,src,steps);
}

int main(){
    int number_of_disks;
    cin>>number_of_disks;
    vector<pair<int,pair<string,string>>> steps;
    TOH(number_of_disks,"Source","Destination","Helper",steps);
    for(int j=0;j<steps.size();j++){
        cout<<"Move Disk '"<<steps[j].first<<"' from "+steps[j].second.first+" to "+steps[j].second.second<<endl;
    }
}
