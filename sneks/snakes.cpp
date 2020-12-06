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
	//freopen((s + ".out").c_str(), "w", stdout);
}

const int mxN = 4e2 + 5;

int N, K;
int snakes[mxN];

int groupSize[mxN];
int mxRange[mxN][mxN];

int dp[mxN][mxN];

int main() {
	setIO("snakes");
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> snakes[i];
		groupSize[i] = groupSize[i - 1] + snakes[i];
		for (int j = 1; j <= i; j++) {
			mxRange[j][i] = max(mxRange[j][i - 1], snakes[i]);
		}
	}
	for (int i = 1; i <= N; i++) mxRange[0][i] = max(mxRange[0][i - 1], snakes[i]);
	fill(&dp[0][0], &dp[N][K], INF);
	dp[0][0] = 0;
	//for (int i = 0; i <= K + 1; i++) dp[0][i] = 0, dp[i][0] = 0;	
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K + 1; j++) {
			for (int amt = 1; amt <= i; amt++) {
				dp[i][j] = min(dp[i][j], dp[i - amt][j - 1] + amt * mxRange[i - amt][i] - groupSize[i]
					+ groupSize[i - amt]);
			}
		} 
	}
	cout << dp[N][K] << endl;
}
