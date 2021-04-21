#include<bits/stdc++.h>
using namespace std;

// Returns minimum x for which a ^ x % m = b % m, a and m are co-prime.
// Complexity : O ( sqrt(m) ) 
// for non co prime check : https://cp-algorithms.com/algebra/discrete-log.html


int solve(int a, int b, int m) {
    a %= m, b %= m;
    int n = sqrt(m) + 1;

    int an = 1;
    for (int i = 0; i < n; ++i)
        an = (an * 1ll * a) % m;

    unordered_map<int, int> vals;
    for (int q = 0, cur = b; q <= n; ++q) {
        vals[cur] = q;
        cur = (cur * 1ll * a) % m;
    }

    for (int p = 1, cur = 1; p <= n; ++p) {
        cur = (cur * 1ll * an) % m;
        if (vals.count(cur)) {
            int ans = n * p - vals[cur];
            return ans;
        }
    }
    return -1;
}



int main()
{
     cout<<solve(2,3,5)<<endl;


    return 0;
}
