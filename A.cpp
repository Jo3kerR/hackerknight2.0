#include<bits/stdc++.h>
using namespace std ;
using ll = long long ;

#define int long long

signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0) ;

    int n; cin >> n ;
    assert(n > 1 && n <= 2e5) ;
    vector<int> x0, y0 ;
    set<pair<int,int>> unique_only ;
    map<long double, vector<pair<int,int>>> m;
    bool flag = 0 ;
    for(int i = 0 ; i < n ; ++i) {
        int X, Y; cin >> X >> Y ;
        assert(-1e6 <= X && X <= 1e6) ;
        assert(-1e6 <= Y && Y <= 1e6) ;
        if(X == 0) x0.push_back(Y);
        if(Y == 0) y0.push_back(X);
        if(X && Y) {
            m[Y * 1.0l / X].push_back({X, Y});
        }
        if(X == 0 && Y == 0) flag = 1;
        unique_only.insert({X, Y});
    }
    assert(unique_only.size() == n);
    ll ans = 0;
    if(flag) {
        for(auto [x,y] : unique_only) {
            ans = max(ans, x * 1ll * x + y * 1ll * y);
        }
    }
    for(auto &[i, j] : m) {
        sort(j.begin(), j.end());
        int X = j.back().first - j[0].first ;
        int Y = j.back().second - j[0].second ;
        ans = max(ans, X * 1ll * X + Y * 1ll * Y);
    }
    if(!x0.empty()) {
        sort(x0.begin(), x0.end()) ;
        int d = x0.back() - x0[0] ;
        ans = max(ans, d * 1ll * d) ;
    }
    if(!y0.empty()) {
        sort(y0.begin(), y0.end()) ;
        int d = y0.back() - y0[0] ;
        ans = max(ans, d * 1ll * d) ;
    }
    if(ans == 0) ans = -1 ;
    cout << ans ;

    return 0 ;
}
