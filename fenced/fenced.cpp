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
	//freopen((s + ".out").c_str(), "w", stdout);
}

class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<ll>
  ll numSets;
public:
  UnionFind(ll N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (ll i = 0; i < N; i++) p[i] = i; }
  ll findSet(ll i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(ll i, ll j) { return findSet(i) == findSet(j); }
  void unionSet(ll i, ll j) { 
    if (!isSameSet(i, j)) { numSets--; 
    ll x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  ll numDisjollSets() { return numSets; }
  ll sizeOfSet(ll i) { return setSize[findSet(i)]; }
};

const ll mxN = 2e3 + 5;
const ll mxM = 2e3 + 5;

ll A, B, N, M;

ll vertical[mxN];
ll horizontal[mxM];

vector< pair<ll, ii> > EdgeList;

int main() {
	setIO("fencedin");
	cin >> A >> B >> N >> M;
	vertical[0] = 0;
	for (ll i = 1; i <= N; i++) {
		cin >> vertical[i];
	}
	vertical[N + 1] = A;
	sort(vertical, vertical + N + 1);
	horizontal[0] = 0;
	for (ll i = 1; i <= M; i++) {
		cin >> horizontal[i];
	}
	horizontal[M + 1] = B;
	sort(horizontal, horizontal + M + 1);
	for (ll i = 1; i <= M + 1; i++) {
		for (ll j = 1; j <= N + 1; j++) {
			ll node = j - 1 + (i - 1) * (N + 1);
			if (i != M + 1) {
				ll up = vertical[j] - vertical[j - 1];
				EdgeList.pb(make_pair(up, ii(node, node + N + 1)));
			}
			if (j != N + 1) {
				ll right = horizontal[i] - horizontal[i - 1];
				EdgeList.pb(make_pair(right, ii(node, node + 1)));
			}
		}
	}
	sort(EdgeList.begin(), EdgeList.end());
	
	ll mst_cost = 0;
	UnionFind UF((N + 1) * (M + 1));
	for (ll i = 0; i < (ll) EdgeList.size(); i++) {
		pair<ll, ii> front = EdgeList[i];
		if (!UF.isSameSet(front.second.first, front.second.second)) {
			mst_cost += front.first;
			UF.unionSet(front.second.first, front.second.second);
		}
	}
	
	cout << mst_cost << endl;
}
