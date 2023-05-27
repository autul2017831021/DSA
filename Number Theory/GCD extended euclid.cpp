// C++ program to demonstrate working of
// extended Euclidean Algorithm
#include <iostream>
using namespace std;
#define de cout<<
#define nl printf("\n")
#define sp printf(" ")
int gcdExtended(int a, int b, int *x, int *y)
{
	if (a == 0)
	{
		*x = 0;
		*y = 1;
		return b;
	}

	int x1, y1;
	int gcd = gcdExtended(b%a, a, &x1, &y1);
	*x = y1 - (b/a) * x1;
	*y = x1;

	return gcd;
}

int main()
{
	int x,y,a,b;
	cin>>a>>b;
	int g = gcdExtended(a, b, &x, &y);
	cout<<"("<<x<<"*"<<a<<") + "<<"("<<y<<"*"<<b<<") = "<<g<<endl;
	return 0;
}

// This code is contributed by TusharSabhani
