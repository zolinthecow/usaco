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

const int mxN = 2e5 + 5;

int N;

//cost, have, need
int values[mxN][3];
vi adjList[mxN];

int memo[mxN];

int ans[mxN];

//needZero, needOne, haveZero, haveOne
int pref[mxN][4];

void shuffle(int u, int p) {
	pref[u][0] = values[u][2] == 0;
	pref[u][1] = values[u][2] == 1;
	pref[u][2] = values[u][1] == 0;
	pref[u][3] = values[u][1] == 1;
	for (auto v : adjList[u]) {
		if (v == p) continue;
		for (int i = 0; i < 4; i++) {
			pref[u][i] += pref[v][i];
		}
	}
	
}

void dfs1(int u, int p = -1) {
	for (auto v : adjList[u]) {
		if (v == p) continue;
		dfs(v, u);
	}
	shuffle(u, p);
}

void dfs2(int u, int p = -1) {
	//if this node is solved dont shuffle unless children cant be solved then try to shuffle
	int cst = INF;
	if (values[u][1] != values[u][2]) {
		cst = values[u][0] * 
	}
}

int main () {
    setIO("treeShuffle");	
	cin >> N;
	for (int i = 1; i <= N; i++) 
		for (int j = 0; j < 3; j++)
			cin >> values[i][j];
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		adjList[a].pb(b);
		adjList[b].pb(a);
	}
	dfs1(1);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 4; j++) {
			cout << pref[i][j] << " ";
		}
		cout << '\n';
	}
}
