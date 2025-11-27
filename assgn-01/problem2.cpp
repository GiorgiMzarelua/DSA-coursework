#include <bits/stdc++.h>
using namespace std;

int nums[60005], n, minPrime;
long long dp[60005];

int main() {
    cin >> n;
    memset(nums, 0, sizeof(nums));
    nums[0] = nums[1] = 1;
    
    for (int i = 2; i*i <= 60000; i++)
        if (!nums[i])
            for (int j = i*i; j <= 60000; j += i)
                nums[j] = 1;

    minPrime = n + 1;
    while (nums[minPrime]) minPrime++;

    dp[0] = 1;
    for (int p = 2; p <= n; p++) {
        if (!nums[p]) {
            for (int i = p; i <= n; i++) {
                dp[i] = (dp[i] + dp[i-p]) % minPrime;
            }
        }
    }

    if (nums[n]) cout << dp[n] << endl;
    else cout << (dp[n] + minPrime - 1) % minPrime << endl;
}
