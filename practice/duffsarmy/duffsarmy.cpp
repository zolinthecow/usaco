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

const int mxN = 1e5 + 5;

int N, M, Q;
vi adjList[mxN];
set<int> people[mxN];

bool visited[mxN];

int timer = 0, tin[mxN], tout[mxN];
int anc[mxN][18];

int par[mxN];

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

void dfs2(int on = 1, int p = -1) {
    par[on] = p;
    for (auto v : adjList[on]) {
        if (v == p) continue;
        dfs2(v, on);
    }
}

set<int> trav(int u, int v, int lca, bool up, set<int> ans, int a) {
    for (auto it : people[u]) {
        ans.insert(it);
        if (sz(ans) >= a) return ans;
    }
    if (u == v) return ans;
    if (up && u == lca) up = false;
    if (up) {
        ans = trav(par[u], v, lca, up, ans, a);
    } else {
        for (auto it : adjList[u]) {
            if (is_anc(it, v)) {
                ans = trav(it, v, lca, up, ans, a);
                break;
            }
        }
    }
    return ans;
}

int main () {
    setIO("duffsarmy");	
    cin >> N >> M >> Q;
    int a, b;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }
    int city;
    for (int i = 1; i <= M; i++) {
        cin >> city;
        people[city].insert(i);
    }
    dfs1();
    dfs2();
    int v, u, to;
    set<int> ans;
    while (Q--) {
        cin >> v >> u >> a;
        to = lca(v, u);
        ans = trav(u, v, to, false, {}, a);
        cout << min(a, sz(ans)) << " ";
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << "\n";
    }
}
