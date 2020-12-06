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

const int mxN = 1e5 + 5;

int N;
unordered_map<int, int> adjList[mxN];

vi divisors;

int ans[mxN];

vi findDivisors(int n) {
	vi div;
	int sq = sqrt(n) + 1;
	for (int i = 2; i < sq; i++) {
		if (n % i == 0) {
			if (n / i == i) div.pb(i);
			else div.pb(i), div.pb(n / i);
		}
	}
	return div;
}

void compress() {
	queue<ii> q; q.push(ii(1, -1));
	ii front; int u, p, newP; ii child;
	while (!q.empty()) {
		front = q.front(); q.pop();
		u = front.first, p = front.second;
		newP = (adjList[u].size() == 2) ? p : u;
		for (auto v : adjList[u]) {
			if (v.first == p) continue;
			child = v;
			q.push(ii(v.first, newP));
		}
		if (newP == p && newP != -1) {
			//join parent and child
			adjList[p].insert(ii(child.first, adjList[p][u] + 1));
			//join child and parent
			adjList[child.first].insert(ii(p, adjList[p][u] + 1));
			//remove u from parent
			adjList[p].erase(u);
			//remove u from child
			adjList[child.first].erase(u);
			//remove parent from u
			adjList[u].erase(p);
			//remove child from u
			adjList[u].erase(child.first);
		}
	}
}

int dfs(int u, int weight, int p, int path) {
	if (adjList[u].size() == 1 && p != -1) {
		return weight - (weight / path) * path; 
	}
	vi leftover; int l;
	for (auto v : adjList[u]) {
		if (v.first == p) continue;
		l = dfs(v.first, v.second, u, path);
		if (l == -INF) return -INF;
		if (l != 0) leftover.pb(l);
	}
	unordered_multiset<int> ret(leftover.begin(), leftover.end());
	for (int i = 0; i < (int) leftover.size(); i++) {
		for (int j = i + 1; j < (int) leftover.size(); j++) {
			if (leftover[i] + leftover[j] == path && ret.find(leftover[i]) != ret.end() && 
				ret.find(leftover[j]) != ret.end()) {
					
				ret.erase(ret.find(leftover[i]));
				ret.erase(ret.find(leftover[j]));
			}
		}
	}
	for (auto it : ret) {
		if (it + weight == path) {
			ret.erase(it);
			break;
		}
	}
	if (ret.size() == 0) return 0;
	else if (ret.size() == 1) return *(ret.begin()) + weight;
	else return -INF;
}

int main () {
	setIO("deleg");
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		adjList[a].insert(ii(b, 1));
		adjList[b].insert(ii(a, 1));
	}
	divisors = findDivisors(N - 1); 
	divisors.pb(1), divisors.pb(N - 1);
	compress();
	//for (int i = 1; i <= N; i++) {
		//if (adjList[i].size() == 0) continue;
		//cout << i << ": ";
		//for (auto v : adjList[i]) {
			//cout << "(" << v.first << ", " << v.second << ") ";
		//}
		//cout << endl;
	//}
	for (auto it : divisors) {
		if (dfs(1, 0, -1, it) == 0) ans[it] = 1;
	}
	for (int i = 1; i < N; i++) cout << ans[i];
	cout << endl;
}
