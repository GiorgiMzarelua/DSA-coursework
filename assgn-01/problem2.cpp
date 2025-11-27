#include<bits/stdc++.h>
using namespace std;
 
int nums[60005], n, minPrime;
long long int dp[60005];
 
void eratos(){
	for(int i = 2; i <= 60000; i++){
		if(nums[i] == 0){
			for(int j = i * 2; j <= 60000; j += i){
				nums[j] = 1;
			}
		}
	}
}
 
int SUM(int n){
	eratos();
	minPrime = n + 1;
	while(nums[minPrime] != 0) minPrime++;
	for(int prime = 2; prime <= n; prime++){
		if(nums[prime] == 0){
			for(int i = prime; i <= n; i++){
				dp[i] = dp[i] + dp[i - prime];
				dp[i] = dp[i] % minPrime;
			}
		}
	}
	return dp[n];
}
 
int main() {
    cin >> n;
   	nums[0] = 1;
	nums[1] = 1;
    dp[0] = 1;
    int ans = SUM(n);
    if(nums[n] == 1) cout << ans % minPrime << endl;
	else cout << (ans + minPrime - 1) % minPrime << endl;
}