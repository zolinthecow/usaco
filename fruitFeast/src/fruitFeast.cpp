#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ii pair<ll, ll>
#define dd pair<double, double>
#define vi vector<ll>
#define vd vector<double>
#define vii vector<ii>
#define vdd vector<dd>
#define vs vector<string>
#define ll long long
#define INF 10000000
#define MOD 10000000
#define LSOne(S) (S & (-S))

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int dp[5000000][2];

int main() {
	setIO("feast");
	int T, A, B;
	cin >> T >> A >> B;
	dp[0][0] = 1;
	for (int i = 0; i <= T; i++) {
		if (i - A >= 0) {
			if (dp[i - A][0]) dp[i][0] = 1;
		}
		if (i - B >= 0) {
			if (dp[i - B][0]) dp[i][0] = 1;
		}
	}
	for (int i = 0; i <= T; i++) {
		if (i * 2 <= T) {
			if (dp[i * 2][0]) dp[i][1] = 1;
		}
	}
	for (int i = 0; i <= T; i++) {
		if (i - A >= 0) {
			if (dp[i - A][1]) dp[i][1] = 1;
		}
		if (i - B >= 0) {
			if (dp[i - B][1]) dp[i][1] = 1;
		}
	}
	int ans = 0;
	for (int i = 0; i <= T; i++) {
		if (dp[i][0] || dp[i][1]) ans = i;
	}
	cout << ans << endl;
}
