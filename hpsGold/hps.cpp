#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define pb push_back
#define INF 2000000000
#define line pair<int, bool>
#define LSOne(S) (S & (-S))

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int mxN = 1e5 + 5, mxK = 25;

int N, K;
int moves[mxN]; //0 = H, 1 = P, 2 = S

int dp[mxN][mxK][3];

int win(int on, int move) {
	int fj = moves[on];
	return (int) (fj == 0 && move == 1) || (fj == 1 && move == 2) || (fj == 2 && move == 0);
}

int main() {
	setIO("hps");
	cin >> N >> K;
	char move;
	for (int i = 1; i <= N; i++) {
		cin >> move;
		if      (move == 'H') moves[i] = 0;
		else if (move == 'P') moves[i] = 1;
		else if (move == 'S') moves[i] = 2;
	}
	for (int i = 1; i <=N; i++) {
		for (int j = 0; j <= K; j++) {
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					if (j != 0 || k == l) {
						dp[i][j][k] = max(dp[i - 1][(k == l) ? j : j - 1][l] +  win(i, l), 
							dp[i][j][k]);
					}
				}
			}
		}
	}
	cout << max(dp[N][K][0], max(dp[N][K][1], dp[N][K][2])) << endl;
}
