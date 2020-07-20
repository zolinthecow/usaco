#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ii pair<int, int>
#define dd pair<double, double>
#define vi vector<ll>
#define vd vector<double>
#define vii vector<ii>
#define vdd vector<dd>
#define vs vector<string>
#define ll long long
#define INF 10000000
#define MOD 10000000

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("timeline.in");
	fout.open("timeline.out");
	int N, M, C;
	fin >> N >> M >> C;
	vi noEarlierThan(N);
	vi topSort(N, 0);
	vector< vii > AdjList(N);
	for (int i = 0; i < N; i++) {
		fin >> noEarlierThan[i];
	}
	for (int i = 0; i < C; i++) {
		int a, b, c;
		fin >> a >> b >> c;
		a--; b--;
		AdjList[a].pb(ii(b,c));
		topSort[b]++;
	}
	queue<int> q;
	for (int i = 0; i < N; i++) {
		if (topSort[i] == 0) q.push(i);
	}
	vi ans(noEarlierThan);
	vector<bool> visited(N, false);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		visited[u] = true;
		for (int i = 0; i < (int)AdjList[u].size(); i++) {
			ii v = AdjList[u][i];
			ans[v.first] = max(ans[v.first], ans[u] + v.second);
			if (--topSort[v.first] == 0 && !visited[v.first]) q.push(v.first);
		}
	}
	for (auto it : ans) {
		fout << it << endl;
	}
	fin.close();
	fout.close();
}
