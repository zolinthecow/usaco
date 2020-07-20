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

const ll mxN = 1e4 + 5;

ll N, M, T;
ll numCows[mxN];
vii adjList[mxN];

ll par[mxN];
ll dist[mxN];

vi adjList2[mxN];

ll numPassThrough[mxN];

void dij() {
	for (ll i = 0; i < mxN; i++) dist[i] = INF;
	dist[1] = 0;
	priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, 1));
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		ll d = front.first, u = front.second;
		if (d > dist[u]) continue;
		for (auto v : adjList[u]) {
			if (dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				par[v.first] = u;
				pq.push(ii(dist[v.first], v.first));
			} else if (dist[u] + v.second == dist[v.first] && u < par[v.first]) {
				dist[v.first] = dist[u] + v.second;
				par[v.first] = u;
				pq.push(ii(dist[v.first], v.first));
			}
			
		}
	}
}

void dfs(ll on, ll p = -1) {
	ll sum = numCows[on];
	for (auto v : adjList2[on]) {
		if (v == p) continue;
		dfs(v, on);
		sum += numPassThrough[v];
	}
	numPassThrough[on] = sum;
}

int main() {
	setIO("shortcut");
	cin >> N >> M >> T;
	for (ll i = 1; i <= N; i++) cin >> numCows[i];
	ll a, b, c;
	for (ll i = 0; i < M; i++) {
		cin >> a >> b >> c;
		adjList[a].pb(ii(b, c));
		adjList[b].pb(ii(a, c));
	}
	dij();
	for (ll i = 2; i <= N; i++) {
		adjList2[i].pb(par[i]);
		adjList2[par[i]].pb(i);
	}
	dfs(1);
	ll ans = 0;
	for (ll i = 1; i <= N; i++) {
		ans = max(ans, numPassThrough[i] * (dist[i] - T));
	}
	cout << ans << endl;
}
