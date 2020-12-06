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

ll N;

vector<int> factor(ll n) {
    vector<int> ret;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret.push_back(i);
            n /= i;
        }
    }
    return ret;
}

inline int calc(int x) {
    return (-1 + sqrt(1 + 8 * x)) / 2;
}

int main () {
    setIO("divgame");	
    cin >> N;
    vi f = factor(N);
    for (auto it : f) cout << it << " ";
    cout << "\n";
}
