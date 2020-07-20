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

vi otherTwo(int a) {
	vi ans;
	for (int i = 0; i < 3; i++) {
		if (i != a) ans.pb(i);
	}
	return ans;
}

bool win(int a, int b) {
	if (a == 0) {
		return b == 2;
	} else if (a == 1) {
		return b == 0;
	} else {
		return b == 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream fin;
	ofstream fout;
	fin.open("hps.in");
	fout.open("hps.out");
	int N, K;
	fin >> N >> K;
	//H = 0, P = 1, S = 2;
	vi moves;
	for (int i = 0; i < N; i++) {
		char a;
		fin >> a;
		if (a == 'H') moves.pb(0);
		else if (a == 'P') moves.pb(1);
		else moves.pb(2);
	}
	int ***dp = new int**[N + 1];
	for (int i = 0; i <= N; i++) {
		dp[i] = new int*[K + 1];
		for (int j = 0; j <= K; j++) {
			dp[i][j] = new int[3];
			for (int k = 0; k < 3; k++) {
				dp[i][j][k] = 0;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			for (int k = 0; k < 3; k++) {
				int toAdd = win(k, moves[i - 1]) ? 1 : 0;
				dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + toAdd);
				if (j == 0) continue;
				vi from = otherTwo(k);
				for (auto it : from) {
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][it] + toAdd);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 3; i++) {
		ans = max(ans, dp[N][K][i]);
	}
	fout << ans << endl;
	fin.close();
	fout.close();
}
