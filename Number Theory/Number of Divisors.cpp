#include<bits/stdc++.h>
using namespace std;
const int sizee=10000000;
long long nod[sizee+1];
void NOD(long long N)
{
    for(long long i=1;i<=N;i++)nod[i]=1;
    for(long long i=2;i<=N;i++){
        for(long long j=i;j<=N;j=j+i){
            nod[j]++;
        }
    }
}
int main()
{
    NOD(sizee);
    while(1)
    {
        long long n;cin>>n;
        if(n){
            printf("Number of Divisors of %lld is %lld\n",n,nod[n]);
        }
        else{break;}
    }
}
