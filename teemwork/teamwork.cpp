#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define pb push_back
#define INF 2000000000
#define LSOne(S) (S & (-S))

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int mxN = 1e4 + 5, mxK = 1e3 + 5;

int N, K;
int skill[mxN];

int pref[mxN][mxK];
int mxRow[mxN];
int dp[mxN][mxK];

int main() {
	setIO("teamwork");
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> skill[i];
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= K && i - j >= 0; j++) 
			pref[i][j] = max(skill[i], pref[i - 1][j - 1]);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K && i - j >= 0; j++) {
			dp[i][j] = mxRow[i - j] + pref[i][j] * j;
			mxRow[i] = max(mxRow[i], dp[i][j]);
		}
	}
	cout << mxRow[N] << endl;
}
