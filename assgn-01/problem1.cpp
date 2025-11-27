#include <bits/stdc++.h>
using namespace std;

set<pair<long long, long long>> coordinatesx, coordinatesy, s1, s2, s3, s4;
set<pair<long long, long long>>::iterator it;
long long n, maximum = 0;

long long findArea() {
    long long minx = LLONG_MAX, miny = LLONG_MAX, maxx = LLONG_MIN, maxy = LLONG_MIN;
    long long ans = LLONG_MAX, minx1, miny1, maxx1, maxy1;

    for (it = coordinatesx.begin(); it != coordinatesx.end(); ++it) {
        auto [x, y] = *it;
        minx = min(minx, x); miny = min(miny, y);
        maxx = max(maxx, x); maxy = max(maxy, y);

        s1.erase({x, y}); s2.erase({y, x});
        if (s1.empty()) break;

        minx1 = s1.begin()->first;  miny1 = s2.begin()->first;
        maxx1 = s1.rbegin()->first; maxy1 = s2.rbegin()->first;

        maximum = max(maximum, (maxx1 - minx) * (max(maxy1, maxy) - min(miny1, miny)));
        if (maxx != minx1)
            ans = min(ans, (maxx - minx)*(maxy - miny) + (maxx1 - minx1)*(maxy1 - miny1));
    }

    minx = miny = LLONG_MAX; maxx = maxy = LLONG_MIN;
    for (it = coordinatesy.begin(); it != coordinatesy.end(); ++it) {
        auto [y, x] = *it;
        minx = min(minx, x); miny = min(miny, y);
        maxx = max(maxx, x); maxy = max(maxy, y);

        s3.erase({y, x}); s4.erase({x, y});
        if (s3.empty()) break;

        miny1 = s3.begin()->first;  minx1 = s4.begin()->first;
        maxy1 = s3.rbegin()->first; maxx1 = s4.rbegin()->first;

        maximum = max(maximum, (maxx1 - minx) * (max(maxy1, maxy) - min(miny1, miny)));
        if (maxy != miny1)
            ans = min(ans, (maxx - minx)*(maxy - miny) + (maxx1 - minx1)*(maxy1 - miny1));
    }
    return ans;
}

int main() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        coordinatesx.insert({x, y});
        coordinatesy.insert({y, x});
        s1.insert({x, y});
        s2.insert({y, x});
        s3.insert({y, x});
        s4.insert({x, y});
    }
    cout << maximum - findArea() << endl;
}
