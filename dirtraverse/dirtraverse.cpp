#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define pb push_back
#define LSOne(S) (S & (-S))
#define INF 1e9;

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int mxN = 1e5 + 5;

int N;

int files[mxN];
vi adjList[mxN];

int numLeaves[mxN];

int down[mxN];
int up[mxN];

int totalLeaves = 0;

inline bool isLeaf(int on) { return adjList[on].size() == 0; }

int dfs1(int on, int p = -1) {
	if (isLeaf(on)) {
		totalLeaves++;
		return 1;
	}
	int sum = 0;
	for (auto it : adjList[on]) {
		if (it == p) continue;
		sum += dfs1(it, on);
	}
	numLeaves[on] = sum;
	return sum;
}

int dfs2(int on, int p = -1) {
	int sum = 0;
	for (auto it : adjList[on]) {
		if (it == p) continue;
		if (isLeaf(it)) sum += files[it];
		else            sum += (files[it] + 1) * numLeaves[it];
		sum += dfs2(it, on);
	}
	down[on] = sum;
	return sum;
}

void dfs3(int on, int p = -1) {
	if (on != 1) up[on] = (down[p] - down[on] - numLeaves[on] * (files[on] + 1)) + up[p] + 
		(totalLeaves - numLeaves[on]) * 3;
	for (auto it : adjList[on]) {
		if (it == p) continue;
		dfs3(it, on);
	}	
}

int main() {
	setIO("dirtraverse");
	cin >> N;
	string name; int numChildren, child;
	for (int i = 1; i <= N; i++) {
		cin >> name >> numChildren;
		files[i] = name.length();
		for (int j = 0; j < numChildren; j++) {
			cin >> child;
			adjList[i].pb(child);
			//adjList[child].pb(i);
		}
	}
	dfs1(1);
	dfs2(1);
	dfs3(1);
	int ans = INF;
	for (int i = 1; i <= N; i++) {
		if (!isLeaf(i)) ans = min(ans, up[i] + down[i]);
	}
	cout << ans << endl;
}
