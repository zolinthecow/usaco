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
	//freopen((s + ".out").c_str(), "w", stdout);
}

int dr[5] = {0, 0, -1, 0, 1};
int dc[5] = {0, -1, 0, 1, 0};


struct state {
	int ax, ay, ad, bx, by, bd;
	vector<state> boi;
	vector<state>* next = &boi;
	void fillNext() {
		next -> pb(state {ax, ay, (ad + 3) % 4, bx, by, (bd + 3) % 4} );
		next -> pb(state {ax, ay, (ad + 1) % 4, bx, by, (bd + 1) % 4} );
		next -> pb(state {ax + dr[ad], bx + dc[ad], ad, bx + dr[bd], by + dc[bd], bd} );
	}
};

const int mxN = 25;
int N;
char grid[mxN][mxN];

int dp[mxN][mxN][5][mxN][mxN][5];

int main() {
	setIO("cownav");
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}
	state init = {0, 0, 1, 0, 0, 2};
	queue<state> q; q.push(init);
	while (q.size()) {
		state u = q.top(); q.pop();
		u.fillNext();
		for (auto it : *(u.next)) {
			if (dp[u.ax][u.ay][u.ad][u.bx][u.by][u.bd] == 0) {
				
			}
		}
	}
	
}
