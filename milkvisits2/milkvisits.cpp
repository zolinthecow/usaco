#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define pb push_back
#define INF 2000000000
#define LSOne(S) (S & (-S))
#define tup tuple<int, int, int>
#define f get<0>
#define sec get<1>
#define th get<2>
#define trav(a,x) for (auto& a: x)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
namespace FastIO {
	const int BSZ = 1<<15; ////// INPUT
	char ibuf[BSZ]; int ipos, ilen;
	char nc() { // next char
		if (ipos == ilen) {
			ipos = 0; ilen = fread(ibuf,1,BSZ,stdin);
			if (!ilen) return EOF;
		}
		return ibuf[ipos++];
	}
	void rs(string& x) { // read str
		char ch; while (isspace(ch = nc()));
		do { x += ch; } while (!isspace(ch = nc()) && ch != EOF);
	}
	template<class T> void ri(T& x) { // read int or ll
		char ch; int sgn = 1;
		while (!isdigit(ch = nc())) if (ch == '-') sgn *= -1;
		x = ch-'0'; while (isdigit(ch = nc())) x = x*10+(ch-'0');
		x *= sgn;
	}
	template<class T, class... Ts> void ri(T& t, Ts&... ts) { 
		ri(t); ri(ts...); } // read ints
	////// OUTPUT (call initO() at start)
	char obuf[BSZ], numBuf[100]; int opos;
	void flushOut() { fwrite(obuf,1,opos,stdout); opos = 0; }
	void wc(char c) { // write char
		if (opos == BSZ) flushOut();
		obuf[opos++] = c; }
	void ws(string s) { trav(c,s) wc(c); } // write str
	template<class T> void wi(T x, char after = '\0') { /// write int
		if (x < 0) wc('-'), x *= -1;
		int len = 0; for (;x>=10;x/=10) numBuf[len++] = '0'+(x%10);
		wc('0'+x); R0F(i,len) wc(numBuf[i]);
		if (after) wc(after);
	}
	void initO() { assert(atexit(flushOut) == 0); } /// auto-flush output
}

using namespace FastIO;

void setIO(string st) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((st + ".in").c_str(), "r", stdin);
	freopen((st + ".out").c_str(), "w", stdout);
}

const int mxN = 1e5 + 5;

int N, M;
int milk[mxN];
vi adjList[mxN];

unordered_set<int> lcas;
vector<tup> needs[mxN];
int lcaPos[mxN];

bool visited[mxN];

bool works[mxN];

vi seen;

int timer = 0, tin[mxN], tout[mxN];
int anc[mxN][18];

void dfs1(/*int node = 1, int parent = 1*/) {
	//tin[node] = ++timer;
    //anc[node][0] = parent;
    //for (int i = 1; i < 18; i++)
        //anc[node][i] = anc[anc[node][i - 1]][i - 1];

    //for (int i : adjList[node]) if (i != parent) dfs1(i, node);
    //tout[node] = ++timer;
    fill(begin(visited), end(visited), false);
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

void dfs2(/*int on = 1, int p = -1*/) {
	//seen.pb(milk[on]);
	//if (lcas.find(on) != lcas.end()) lcaPos[on] = seen.size() - 1;
	//for (auto it : needs[on]) {
		//if (find(seen.begin() + lcaPos[f(it)], seen.end(), t(it)) != seen.end())
			//works[s(it)] = true;
	//}
	//for (auto v : adjList[on]) {
		//if (v == p) continue;
		//dfs2(v, on);
	//}
	//seen.pop_back();
	
	fill(begin(visited), end(visited), false);
	stack<int> st; st.push(1);
	int cont = false;
	while (!st.empty()) {
		int u = st.top();
		if (!visited[u]) {
			visited[u] = true;
			seen.pb(milk[u]);
			if (lcas.find(u) != lcas.end()) lcaPos[u] = seen.size() - 1;
			for (auto it : needs[u]) 
				if (find(seen.begin() + lcaPos[f(it)], seen.end(), th(it)) != seen.end())
					works[sec(it)] = true;
		}
		cont = false;
		for (auto v : adjList[u]) {
			if (!visited[v]) {
				cont = true;
				st.push(v);
				break;
			}
		}
		if (!cont) {
			st.pop();
			seen.pop_back();
		}
	}
}

int main() {
	//setIO("milkvisits");
	initO();
	ri(N, M);
	for (int i = 1; i <= N; i++) ri(milk[i]);
	int a, b, c;
	for (int i = 0; i < N - 1; i++) {
		ri(a, b);
		adjList[a].pb(b);
		adjList[b].pb(a);
	}
	dfs1();
	int l;
	for (int i = 0; i < M; i++) {
		ri(a, b, c);
		l = lca(a, b);
		lcas.insert(l);
		needs[a].pb(tup(l, i, c)); needs[b].pb(tup(l, i, c));
	}
	dfs2();
	for (int i = 0; i < M; i++) {
		wi((int) works[i]);
	}
	wi('\n');
}
