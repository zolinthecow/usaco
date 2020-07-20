#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define pb push_back
#define INF 2000000000
#define LSOne(S) (S & (-S))

typedef tuple< ll, ll, ll, ll > tupe;

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

const int mxN = 1e3 + 5;
const int mxT = 1e6 + 5;

int N, T;
int grid[mxN][mxN];

int dist[mxN][mxN];

int main() {
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}
	queue<tupe> q; q.push(tupe(0, 0, 0, 0));
	int ans = INF;

}
