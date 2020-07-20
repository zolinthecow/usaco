#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define iii pair<int, ii>;
#define pb push_back
#define INF 2000000000
#define line pair<int, bool>
#define LSOne(S) (S & (-S))

typedef tuple< ll, ll, ll > tuple_t;

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int dr[16] = {0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 0, -1, 1};
int dc[16] = {3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 2, 1, -1, 0, 0};

const int mxN = 1e3 + 5;
const int mxT = 1e6 + 5;

int N, T;
int grid[mxN][mxN];

int dist[mxN][mxN];

int main() {
	setIO("visitfj");
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}
	memset(dist, 0xF, sizeof(dist));
	dist[0][0] = 0;
	priority_queue< tuple_t, vector<tuple_t>, greater<tuple_t> > pq; pq.push(tuple_t(0, 0, 0));
	int ans = INF;
	while (!pq.empty()) {
		tuple_t front = pq.top(); pq.pop();
		int d = get<0>(front); 
		ii u = ii(get<1>(front), get<2>(front));
		if (d > dist[u.first][u.second]) continue;
		int dis = abs(N - 1 - u.first) + abs(N - 1 - u.second);
		if (dis <= 2) 
			ans = min(ans, dist[u.first][u.second] + dis * T);
		for (int j = 0; j < 16; j++) {
			int vr = u.first + dr[j], vc = u.second + dc[j];
			if (vr >= 0 && vr < N && vc >= 0 && vc < N && dist[u.first][u.second] + T * 3 + 
				grid[vr][vc] < dist[vr][vc]) {
				
				dist[vr][vc] = dist[u.first][u.second] + T * 3 + grid[vr][vc];
				pq.push(tuple_t(dist[vr][vc], vr, vc));	
			}
		}
	}
	cout << ans << endl;
}
