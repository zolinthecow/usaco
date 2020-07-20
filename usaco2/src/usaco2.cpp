#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ii pair<ll, ll>
#define dd pair<double, double>
#define vi vector<ll>
#define vd vector<double>
#define vii vector<ii>
#define vdd vector<dd>
#define vs vector<string>
#define ll long long
#define INF 1000000000
#define MOD 1000000007

struct farmer{
	int from, to, milk, farmerNum;
};

int main() {
	int N, M;
	cin >> N >> M;
	vi milkTypes(N);
	for (int i = 0; i < N; i++) {
		cin >> milkTypes[i];
	}
	vector<vi> AdjList(N);
	for (int i = 0; i < N - 1; i++) {
		int x, y;
		cin >> x >> y;
		x -= 1; y -= 1;
		AdjList[x].pb(y);
		AdjList[y].pb(x);
	}
	vector< vector<farmer> > paths(N);

	vector<farmer> allFarmers;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a -= 1, b -= 1;
		farmer t; t.from = min(a, b), t.to = max(a, b), t.milk = c, t.farmerNum = i;
		paths[min(a, b)].pb(t);
		allFarmers.pb(t);
	}
	vi satisfied(N, 0);
	vector< vector<farmer> > need(N + 1);

	map<int, map<int, ii> > off;
	map<int, ii> temp;
	for (int i = 0; i < N; i++) {
		off.insert(make_pair(i, temp));
	}
	vi d(N, INF); d[0] = 0;
	queue<int> q; q.push(0);

	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < (int)paths[u].size(); i++) {
			farmer farmerOn = paths[u][i];
			need[farmerOn.milk].pb(farmerOn);
			off[farmerOn.to].insert(make_pair(farmerOn.farmerNum, ii(farmerOn.milk, need[farmerOn.milk].size() - 1)));
		}
		int milkOn = milkTypes[u];
		for (int i = 0; i < (int)need[milkOn].size(); i++) {
			farmer farmerOn = need[milkOn][i];
			satisfied[farmerOn.farmerNum] = 1;
			off[farmerOn.to].erase(farmerOn.farmerNum);
		}
		need[milkOn].clear();
		for (auto it : off[u]) {
			need[it.second.first].erase(need[it.second.first].begin() + it.second.second);
		}
		for (int j = 0; j < (int)AdjList[u].size(); j++) {
			int v = AdjList[u][j];
			if (d[v] == INF) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
	for (auto it : satisfied) {
		cout << it;
	}
	cout << endl;
}
