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

const int mxN = 1e5 + 5;

struct path {
	int a, b, want;
	
	//path(int a, int b, int want) {
		//this.a = a;
		//this.b = b;
		//this.want = want;
	//}
	
	bool operator==(const path &p) const
	{
		return a == p.a && b == p.b && want == p.want;
	}
};


struct hash_fn
{
	size_t operator() (const path &a) const
	{
		size_t h1 = hash<int>()(a.a);
		size_t h2 = hash<int>()(a.b);
		size_t h3 = hash<int>()(a.want);
		return h1 ^ h2 ^ h3;
	} 
};

struct DSU {
	vi e; void init(int N) { e = vi(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};

int N, M;
int num[mxN];
vi adjList[mxN];
path paths[mxN];

DSU d;
vi queries[mxN];
int ancestor[mxN];
bool visited[mxN];

map<ii, int> lcas;

//bool visited[mxN];

//int timer = 0, tin[mxN], tout[mxN];
//int anc[mxN][18];

//void dfs1() {
    //stack<ii> st; st.push(ii(1, 1));
    //visited[1] = true;
    //int cont = false;
    //while (!st.empty()) {
		//ii top = st.top();
		//int u = top.first, p = top.second;
		//visited[u] = true;
		//cont = false;
		//if (!tin[u]) {
			//tin[u] = ++timer;
			//anc[u][0] = p;
			//for (int i = 1; i < 18; i++)
				//anc[u][i] = anc[anc[u][i - 1]][i - 1];
		//}
		//for (auto v : adjList[u]) {
			//if (!visited[v]) {
				//st.push(ii(v, u));
				//cont = true;
				//break;
			//}
		//}
		//if (!cont) {
			//tout[u] = ++timer;
			//st.pop();
		//}
	//}
//}

//bool is_anc(int u, int v) {
	//return tin[u] <= tin[v] && tout[u] >= tout[v];
//}

//int lca(int u, int v) {
    //if (is_anc(u, v))
		//return u;
	//if (is_anc(v, u)) 
		//return v;
	//for (int i = 17; i >= 0; i--) {
		//if (!is_anc(anc[u][i], v))
			//u = anc[u][i];
	//}
	//return anc[u][0];
//}

void dfs1(int u) {
	visited[u] = true;
	ancestor[u] = u;
	for (auto v : adjList[u]) {
		if (!visited[v]) {
			dfs1(v);
			d.unite(u, v);
			ancestor[d.get(u)] = u;
		}
	}
	for (auto v : queries[u]) {
		if (visited[v]) {
			lcas[ii(u, v)] = ancestor[d.get(v)];
			lcas[ii(v, u)] = ancestor[d.get(v)];
		}
	}
}

vector<path> endOn[mxN];
vector<path> lcaOn[mxN];

unordered_map<path, vi, hash_fn> order;

unordered_map<path, vi, hash_fn> vals;

int seen[mxN];

void dfs2(int u, int p = -1) {
	seen[num[u]]++;
	for (auto pathOn : endOn[u]) {
		vals[pathOn].pb(seen[pathOn.want]);
	}
	for (auto v : adjList[u]) {
		if (v == p) continue;
		dfs2(v, u);
	}
	for (auto pathOn : lcaOn[u]) {
		vals[pathOn].pb(seen[pathOn.want]);
		vals[pathOn].pb(num[u] == pathOn.want ? 1 : 0);
	}
	seen[num[u]]--;
}

int ans[mxN];

int main () {
    setIO("milkvisits");	
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> num[i];
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		adjList[a].pb(b);
		adjList[b].pb(a);
	}
	for (int i = 0; i < M; i++) {
		cin >> paths[i].a >> paths[i].b >> paths[i].want;
		endOn[paths[i].a].pb(paths[i]);
		endOn[paths[i].b].pb(paths[i]);
		queries[paths[i].a].pb(paths[i].b);
		queries[paths[i].b].pb(paths[i].a);
		order[paths[i]].pb(i);
	}
	d.init(N + 5);
	dfs1(1);
	for (int i = 0; i < M; i++) {
		lcaOn[lcas[ii(paths[i].a, paths[i].b)]].pb(paths[i]);
	}
	dfs2(1);
	//for (auto i : vals) {
		//cout << i.first.a << ' ' << i.first.b << ' ' << i.first.want << ": ";
		//for (auto j : i.second) {
			//cout << j << ' ';
		//}
		//cout << '\n';
	//}
	for (auto pathOn : order) {
		vi curVi = vals[pathOn.first];
		int curAns = curVi[0] + curVi[1] - 2 * curVi[2] + curVi[3];
		for (auto index : pathOn.second) {
			ans[index] = (int) (curAns >= 1);
		}
	}
	for (int i = 0; i < M; i++) {
		cout << ans[i];
	}
	cout << '\n';
}
