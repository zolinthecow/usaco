#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define pb push_back
#define INF 1061109567
#define LSOne(S) (S & (-S))

void setIO(string st) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((st + ".in").c_str(), "r", stdin);
	freopen((st + ".out").c_str(), "w", stdout);
}

const int mxN = 1e5 + 5, mxM = 26 + 5;

int N, M, K;
int S[mxN];
int dist[mxM][mxM];

int pref[mxN][mxM];
int minRow[mxN];

int dp[mxN][mxM];

void floyd() {
	for (int k = 1; k <= M; k++) {
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= M; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main() {
	setIO("cowmbat");
	cin >> N >> M >> K;
	char a;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		S[i] = (int) (a - 96);
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> dist[i][j];
		}
	}
	floyd();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			pref[i][j] = pref[i - 1][j] + dist[S[i]][j];
		}
	}
	memset(dp, 0x3F, sizeof(dp));
	memset(minRow, 0x3F, sizeof(minRow));
	minRow[0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + dist[S[i]][j]);
			if (i >= K) dp[i][j] = min(dp[i][j], minRow[i - K] + pref[i][j] - pref[i - K][j]);
			minRow[i] = min(minRow[i], dp[i][j]);
		}
	}
	cout << minRow[N] << endl;
}
