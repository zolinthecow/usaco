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

struct node{
	int r;
	int c;
	int from;
	bool smell;

	node(int r, int c, int from, bool smell) :
		r(r), c(c), from(from), smell(smell) {
	}

	int pack() {
		return smell + (smell ? 4 : 0) + from  + c * 10 + r * 10000;
	}

	static node unpack(int x) {
		return node(x / 10000, (x / 10) % 1000, (x % 10) % 5, (x % 10) / 5);
	}
};

int dp[10000000];
int grid[1000][1000];

int mr[4] = {0, 0, 1, -1};
int mc[4] = {1, -1, 0, 0};

int N, M;

int val(int r, int c) {
	if (r >= 0 && r < N && c >= 0 && c < M) return grid[r][c];
	return 0;
}

int direc(node on, int r, int c) {
	int oR = on.r, oC = on.c;
	if 		(r == oR + 1) return 2;
	else if (r == oR - 1) return 1;
	else if (c == oC + 1) return 4;
	else				  return 3;
}

ii to(node on) {
	int direc = on.from;
	int r = on.r, c = on.c;
	if (direc == 1)      r -= 1;
	else if (direc == 2) r += 1;
	else if (direc == 3) c  -= 1;
	else				 c += 1;
	return ii(r,c);
}

vector<node> calcTo(node on) {
	vector<node> ans;
	int r = on.r, c = on.c;
	int toR, toC, from, cellVal;
	bool smell;
	bool cont = false;
	if (grid[r][c] == 4) {
		ii t = to(on);
		cellVal = val(t.first, t.second);
		if (cellVal == 0 || cellVal == 3) cont = true;
		else {
			toR = t.first, toC = t.second;
			from = (cellVal == 4) ? on.from : 0;
			smell = (cellVal == 2);
			ans.pb(node(toR, toC, from, smell));
		}
	}
	if (grid[r][c] != 4 || cont) {
		for (int i = 0; i < 4; i++) {
			toR = r + mr[i], toC = c + mc[i];
			cellVal = val(toR, toC);
			if (!cellVal || (cellVal == 3 && !on.smell)) continue;
			smell = (cellVal == 2) | on.smell;
			if (cellVal == 4) {
				//u = 1, d = 2, l = 3, r = 4
				from = direc(on, toR, toC);
				smell = 0;
			} else {
				from = 0;
			}
			ans.pb(node(toR, toC, from, smell));
		}
	}
	return ans;
}

int main() {
	setIO("dream");
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> grid[i][j];
		}
	}
	for (int i = 0; i < 10000000; i++) dp[i] = -1;
	dp[0] = 0;
	queue<int> q;
	q.push(node(0,0,0,0).pack());
	while (!q.empty()) {
		node on = node::unpack(q.front()); q.pop();
		if (on.r == N - 1 && on.c == M - 1) {
			cout << dp[on.pack()] << "\n";
			return 0;
		}
		if (on.r == 0 && on.c == 3) {
			int h = 0;
		}
		vector<node> adj = calcTo(on);
		for (auto v : adj) {
			if (dp[v.pack()] != -1) continue;
			dp[v.pack()] = dp[on.pack()] + 1;
			q.push(v.pack());
		}
	}
	cout << -1 << "\n";
}
