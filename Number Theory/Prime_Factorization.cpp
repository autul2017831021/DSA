//#include <bits/stdc++.h>
//using namespace std;
//typedef long long int ll;
//void primeFactors(long long n)
//{
//    map<ll,ll>m;
//    map<ll,ll>::iterator it;
//    cout<<"Prime Factors are: ";
//    while (n%2==0)
//    {
//        cout<<2<<" ";
//        m[2]++;
//        n=n/2;
//    }
//    for (long long i=3;i<=sqrt(n);i=i+2)
//    {
//        // While i divides n, print i and divide n
//        while (n%i==0)
//        {
//            cout<<i<<" ";
//            m[i]++;
//            n=n/i;
//        }
//    }
//    if (n>2)
//    {
//       m[n]++;
//       cout<<n<<" ";
//    }
//    cout<<endl;
//    for(it=m.begin();it!=m.end();it++)
//    {
//        cout<<"("<<(*it).first<<"^"<<(*it).second<<") ";
//    }
//
//}
//int main()
//{
//    cout<<"Enter a 32/64 bit signed/unsigned integer"<<endl;
//    long long n;
//    cin>>n;
//    if(n<0)
//        n=n*-1;
//    primeFactors(n);
//    return 0;
//}


// Optimized Way
// C++ program to find prime factorization of a
// number n in O(Log n) time with precomputation
// allowed.
#include "bits/stdc++.h"
using namespace std;

#define MAXN 10000001

// stores smallest prime factor for every number
int spf[MAXN];

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
	spf[1] = 1;
	for (int i=2; i<MAXN; i++)

		// marking smallest prime factor for every
		// number to be itself.
		spf[i] = i;

	// separately marking spf for every even
	// number as 2
	for (int i=4; i<MAXN; i+=2)
		spf[i] = 2;

	for (int i=3; i*i<MAXN; i++)
	{
		// checking if i is prime
		if (spf[i] == i)
		{
			// marking SPF for all numbers divisible by i
			for (int j=i*i; j<MAXN; j+=i)

				// marking spf[j] if it is not
				// previously marked
				if (spf[j]==j)
					spf[j] = i;
		}
	}
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int x)
{
	vector<int> ret;
	while (x != 1)
	{
		ret.push_back(spf[x]);
		x = x / spf[x];
	}
	return ret;
}

// driver program for above function
int main()
{
	// precalculating Smallest Prime Factor
	sieve();
	int x;
	cin>>x;
	cout << "prime factorization for " << x << " : ";

	// calling getFactorization function
	vector <int> p = getFactorization(x);

	for (int i=0; i<p.size(); i++)
		cout << p[i] << " ";
	cout << endl;
	return 0;
}
