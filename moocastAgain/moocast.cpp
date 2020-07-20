#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define ii pair<ll, ll>
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

struct edge{
	int a, b;
	int dist;
};

const int mxN = 1e3 + 5;

int N;
ii coords[mxN];

vector< edge > edges;

bool edgeSort(edge a, edge b) {
	return a.dist < b.dist;
}

inline int sqDist(ii a, ii b) {
	return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}
	
int main() {
	setIO("moocast");
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> coords[i].first >> coords[i].second;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			edges.pb(edge{i, j, sqDist(coords[i], coords[j])});
		}
	}
	sort(edges.begin(), edges.end(), edgeSort);
	UnionFind UF(N);
	int i = 0;
	while(UF.numDisjointSets() != 1) {
		if (!UF.isSameSet(edges[i].a, edges[i].b)) {
			UF.unionSet(edges[i].a, edges[i].b);
		}
		i++;
	}
	cout << edges[i].dist << endl;
}
