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
	freopen((s + ".out").c_str(), "w", stdout);
}

const int mxN = 1e5 + 5;
const int logN = 14;

int L[2*mxN], E[2*mxN], H[mxN], idx;

class RMQ {                                          // Range Minimum Query
private:
  int _A[mxN], SpT[mxN][logN];
public:
  RMQ(int n, int A[]) {    // constructor as well as pre-processing routine
    for (int i = 0; i < n; i++) {
      _A[i] = A[i];
      SpT[i][0] = i; // RMQ of sub array starting at index i + length 2^0=1
    }
    // the two nested loops below have overall time complexity = O(n log n)
    for (int j = 1; (1<<j) <= n; j++) // for each j s.t. 2^j <= n, O(log n)
      for (int i = 0; i + (1<<j) - 1 < n; i++)    // for each valid i, O(n)
        if (_A[SpT[i][j-1]] < _A[SpT[i+(1<<(j-1))][j-1]])            // RMQ
          SpT[i][j] = SpT[i][j-1];    // start at index i of length 2^(j-1)
        else                  // start at index i+2^(j-1) of length 2^(j-1)
          SpT[i][j] = SpT[i+(1<<(j-1))][j-1];
  }

  int query(int i, int j) {
    int k = (int)floor(log((double)j-i+1) / log(2.0));    // 2^k <= (j-i+1)
    if (_A[SpT[i][k]] <= _A[SpT[j-(1<<k)+1][k]]) return SpT[i][k];
    else                                         return SpT[j-(1<<k)+1][k];
} 
  int lca(int a, int b) {
	return E[query(min(H[a], H[b]), max(H[a], H[b]))];
  }
};

int N, M;
int milk[mxN];
vi adjList[mxN];

map<int, int> types[mxN];

struct dSto {
	int cur, depth, p;
};

void dfs1() {
  //H[cur] = idx;
  //E[idx] = cur;
  //L[idx++] = depth;
  //for (int i = 0; i < (int) adjList[cur].size(); i++) {
	//if (adjList[cur][i] == p) continue;
    //dfs1(adjList[cur][i], depth+1, cur);
    //E[idx] = cur;                              // backtrack to current node
    //L[idx++] = depth;
  //}
  deque<dSto> s;
  s.push_front(dSto{1, 0, -1});
  while (!s.empty()) {
	dSto on = s.front();
	H[on.cur] = idx;
	E[idx] = on.cur;
	L[idx++] = on.depth;
	for (auto v : adjList[on.cur]) {
	  if (v == on.p) continue;
	  s.push_front(dSto{v, on.depth + 1, on.cur});	
	}
	if (s.front().cur == on.cur) {
	  for (auto v : adjList[on.cur]) {
		if (v == on.p) continue;
		E[idx] = on.cur;
		L[idx++] = on.depth;  
	  }	
	  s.pop_front();
	}  
  }
  
}

void buildRMQ() {
  idx = 0;
  memset(H, -1, sizeof H);
  dfs1();                       // we assume that the root is at index 0
}

void dfs2() {
	deque<ii> s;
	s.push_front(ii(1, -1));
	while (!s.empty()) {
		ii u = s.front(); s.pop_front();
		int on = u.first, p = u.second;
		if (p != -1) types[on] = types[p];
		types[on][milk[on]]++;
		for (auto v : adjList[on]) {
			if (v == p) continue;
			s.push_front(ii(v, on));
		}
	}
}

int main() {
	setIO("milkvisits");
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> milk[i];
	int a, b, c;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		adjList[a].pb(b);
		adjList[b].pb(a);
	}
	dfs2();
	buildRMQ();
	RMQ r = RMQ(2 * N, L);
	int lca;
	int ans;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		lca = r.lca(a, b);
		ans = 0;
		ans += types[b][c] - types[lca][c] + (milk[lca] == c);
		ans += types[a][c] - types[lca][c];
		if (ans > 0) cout << 1;
		else         cout << 0;
	}
	cout << endl;
}
