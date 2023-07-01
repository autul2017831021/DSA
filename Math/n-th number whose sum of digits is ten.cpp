// Logic Lonk : https://www.geeksforgeeks.org/n-th-number-whose-sum-of-digits-is-ten

#include <bits/stdc++.h>
using namespace std;

int digitSum(int n){
    int ans = 0;
    while(n){
        ans += n%10;
        n = n/10;
    }
    return ans;
}

int findNth(int n)
{
	int count = 0;

	for (int curr = 19;; curr += 9) {
		int sum = 0;
		sum = digitSum(curr);
		if (sum == 10)
			count++;
		if (count == n)
			return curr;
	}
	return -1;
}

int main()
{
    int n;
    cin>>n;
	cout<<findNth(n);
	return 0;
}
