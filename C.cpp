#include<bits/stdc++.h>
using namespace std ;
using ll = long long ;

int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0) ;

    string t, p;
    cin >> t >> p ;
    int n = t.size() ;
    vector<int> a(n) ;
    for(auto &i: a) cin >> i ;

    auto check = [&](auto mid) {
        vector<bool> ignore(n) ;
        for(int i = 0 ; i <= mid ; ++i) {
            ignore[a[i] - 1] = 1 ; // a[i] - 1 is necessary because we are considering 0-based indexing
                                    // and we are given 1-based indexing in the input
        }
        int i = 0, j = 0;
        // `i` points to the first position of `t`
        // `j` points to the first position of `p`
        while(i < n && j < (int)p.size()) {
            // increase the pointer of `p` if and only if t[i] is equal to p[j]
            // and we should not ignore t[i]
            if(!ignore[i] && t[i] == p[j]) ++j ;
            ++ i ; // we will always increase the pointer of `t`, i.e. `i`
        }
        return j == (int)p.size() ;
    };

    int l = 0, r = n - 1 ;
    while(l <= r) {
        int mid = l + r >> 1 ;
        if(check(mid)) l = mid + 1 ;
        else r = mid - 1 ;
    }

    cout << l ;

    return 0 ;

}
