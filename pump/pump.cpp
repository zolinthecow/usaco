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
	freopen((s + ".out").c_str(), "w", stdout);
}

const int mult = 1e6;

const int mxN = 1e3 + 5;

int N, M;
vii adjList[mxN];
int flow[mxN][mxN];

int dist[mxN];
int p[mxN];

vi path;

void findPath(int on) {
	if (p[on] == -1) return;
	findPath(p[on]);
	path.pb(on);
}

void dij(int minFlow) {
	fill(begin(p), end(p), -1);
	fill(begin(dist), end(dist), INF); dist[1] = 0;
	priority_queue< ii, vii, greater<ii> > pq; pq.push(ii(0, 1));
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int d = front.first, u= front.second;
		if (d > dist[u]) continue;
		for (auto v : adjList[u]) {
			if (dist[u] + v.second < dist[v.first] && flow[u][v.first] >= minFlow) {
				dist[v.first] = dist[u] + v.second;
				p[v.first] = u;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
}

int main() {
	setIO("pump");
	cin >> N >> M;
	int a, b, c, d;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c >> d;
		adjList[a].pb(ii(b, c));
		adjList[b].pb(ii(a, c));
		flow[a][b] = d, flow[b][a] = d;
	}
	int ans = 0, minF = INF;
	for (int f = 1; f <= 1000; f++) {
		dij(f);
		if (dist[N] != INF) {
			path.clear(); path.pb(1);
			findPath(N);
			minF = INF;
			for (int i = 0; i < (int) path.size() - 1; i++) 
				minF = min(minF, flow[path[i]][path[i + 1]]);
			ans = max(ans, (int) (((float) minF / dist[N]) * mult));
		}
	}
	cout << ans << endl;
}
