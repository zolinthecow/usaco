#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define pb push_back
#define INF 2000000000
#define LSOne(S) (S & (-S))

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int mxN = 1e3 + 5;

int N;
int lef[mxN], rite[mxN];

int dp[mxN][mxN];

int main() {
	setIO("nocross");
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> lef[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> rite[i];
	}
	dp[0][0] = (int) (abs(lef[0] - rite[0]) <= 4);
	for (int i = 1; i < N; i++) {
		dp[i][0] = max(dp[i - 1][0], (int) (abs(lef[i] - rite[0]) <= 4));
		dp[0][i] = max(dp[0][i - 1], (int) (abs(lef[0] - rite[i]) <= 4));
	}
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			dp[i][j] = max( max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1] + (int) (abs(lef[i] -
				rite[j]) <= 4));
		}
	}
	cout << dp[N - 1][N - 1] << endl;
}
