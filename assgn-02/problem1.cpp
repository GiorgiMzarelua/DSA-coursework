#include<bits/stdc++.h>
using namespace std;
 
int tree[400005], lazy[400005], n, k, qType;
 
void push(int left, int right, int index){
	if(lazy[index] % 2 == 0) return;
	int avg = (left + right) / 2;
	tree[2 * index] = avg - left + 1 - tree[2 * index];
	tree[2 * index + 1] = right - avg - tree[2 * index + 1];
	lazy[2 * index] += lazy[index];
	lazy[2 * index + 1] += lazy[index];
	lazy[index] = 0;
}
 
int getSum(int start, int finish, int left, int right, int index){
	if(right < start) return 0;
	if(left > finish) return 0;
	if(left >= start && right <= finish) return tree[index];
	push(left, right, index);
	int avg = (left + right) / 2;
	return getSum(start, finish, avg + 1, right, 2 * index + 1) + getSum(start, finish, left, avg, 2 * index); 
}
 
void update_range(int start, int finish, int left, int right, int index){
	if(left > finish || right < start) return;
	if(left >= start && right <= finish) {
		tree[index] = right - left + 1 - tree[index];
		lazy[index] += 1;
		return; 
	}
	int avg = (left + right) / 2;
	push(left, right, index);
	update_range(start, finish, left, avg, 2 * index);
	update_range(start, finish, avg + 1, right, 2 * index + 1);
    tree[index] = tree[index * 2 + 1] + tree[index * 2];
}
 
int main(){
	cin >> n >> k;
	for(int i = 0; i < k; i++){
		cin >> qType;
		if(qType == 0){
			int left, right;
			cin >> left >> right;
			update_range(left, right, 1, n, 1);
		}
		else{
			int left, right;
			cin >> left >> right;
			int ans = getSum(left, right, 1, n, 1);
			cout << ans << endl;
		}
	}
}