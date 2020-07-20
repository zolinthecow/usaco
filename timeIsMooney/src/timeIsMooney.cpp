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
	fin.open("time.in");
	fout.open("time.out");
	int N, M, C;
	fin >> N >> M >> C;
	vi moonies(N);
	for (int i = 0; i < N; i++) {
		fin >> moonies[i];
	}
	vector< vi > AdjList(N);
	for (int i = 0; i < M; i++) {
		int a, b;
		fin >> a >> b;
		a--; b--;
		AdjList[b].pb(a);
	}
	int **dp = new int*[1001];
	for (int i = 0; i <= 1000; i++) {
		dp[i] = new int[N];
		for (int j = 0; j < N; j++) {
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 0;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < (int)AdjList[j].size(); k++) {
				if (dp[i - 1][AdjList[j][k]] == -1) continue;
				dp[i][j] = max(dp[i][j], (int) (dp[i - 1][AdjList[j][k]] + moonies[j]));
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= 1000; i++) {
		ans = max(ans, (int) (dp[i][0] - C * pow(i, 2)));
	}
	fout << ans << endl;
	fin.close();
	fout.close();
}
