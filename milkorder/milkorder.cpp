#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define pb push_back
#define LSOne(S) (S & (-S))

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	//freopen((s + ".out").c_str(), "w", stdout);
}

const int mxN = 1e5 + 5, mxM = 5e4 + 5;

int N, M;
vi obs[mxM];

vi adjList[mxN];

int in[mxN];

vi ts;

bool top1() {
	queue<int> q;
	memset(in, 0, sizeof(in));
	for (int i = 1; i <= N; i++) {
		for (auto v : adjList[i]) {
			in[v]++;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (in[i] == 0) q.push(i);
	}
	int cnt = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		ts.pb(u);
		for (auto v : adjList[u]) {
			if (--in[v] == 0) {
				q.push(v);
			}
		}
		cnt++;
	}
	if (cnt == 0) return false;
	return cnt != N;
}

inline int bin() {
	int mid;
	int low = 0, up = M;
	while (low < up - 1) {
		mid = low + (up - low) / 2;
		ts.clear();
		for (int i = 0; i < N; i++) adjList[i].clear();
		for (int i = 0; i < mid; i++) {
			for (int j = 0; j < (int) obs[i].size() - 1; j++) {
				adjList[obs[i][j]].pb(obs[i][j + 1]);
			}
		}
		if (!top1()) 
			low = mid;
		else
			up = mid;
	}
	ts.clear();
	for (int i = 0; i < N; i++) adjList[i].clear();
	for (int i = 0; i < low; i++) {
		for (int j = 0; j < (int) obs[i].size() - 1; j++) {
			adjList[obs[i][j]].pb(obs[i][j + 1]);
		}
	}
	if (!top1()) return low;
	else return up;
}

void top2() {
	memset(in, 0, sizeof(in));
	for (int i = 1; i <= N; i++) {
		for (auto v : adjList[i]) {
			in[v]++;
		}
	}
	multiset<int> s;
	for (int i = 1; i <= N; i++) {
		if (in[i] == 0) s.insert(i);
	}
	while (!s.empty()) {
		int u = *s.begin();
		s.erase(s.begin());
		ts.pb(u);
		for (auto v : adjList[u]) {
			if (--in[v] == 0) {
				s.insert(v);
			}
		}
	}
}

int main() {
	setIO("milkorder");
	cin >> N >> M;
	int mi, a;
	for (int i = 0; i < M; i++) {
		cin >> mi;
		for (int j = 0; j < mi; j++) {
			cin >> a;
			obs[i].pb(a);
		}
	}
	int X = bin();
	ts.clear();
	for (int i = 0; i < N; i++) adjList[i].clear();
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < (int) obs[i].size() - 1; j++) {
			adjList[obs[i][j]].pb(obs[i][j + 1]);
		}
	}
	top2();
	for (int i = 0; i < N; i++) {
		cout << ts[i];
		if (i != N - 1) cout << " ";
	}
	cout << endl;
}
