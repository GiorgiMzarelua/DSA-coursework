#include<bits/stdc++.h>
using namespace std;
 
int n, m, arr[40005], dp[40005];
 
set<pair<int, int> > dishIndex;
set<pair<int, int> > indexDish;
set<pair<int, int> > :: iterator it;
 
int minimalTime(){
	dp[0] = 1;
	for(int i = 0; i < n; i++){
		pair<int, int> p = make_pair(arr[i], 0);
		set<pair<int, int> > :: iterator itt = dishIndex.lower_bound(p);
		pair<int, int> P = *itt;
		if(P.first == p.first){
			dishIndex.erase(*itt);
			indexDish.erase({P.second, P.first});
			dishIndex.insert({arr[i], i});
		    indexDish.insert({i, arr[i]});
		}	
		else if(dishIndex.size() < 200){
			dishIndex.insert({arr[i], i});
		    indexDish.insert({i, arr[i]});
		}
		else{
		    itt = indexDish.begin();
		    p = *itt;
		    indexDish.erase(*itt);
		    dishIndex.erase({p.second, p.first});
		    dishIndex.insert({arr[i], i});
		    indexDish.insert({i, arr[i]});
		}
		if(i != 0) dp[i] = dp[i - 1] + 1;
		int j = 1;
		for(it = indexDish.begin(); it != indexDish.end(); it++){
			int k = (indexDish.size() - j) * (indexDish.size() - j);
			p = *it;
			dp[i] = min(dp[i], dp[p.first] + k);
			j++;
		}
	}
	return dp[n - 1];
}
 
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int ans = minimalTime();
	cout << ans << endl;
}