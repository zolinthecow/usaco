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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream fin;
	ofstream fout;
	fin.open("taming.in");
	fout.open("taming.out");
	int N;
	fin >> N;
	vi log(N);
	for (int i = 0; i < N; i++) {
		fin >> log[i];
	}
	int **dp = new int*[N + 1];
	for (int i = 0; i <= N; i++) {
		dp[i] = new int[N];
		for (int j = 0; j < N; j++) {
			dp[i][j] = INF;
		}
	}
	int amtDif1 = 0;
	for (int i = 0; i < N; i++) {
		if (log[i] != i) amtDif1++;
	}
	dp[1][0] = amtDif1;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < N; j++) {
			for (int k = 0; k < j; k++) {
				if (dp[i - 1][k] == INF) continue;
				int afterAmtChanged = 0;
				for (int l = 0; l < N - k; l++) {
					if (log[l + k] != l) afterAmtChanged++;
				}
				int prevAmtChanged = dp[i - 1][k] - afterAmtChanged;
				int befBreak = 0;
				for (int l = 0; l < j - k; l++) {
					if (log[l + k] != l) befBreak++;
				}
				int aftBreak = 0;
				for (int l = 0; l < N - j; l++) {
					if (log[l + j] != l) aftBreak++;
				}
				dp[i][j] = min(dp[i][j], prevAmtChanged + befBreak + aftBreak);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		int ans = INF;
		for (int j = 0; j < N; j++) {
			ans = min(ans, dp[i][j]);
		}
		fout << ans << endl;
	}
	fin.close();
	fout.close();
}
