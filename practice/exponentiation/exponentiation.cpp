#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define mp make_pair

#define LSOne(S) (S & (-S))

const int INF = 1061109567;

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin); 
    //freopen((name+".out").c_str(), "w", stdout);
}

const ll MOD = 1e9 + 7;

int N;

// divide 2 is left shift, if you take off a 0 dont need to mulitply, so just store whatever x^(2^whatever) is, if its a 1
// then you need to mulitply it so multiply it
ll binpow(ll x, ll n, ll m) {
    assert(n >= 0);
    x %= m; //note: m*m must be less than 2^63 to avoid ll overflow
    ll res = 1;
    while (n > 0) {
        if (n % 2 == 1) //if n is odd
            res = res * x % m;
        x = x * x % m;
        n /= 2; //divide by two
        cout << n << " " << res << " " << x << "\n";
    }
    cout << "\n";
    return res;
}

int main () {
    setIO("exponentiation");	
    cin >> N;
    ll a, b;
    while (N--) {
        cin >> a >> b;
        cout << binpow(a, b, MOD) << "\n";
    }
}
