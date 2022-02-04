#include<bits/stdc++.h>
using namespace std ;
using ll = long long ;

bool check_function(vector<int> &v) {
    for(auto &i : v) {
        if(i & 1) return 0 ;
        i >>= 1;
    }
    return 1;
}

int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0) ;

    int n; cin >> n;
    vector<int> a(n) ;
    for(auto &i : a) cin >> i ;
    int ans = 0;

    // this lambda, and the function above are equivalent
    auto check_lambda = [&](auto &v) {
        for(auto &i : v) { // access by reference, &i is necessary
                            // because the values of the vectors are being updated
            if(i & 1) return false ; // equivalent to if(i % 2 == 1) 
            i >>= 1; // equivalent to i = i / 2 ;
        }
        return true;
    };
    while(check_lambda(a)) { // or while(check_function(a))
        ++ ans ;
    }
    cout << ans ;

    return 0 ;
}