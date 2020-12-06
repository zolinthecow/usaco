#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define mp make_pair

#define LSOne(S) (S & (-S))

const int INF = 1061109567;

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin); 
    //freopen((name+".out").c_str(), "w", stdout);
}

const int mxN = 1e2 + 5, mxK = 7 + 5;

int N, K;
int cows[mxN];

int cst[mxN][mxN];

int dp[mxK][mxN];

int main () {
    setIO("cbarn2");	
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> cows[i];
	int adjJ;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= i + N; j++) {
			adjJ = j > N ? j - N : j;
			cst[i][adjJ] = cst[i][adjJ - 1] + (j - i) * cows[adjJ];
		}
	}
	for (int i = 1; i <= N; i++) {
		memset(dp, 0x3F, sizeof(dp));
		dp[1][1] = cst[1 + i - 1][(N + i - 1) > N ? i - 1 : N + i - 1];
		for (int k = 2; k <= K; k++) {
			for (int j = 1; j <= N; j++) {
				for (int a = 1; a < j; j++) {
					dp[k][j] = min(dp[k][j], dp[k - 1][a] + 
						cst[a + i - 1 > N ? a + i - 1 - N : a + i - 1][
				}
			}
		}
	}
}
