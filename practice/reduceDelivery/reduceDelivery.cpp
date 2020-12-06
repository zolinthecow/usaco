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

const int mxN = 1e3 + 5;

int N, M, K;

vii adjList[mxN];
ii paths[mxN];

ii edges[mxN];

int dist[mxN][mxN];

void dij(int s) {
	dist[s][s] = 0;
	priority_queue< ii, vii, greater<ii> > pq; pq.push(ii(0, s));
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if (d > dist[s][u]) continue;
		for (auto v : adjList[u]) {
			if (dist[s][u] + v.second < dist[s][v.first]) {
				dist[s][v.first] = dist[s][u] + v.second;
				pq.push(ii(dist[s][v.first], v.first));
			}
		}
	}
}

int main () {
    //setIO("reduceDelivery");	
	cin >> N >> M >> K;
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		adjList[a].pb(ii(b, c));
		adjList[b].pb(ii(a, c));
		edges[i] = ii(a, b);
	}
	//memset(dist, 0xFFF, sizeof(dist));
	for (int i = 0; i < mxN; i++) for (int j = 0; j < mxN; j++) dist[i][j] = INF;
	
	for (int i = 1; i <= N; i++) dij(i);
	
	//for (int i = 1; i <= N; i++) {
		//cout << i << ": ";
		//for (int j = 1; j <= N; j++) {
			//cout << dist[i][j] << ", ";
		//}
		//cout << "\n";
	//}
	
	for (int i = 0; i < K; i++) {
		cin >> paths[i].first >> paths[i].second;
	}
	
	int ans = INF, cur;
	for (int i = 0; i < M; i++) {
		cur = 0;
		for (int j = 0; j < K; j++) {
			cur += min(dist[paths[j].first][paths[j].second], min(dist[paths[j].first][edges[i].first] + 
				dist[edges[i].second][paths[j].second], dist[paths[j].first][edges[i].second] +
				dist[edges[i].first][paths[j].second]));
		}
		ans = min(ans, cur);
	}
	cout << ans << "\n";
}
