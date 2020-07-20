#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define pb push_back
#define INF 2000000000
#define LSOne(S) (S & (-S))

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

const int mxN = 1e5 + 5, mxQ = 1e5 + 5;

int N, Q;

struct adjSort {
	bool operator() (const int& a, const int& b) const {
		return a > b;
	}
};

map<int, vii, adjSort> adjList;
ii queries[mxQ];

int qOrder[mxQ];

bool qSort(int a, int b) { return queries[a].first > queries[b].first; }

int ans[mxQ];

int main() {
	setIO("mootube");
	cin >> N >> Q;
	int a, b, c;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> c;
		adjList[c].pb(ii(a, b));
	}
	for (int i = 0; i < Q; i++) {
		cin >> queries[i].first >> queries[i].second;
		qOrder[i] = i;
	}
	sort(qOrder, qOrder + Q, qSort);
	UnionFind UF(N + 1);
	for (int i = 0; i < Q; i++) {
		ii q = queries[qOrder[i]];
		while (adjList.size() > 0) {
			map<int, vii, adjSort>::iterator it = adjList.begin();
			if ((*it).first < q.first) break;
			for (auto edge : (*it).second) {
				UF.unionSet(edge.first, edge.second);
			}
			adjList.erase(it);
		}
		ans[qOrder[i]] = UF.sizeOfSet(q.second) - 1;
	}
	for (int i = 0; i < Q; i++) {
		cout << ans[i] << endl;
	}
}
