#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[100000];

    int i, j, k;
    long long ans=0, mod=1073741824;
    int n;
    int a, b, c;
    cin>>a>>b>>c;
    int m = a*b*c;

    memset(arr, 0, sizeof(arr));
    for(i = 1; i <= m; i++)
    {
        for(j = i; j <= m; j += i)
            arr[j]++;
    }

    for(i = 1; i <= a; i++)
    {
        for(j = 1; j <= b; j++)
        {
            for(k = 1; k <= c; k++)
            {
                ans += arr[i * j * k];
                ans = ans % mod;
            }
        }
    }

    cout << ans<<endl;

    return 0;
}
