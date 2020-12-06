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

const int mxN = 2e1 + 5;

struct state {
	int ax, ay, ad, bx, by, bd;
};

int N;
bool grid[mxN][mxN];

int dp[mxN][mxN][4][mxN][mxN][4];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool inBounds(int a, int b, int d) {
	return a + dr[d] >= 1 && a + dr[d] <= N && b + dc[d] >= 1 && b + dc[d] <= N;
}

vector<state> trans(state u) {
	vector<state> ret;
	ret.pb(state{u.ax, u.ay, (u.ad + 1) % 4, u.bx, u.by, (u.bd + 1) % 4});
	ret.pb(state{u.ax, u.ay, (u.ad + 3) % 4, u.bx, u.by, (u.bd + 3) % 4});
	state forward;
	if (inBounds(u.ax, u.ay, u.ad) && grid[u.ax + dr[u.ad]][u.ay + dc[u.ad]])
		forward.ax = u.ax + dr[u.ad], forward.ay = u.ay + dc[u.ad], forward.ad = u.ad;
	else
		forward.ax = u.ax, forward.ay = u.ay, forward.ad = u.ad;
	if (inBounds(u.bx, u.by, u.bd) && grid[u.bx + dc[u.bd]][u.by + dc[u.bd]])
		forward.bx = u.bx + dr[u.bd], forward.by = u.by + dc[u.bd], forward.bd = u.bd;
	else
		forward.bx = u.bx, forward.by = u.by, forward.bd = u.bd;
	ret.pb(forward);
	return ret;
}

int main () {
    setIO("cownav");	
	cin >> N;
	char a;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> a;
			grid[i][j] = (a == 'E');
		}
	}
	queue<state> q; q.push(state{N, 1, 0, N, 1, 1});
	while (sz(q)) {
		state u = q.front(); q.pop();
		for (auto v : trans(u)) {
			if (dp[v.ax][v.ay][v.ad][v.bx][v.by][v.bd] == 0) {
				dp[v.ax][v.ay][v.ad][v.bx][v.by][v.bd] = dp[u.ax][u.ay][u.ad][u.bx][u.by][u.bd] + 1;
				q.push(v);
				if (v.ax == 0 && v.ay == N && v.bx == 0 && v.by == N) {
					cout << dp[v.ax][v.ay][v.ad][v.bx][v.by][v.bd] << '\n';
					return 0;
				}
			}
		}
	}
}
