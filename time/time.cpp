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
    freopen((name+".out").c_str(), "w", stdout);
}

const int mxN = 1e3 + 5, mxDays = 1e3;

int N, M, C;
int m[mxN];
vi adjList[mxN];

int dp[mxDays + 1][mxN];

int main () {
	setIO("time");
	cin >> N >> M >> C;
	for (int i = 1; i <= N; i++) cin >> m[i];
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		adjList[b].pb(a);
	} 
	memset(dp, -0x3F, sizeof(dp));
	dp[0][1] = 0;
	for (int i = 1; i <= mxDays; i++) {
		for (int j = 1; j <= N; j++) {
			for (auto v : adjList[j]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][v] + m[j]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= mxDays; i++) {
		ans = max(ans, (int) (dp[i][1] - C * pow(i, 2)));
	}
	cout << ans << endl;
}
