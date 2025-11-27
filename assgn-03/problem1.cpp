#include<bits/stdc++.h>
using namespace std;
 
long long int dp[1005][1005][12], n, m, x, a[1005], b[1005];
 
int countPossibilities(){
	sort(a, a + n);
	sort(b, b + m);
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			dp[i][j][0] = 1;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			for(int k = 1; k <= x; k++){
			    dp[i][j][k] = (dp[i - 1][j][k] + dp[i][j - 1][k] - dp[i - 1][j - 1][k] + 1000000009) % 1000000009;
				if(a[i - 1] > b[j - 1]){
					dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][k - 1]) % 1000000009;
				}
			}
		}
	}
	return dp[n][m][x];
}
 
int main(){
	cin >> n >> m >> x;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < m; i++){
		cin >> b[i];
	}
	int ans = countPossibilities();
	cout << ans << endl;
}