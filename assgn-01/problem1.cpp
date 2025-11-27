#include<bits/stdc++.h>

using namespace std;

set<pair<long long, long long> > coordinatesx, coordinatesy, s1, s2, s3, s4;
set<pair<long long, long long> > :: iterator it;
long long n, maximum;

long long findArea(){
long long minx = LLONG_MAX;
long long miny = LLONG_MAX;
long long maxx = LLONG_MIN;
long long maxy = LLONG_MIN;
long long ans = LLONG_MAX;
long long minx1 = LLONG_MAX;
long long miny1 = LLONG_MAX;
long long maxx1 = LLONG_MIN;
long long maxy1 = LLONG_MIN;
for(it = coordinatesx.begin(); it != coordinatesx.end(); ++it){
pair<long long, long long> it1 = *it;
minx = min(minx, it1.first);
miny = min(miny, it1.second);
maxx = max(maxx, it1.first);
maxy = max(maxy, it1.second);
pair<long long, long long> helper;
helper.first = it1.second;
helper.second = it1.first;
s1.erase(it1);
s2.erase(helper);
if(s1.size() == 0) break;
pair<long long, long long> p = *s1.begin();
    minx1 = p.first;
p = *s2.begin();
    miny1 = p.first;
p = *s1.rbegin();
maxx1 = p.first;
p = *s2.rbegin();
maxy1 = p.first;
maximum = max(maximum, ((maxx1 - minx) * ((max(maxy1, maxy)) - (min(miny1, miny)))));
if(maxx == minx1) continue;
        ans = min(ans, (((maxx - minx) * (maxy - miny)) + ((maxx1 - minx1) * (maxy1 - miny1))));
}
minx = LLONG_MAX;
miny = LLONG_MAX;
maxx = LLONG_MIN;
maxy = LLONG_MIN;
minx1 = LLONG_MAX;
miny1 = LLONG_MAX;
maxx1 = LLONG_MIN;
maxy1 = LLONG_MIN;
for(it = coordinatesy.begin(); it != coordinatesy.end(); ++it){
pair<long long, long long> it1 = *it;
minx = min(minx, it1.second);
miny = min(miny, it1.first);
maxx = max(maxx, it1.second);
maxy = max(maxy, it1.first);
pair<long long, long long> helper;
helper.first = it1.second;
helper.second = it1.first;
s3.erase(it1);
s4.erase(helper);
if(s3.size() == 0) break;
pair<long long, long long> p = *s3.begin();
    miny1 = p.first;
p = *s4.begin();
    minx1 = p.first;
p = *s3.rbegin();
maxy1 = p.first;
p = *s4.rbegin();
maxx1 = p.first;
maximum = max(maximum, ((maxx1 - minx) * ((max(maxy1, maxy)) - (min(miny1, miny)))));
if(maxy == miny1) continue;
ans = min(ans, (((maxx - minx) * (maxy - miny)) + ((maxx1 - minx1) * (maxy1 - miny1))));
}
return ans;
}

int main() {
cin >> n;
for(long long i = 0; i < n; i++){
long long x, y;
cin >> x >> y;
coordinatesx.insert(make_pair(x, y));
coordinatesy.insert(make_pair(y, x));
s1.insert(make_pair(x, y));
s2.insert(make_pair(y, x));
s4.insert(make_pair(x, y));
s3.insert(make_pair(y, x));
}
long long ans = findArea();
cout << maximum - ans << endl;
}
