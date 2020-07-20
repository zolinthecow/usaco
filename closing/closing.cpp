#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define pb push_back
#define INF 2000000000

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

const int mxN = 2e5 + 5;
const int mxM = 2e5 + 5;

int N, M;
vector< vi > adjList;
int rm[mxN];

string res[mxN];
int seen[mxN];

int main() {
	setIO("closing");
	cin >> N >> M;
	adjList.resize(N);
	UnionFind UF(N);
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		a--; b--;
		adjList[a].pb(b);
		adjList[b].pb(a);
	}
	for (int i = 0; i < N; i++) {
		cin >> rm[i];
		rm[i]--;
	}
	for (int i = N - 1; i >= 0; i--) {
		seen[rm[i]] = 1;
		for (auto it : adjList[rm[i]]) {
			if (seen[it]) UF.unionSet(rm[i], it);
		}
		if (UF.numDisjointSets() - i == 1) res[i] = "YES";
		else                               res[i] = "NO";
	}
	for (int i = 0; i < N; i++) {
		cout << res[i] << endl;
	}
}
