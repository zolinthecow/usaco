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

const int mxN = 10;

int N, K;
vi adjList[mxN];
vi paths[mxN];

bool visited[mxN];

int timer = 0, tin[mxN], tout[mxN];
int anc[mxN][18];

void dfs1() {
    stack<ii> st; st.push(ii(1, 1));
    visited[1] = true;
    int cont = false;
    while (!st.empty()) {
		ii top = st.top();
		int u = top.first, p = top.second;
		visited[u] = true;
		cont = false;
		if (!tin[u]) {
			tin[u] = ++timer;
			anc[u][0] = p;
			for (int i = 1; i < 18; i++)
				anc[u][i] = anc[anc[u][i - 1]][i - 1];
		}
		for (auto v : adjList[u]) {
			if (!visited[v]) {
				st.push(ii(v, u));
				cont = true;
				break;
			}
		}
		if (!cont) {
			tout[u] = ++timer;
			st.pop();
		}
	}
}

bool is_anc(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_anc(u, v))
		return u;
	if (is_anc(v, u)) 
		return v;
	for (int i = 17; i >= 0; i--) {
		if (!is_anc(anc[u][i], v))
			u = anc[u][i];
	}
	return anc[u][0];
}

int pickUp[mxN];

int num[mxN];

map<ii, int> endpt;

int enduh[mxN];

int ans = 0;

void dfs2(int u, int p = -1) {
	for (auto v : paths[u]) {
		if (endpt.find(ii(min(u, v), max(u, v))) == endpt.end()) {
			endpt[ii(min(u, v), max(u, v))] = v;
		}
		enduh[v]++;
	}
	for (auto v : adjList[u]) {
		if (v == p) continue;
		dfs2(v, u);
	}
}

void dfs3(int u, int p, int numHave) {
	numHave += pickUp[u];
	ans = max(ans, numHave);
	numHave -= enduh[u];
	for (auto v : adjList[u]) {
		if (v == p) continue;
		dfs3(v, u, numHave);
	}
}

int main () {
    setIO("maxflow");	
	cin >> N >> K;
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		adjList[a].pb(b);
		adjList[b].pb(a);
	}
	dfs1();
	int lcaOn;
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		lcaOn = lca(a, b);
		pickUp[lcaOn]++;
		if (lcaOn != a && lcaOn != b) {
			enduh[a]++;
			enduh[b]++;
		} else if (lcaOn == a) {
			enduh[b]++;
		} else {
			enduh[a]++;
		}
	}
	//dfs2(1);
	dfs3(1, -1, 0);
	cout << ans << '\n';
}
