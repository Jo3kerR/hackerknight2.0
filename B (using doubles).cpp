#include<bits/stdc++.h>
using namespace std ;
using ll = long long ;

ll max_dist(vector<int> &v) {
    if(v.empty()) return 0 ;
    sort(v.begin(), v.end()) ;
    int d = v.back() - v[0] ;
    return d * 1ll * d ;
}

int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0) ;

    int n; cin >> n ;
    // x0 is for points which lie on y-axis, i.e. x = 0
    // y0 is for points which lie on x-axis, i.e. y = 0
    vector<int> x0, y0 ;
    vector<pair<int, int>> points ; // this vector stores all the points
    map<long double, vector<pair<int,int>>> m; // this map stores [`s`, points with slope = `s`]
    bool flag = false ; // true if (0, 0) is present, false otherwise
    for(int i = 0 ; i < n ; ++i) {
        int X, Y; cin >> X >> Y ;
        points.push_back({X, Y});
        if(X == 0) x0.push_back(Y);
        if(Y == 0) y0.push_back(X);
        if(X && Y) {
            // make sure to convert `Y` or `X` to floating point integer otherwise
            // it will result in integer division
            // for example, 5 / 2 = 2, but 5 * 1.0L / 2 = 2.5 because
            // 5 is converted to 5.0 and then 5.0 is divided by 2
            m[Y * 1.0l / X].push_back({X, Y});
        }
        if(X == 0 && Y == 0) flag = 1;
    }
    ll ans = 0;
    if(flag) { // case when one of the points lie on (0, 0)
        for(auto [x,y] : points) {
            ans = max(ans, x * 1LL * x + y * 1LL * y);
            // muliplying with 1LL is necessary to convert `x` and `y` 
            // from `int` to `long long`, otherwise this value may 
            // overflow and you will get incorrect results.

            // Instead of doing this, one can also take `x` and `y` to be
            // `long long` from the beginning, then this type conversion is not needed.
        }
    }
    for(auto &[i, j] : m) { 
        // i denotes the slope
        // j denotes the vector of points with this slope
        sort(j.begin(), j.end());
        int X = j.back().first - j[0].first ;
        int Y = j.back().second - j[0].second ;
        ans = max(ans, X * 1LL * X + Y * 1LL * Y);
    }
    ans = max(ans, max_dist(x0)) ;
    ans = max(ans, max_dist(y0)) ;
    // if `ans` is `0`, that means no pair of points found with the same slope
    if(ans == 0) ans = -1 ;
    cout << ans ;

    return 0 ;
}
