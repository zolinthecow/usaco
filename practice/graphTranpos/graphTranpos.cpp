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

struct node {
	int first, second, transpose;
};

bool comp(node a, node b) {
	return a.first < b.first;
}

const int mxN = 2e5 + 5;
const int MOD = 998244353;

int N, M;
vi adjList[mxN];
unordered_set<int> origDirec[mxN];

int dist[mxN];

void dij() {
	for (int i = 0; i < mxN; i++) dist[i] = INF;
	dist[1] = 0;
	priority_queue< node, vector<node>, function<bool(node, node)> > pq(comp);
	pq.push(node{0, 1, 0});
	while (!pq.empty()) {
		node front = pq.top(); pq.pop();
		int d = front.first, u = front.second, transpose = front.transpose;
		if (d > dist[u]) continue;
		for (auto v : adjList[u]) {
			int cst, newTranspose;
			if (origDirec[u].find(v) != origDirec[u].end()) {
				//if in original direction and need to transpose it back
				if (transpose % 2 == 1) {
					newTranspose = transpose + 1;
					cst = pow(2, transpose) + 1;
					cst %= MOD;
				} else {
					newTranspose = transpose;
					cst = 1;
				}
			} else {
				//if not in original direction and need to traspose it
				if (transpose % 2 == 0) {
					newTranspose = transpose + 1;
					cst = pow(2, transpose) + 1;
					cst %= MOD;
				} else {
					newTranspose = transpose;
					cst = 1;
				}
			}
			if (dist[u] + cst < dist[v]) {
				dist[v] = dist[u] + cst;
				dist[v] %= MOD;
				pq.push(node{dist[v], v, newTranspose});
			}
		}
	}
}

int main () {
    //setIO("graphTranpos");	
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		adjList[a].pb(b);
		adjList[b].pb(a);
		origDirec[a].insert(b);
	}
	dij();
	cout << dist[N] % MOD << '\n';
}
