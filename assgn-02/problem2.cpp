#include<bits/stdc++.h>
using namespace std;
 
struct node{
	int maxZeroLength;
	int maxPrefix;
	int maxSuffix;
	bool allUpdated;
	bool allEqual;
};
 
node tree[2000005];
 
int n, m, qType;
 
void build(int start, int end, int index){
	if(start == end){
		tree[index].maxZeroLength = 1;
		tree[index].maxPrefix = 1;
		tree[index].maxSuffix = 1;
		tree[index].allUpdated = false;
		tree[index].allEqual = false;
		return;
	}
	int middle = (start + end) / 2;
	build(start, middle, 2 * index);
	build(middle + 1, end, 2 * index + 1);
	tree[index].maxZeroLength = end - start + 1;
	tree[index].maxPrefix = end - start + 1;
	tree[index].maxSuffix = end - start + 1;
	tree[index].allUpdated = false;
	tree[index].allEqual = false;
}
 
void helper(int left, int right, int index){
    	if(tree[index].allUpdated == true){
    		if (left != right) {
    			tree[index * 2].allUpdated = true;
				tree[index * 2 + 1].allUpdated = true;
				tree[index * 2].allEqual = tree[index].allEqual;
				tree[index * 2 + 1].allEqual = tree[index].allEqual;
			}
			tree[index].allUpdated = false;
			if(tree[index].allEqual == true){
				tree[index].maxZeroLength = 0;
			    tree[index].maxPrefix = 0;
			    tree[index].maxSuffix = 0;
			}
			else{
				tree[index].maxZeroLength = right - left + 1;
		        tree[index].maxPrefix = right - left + 1;
		        tree[index].maxSuffix = right - left + 1;
			}
		}
}
 
int findFirstEmptySegment(int left, int right, int index, int segmentLength){
	helper(left, right, index);
	if(tree[index].maxZeroLength < segmentLength) return 0;
	if(left == right) return right;
	int middle = (left + right) / 2;
	helper(left, middle, index * 2);
	helper(middle + 1, right, index * 2 + 1);
	if(tree[index * 2].maxZeroLength >= segmentLength) return findFirstEmptySegment(left, middle, 2 * index, segmentLength);
	if(tree[index * 2].maxSuffix + tree[index * 2 + 1].maxPrefix >= segmentLength)  return middle - tree[index * 2].maxSuffix + 1;
	return findFirstEmptySegment(middle + 1, right, 2 * index + 1, segmentLength);
}
 
void update(int left, int right, int leftBorder, int rightBorder, int index, bool equal){
	helper(left, right, index);
	if(leftBorder > right || rightBorder < left || left > right) return;
	if(left >= leftBorder && right <= rightBorder){
		tree[index].allUpdated = true;
        tree[index].allEqual = equal;
        helper(left, right, index);
        return;
	}
	int middle = (left + right) / 2;
	update(left, middle, leftBorder, rightBorder, 2 * index, equal);
	update(middle + 1, right, leftBorder, rightBorder, 2 * index + 1, equal);
    tree[index].maxZeroLength = tree[2 * index].maxZeroLength;
    if (tree[2 * index + 1].maxZeroLength > tree[index].maxZeroLength) tree[index].maxZeroLength = tree[2 * index + 1].maxZeroLength;
    int c = tree[2 * index].maxSuffix + tree[2 * index + 1].maxPrefix;
    if (c > tree[index].maxZeroLength) tree[index].maxZeroLength = c;
    if (tree[2 * index].maxPrefix == middle - left + 1) tree[index].maxPrefix = tree[2 * index].maxPrefix + tree[2 * index + 1].maxPrefix;
    else tree[index].maxPrefix = tree[2 * index].maxPrefix;
    if (tree[2 * index + 1].maxSuffix == right - middle) tree[index].maxSuffix = tree[2 * index + 1].maxSuffix + tree[2 * index].maxSuffix;
	else tree[index].maxSuffix = tree[2 * index + 1].maxSuffix;
}
 
int main(){
	cin >> n >> m;
	build(1, n, 1);	
	for(int i = 0; i < m; i++){
		cin >> qType;
		if(qType == 1){
			int p;
			cin >> p;
			int ans = findFirstEmptySegment(1, n, 1, p);
			cout << ans << endl;
			if(ans != 0) update(1, n, ans, ans + p - 1, 1, true);
		}
		else{
			int start, num;
			cin >> start >> num;
			update(1, n, start, start + num - 1, 1, false);
		}
	}
}