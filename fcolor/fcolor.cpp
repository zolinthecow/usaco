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

const int mxN = 2e5 + 5;

int N, M;
set<int> incoming[mxN];

DSU d;

int ans[mxN], setColor[mxN];
int color = 1;

int main () {
	setIO("fcolor");
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		incoming[b].insert(a);
	}
	d.init(N + 1);
	for (int i = 1; i <= N; i++) {
		for (auto it : incoming[d.get(i)]) {
			d.unite(*(incoming[d.get(i)].begin()), it);
			incoming[d.get(it)].insert(incoming[it].begin(), incoming[it].end());
		}
	}
	for (int i = 1; i <= N; i++) {
		if (setColor[d.get(i)] == 0) {
			ans[i] = color;
			setColor[d.get(i)] = color;
			color++;
		} else {
			ans[i] = setColor[d.get(i)];
		}
	}
	for (int i = 1; i <= N; i++) cout << ans[i] << endl;
}
