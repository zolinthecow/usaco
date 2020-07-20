#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define pb push_back
#define INF 252645135
#define LSOne(S) (S & (-S))

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const ll MOD = 1e9 + 7;

const ll mxN = 1e5 + 5;
const ll add = 1e4;

ll N;
ii points[mxN];

int xOrder[mxN], yOrder[mxN];

map<ll, vi> sameX, sameY;

ll up[mxN];
ll down[mxN];

ll xSum[mxN];
ll ySum[mxN];

bool sortX(int a, int b) {
	return points[a].first < points[b].first;
}

bool sortY(int a, int b) {
	return points[a].second < points[b].second;
}

void sumXCoord(ll x) {
	vi on = sameX[x];
	up[on.size() - 1] = 0;
	for (ll i = on.size() - 2; i >= 0; i--) {
		up[i] = up[i + 1] + (on.size() - i - 1) * (points[on[i + 1]].second - points[on[i]].second);
	}
	down[0] = 0;
	for (ll i = 1; i < (ll) on.size(); i++) {
		down[i] = down[i - 1] + i * (points[on[i]].second - points[on[i - 1]].second);
	}
	for (ll i = 0; i < (ll) on.size(); i++) {
		xSum[on[i]] = up[i] + down[i];
	}
}

void sumYCoord(ll y) {
	vi on = sameY[y];
	up[on.size() - 1] = 0;
	for (ll i = on.size() - 2; i >= 0; i--) {
		up[i] = up[i + 1] + (on.size() - i - 1) * (points[on[i + 1]].first - points[on[i]].first);
	}
	down[0] = 0;
	for (ll i = 1; i < (ll) on.size(); i++) {
		down[i] = down[i - 1] + i * (points[on[i]].first - points[on[i - 1]].first);
	}
	for (ll i = 0; i < (ll) on.size(); i++) {
		ySum[on[i]] = up[i] + down[i];
	}
}

int main() {
	setIO("triangles");
	cin >> N;
	for (ll i = 0; i < N; i++) {
		cin >> points[i].first >> points[i].second;
		points[i].first += add, points[i].second += add;
		xOrder[i] = i;
		yOrder[i] = i;
	}
	sort(xOrder, xOrder + N, sortY);
	for (ll i = 0; i < N; i++) {
		sameX[points[xOrder[i]].first].pb(xOrder[i]);
	}
	for (auto it : sameX) {
		sumXCoord(it.first);
	}
	sort(yOrder, yOrder + N, sortX);
	for (ll i = 0; i < N; i++) {
		sameY[points[yOrder[i]].second].pb(yOrder[i]);
	}
	for (auto it : sameY) {
		sumYCoord(it.first);
	}
	ll ans = 0;
	for (ll i = 0; i < N; i++) {
		ans += (xSum[i] % MOD) * (ySum[i] % MOD);
		ans %= MOD;
	}
	cout << ans << endl;
}
