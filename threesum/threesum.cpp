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

const ll mxN = 53;

ll N, Q;
ll A[mxN + 1];

inline ll numTwoSums(ll goal, ll pos) {
	unordered_multiset<ll> hash;
	ll ans = 0;
	for (ll i = 1; i < pos; i++) {
		ans += hash.count(goal - A[i]);
		hash.insert(A[i]);
	}
	return ans;
}

ll dp[mxN + 1];

int main () {
	setIO("threesum");
	cin >> N >> Q;
	for (ll i = 1; i <= N; i++) cin >> A[i];
	for (ll i = 1; i <= N; i++) {
		dp[i] = dp[i - 1] + numTwoSums(-A[i], i);
	}
	ll a, b;
	while (Q--) {
		cin >> a >> b;
		cout << dp[b] - dp[a - 1] << endl;
	}
}
