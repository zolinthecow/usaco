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
#define INF 1000000000
#define MOD 1000000007

vector<vi> orders;

bool acylic(int a) {

}

vi ts;
vector<bool> visited;
vector<vi> AdjList;

void dfs2(int u) {
	visited[u] = 1;
	for (int j = 0; j < (int)AdjList[u].size(); j++) {
		int v = AdjList[u][j];
		if (!visited[v]) {
			dfs2(v);
		}
	}
	ts.pb(u);
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("milkorder.in");
	fout.open("milkorder.out");
	int N, M;
	fin >> N >> M;
	AdjList.resize(N);
	visited.resize(N);
	for (int i = 0; i < M; i++) {
		int a, b;
		fin >> a >> b;
		a--, b--;
		AdjList[a].pb(b);
	}
	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		dfs2(i);
	}
	for (auto it : ts) {
		cout << it << " ";
	}
	for (int i = 0; i < M; i++) {
		int t;
		cin >> t;
		vi temp(t);
		for (int j = 0; j < t; j++) {
			cin >> temp[j];
		}
		orders.pb(temp);
	}
	int X;
	int mini = 1;
	int maxi = N;
	/*while (mini < maxi - 1) {
		int mid = mini + (maxi - mini) / 2;

	}*/
}
