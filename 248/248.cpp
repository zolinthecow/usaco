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

const int mxN = 248;

int N;
int nums[mxN];

int dp[mxN][mxN];

int main() {
	setIO("248");
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	int ans = 0;
	for (int len = 1; len <= N; len++) {
		for (int i = 0; i + len <= N; i++) {
			int j = i + len - 1;
			if (len == 1) { 
				dp[i][j] = nums[i];
				continue;
			}
			for (int k = i; k < j; k++) {
				if (dp[i][k] == dp[k + 1][j] && dp[i][k] != 0) {
					dp[i][j] = max(dp[i][j], dp[i][k] + 1);
				}
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
}
