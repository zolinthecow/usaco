#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define pb push_back
#define INF 2000000000

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const ll mxN = 1e2 + 5;
const ll mxK = 7 + 5;

ll N, K;
ll cows[mxN];

ll dp[mxN][mxK][mxN];

int main() {
	//setIO("cbarn2");
	cin >> N >> K;
	for (ll i = 0; i < N; i++) {
		cin >> cows[i];
	}
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j <= K; j++) {
			for (ll k = 0; k < N; k++) {
				dp[i][j][k] = INF;
			}
		}
		dp[i][0][N] = 0;
	}
	for (ll i = 0; i < N; i++) {
		for (ll j = 1; j <= K; j++) {
			for (ll k = 0; k < N; k++) {
				ll val = 0;
				for (ll l = k + 1; l <= N; l++) {
					val += cows[l - 1] * (l - k - 1);
					dp[i][j][k] = min(dp[i][j][k], dp[i][j - 1][l] + val); 
				}
			}
		}
		rotate(cows, cows + 1, cows + N);
	}
	ll ans = INF;
	for (ll i = 0; i < N; i++) {
		ans = min(ans, dp[i][K][0]);
	}
	cout << ans << endl;
}
