#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using ii = pair<ll, ll>;
using vii = vector<ii>;

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()

#define mp make_pair

#define LSOne(S) (S & (-S))

const ll INF = 1061109567;

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin); 
    freopen((name+".out").c_str(), "w", stdout);
}

const ll mxN = 1e3 + 5, mult = 1e6;

ll N, M;
vi adjList[mxN];
ll cost[mxN][mxN];
ll flow[mxN][mxN];

ll dist[mxN];

vi allFlows;

ll dij(ll minFlow) {
	memset(dist, 0xFFF, sizeof(dist));
	for (ll i = 0; i < mxN; i++) dist[i] = INF;
	dist[1] = 0;
	priority_queue< ii, vii, greater<ii> > pq; pq.push(ii(0, 1));
	while (sz(pq)) {
		ii front = pq.top(); pq.pop();
		ll d = front.first, u = front.second;
		if (d > dist[u]) continue;
		for (auto v : adjList[u]) {
			if (dist[u] + cost[u][v] < dist[v] && flow[u][v] >= minFlow) {
				dist[v] = dist[u] + cost[u][v];
				pq.push(ii(dist[v], v));
			}
		}
	}
	return dist[N];
}

int main () {
    setIO("pump");	
	cin >> N >> M;
	ll a, b, c, d;
	for (ll i = 0; i < M; i++) {
		cin >> a >> b >> c >> d;
		adjList[a].pb(b);
		adjList[b].pb(a);
		cost[a][b] = c;
		cost[b][a] = c;
		flow[a][b] = d;
		flow[b][a] = d;
		allFlows.pb(d);
	}
	ll bestFlow = 0, bestCost = 1, curFlow, curCost;
	for (auto f : allFlows) {
		curFlow = f;
		curCost = dij(f);
		//curCost = dijkstra(1, N, f);
		//cout << f << ": " << curCost << '\n';
		if (curCost != -1 && curFlow * bestCost > bestFlow * curCost) {
			bestFlow = curFlow, bestCost = curCost;
		}
	}
	cout << bestFlow * mult / bestCost << '\n';
}
