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

const ll mxN = 1e5 + 5;

ll N;
int stalls[mxN];

ll sumNSq(ll n) {
	return (n * (n + 1) * (2 * n + 1)) / 6;
}

int main() {
	setIO("cbarn");
	cin >> N;
	ll cows = 0;
	for (ll i = 0; i < N; i++) {
		cin >> stalls[i];
		cows = max(0ll, cows + stalls[i] - 1);
	}
	for (ll i = 0; ; i++) {
		if (cows == 0) {
			rotate(stalls, stalls + i, stalls + N);
			break;
		}
		cows = max(0ll, cows + stalls[i] - 1);
	}
	ll ans = 0;
	for (ll i = 0; i < N; i++) {
		ans += sumNSq(cows + stalls[i] - 1) - sumNSq(cows - 1);
		cows = max(0ll, cows + stalls[i] - 1);
	}
	cout << ans << endl;
}
