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

int N, K;
vi cows;

int **memo;

int calculate(int on, int currUsed, int currMax) {
	int ret;
	if (memo[on][currUsed] != -1) return memo[on][currUsed];
	if (on == N) {
		ret = 0;
	} else {
		int ans = 0;
		ans = cows[on] + calculate(on + 1, 1, cows[on]);
		if (currUsed < K) {
			int toAdd = 0;
			if (cows[on] > currMax) {
				toAdd = currUsed * (cows[on] - currMax);
			}
			int t = cows[on];
			int valOn = max(t, currMax);
			ans = max(ans, valOn + toAdd + calculate(on + 1, currUsed + 1, valOn));
		}
		ret = ans;
	}
	memo[on][currUsed] = ret;
	return ret;
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("teamwork.in");
	fout.open("teamwork.out");
	fin >> N >> K;
	cows.resize(N);
	for (int i = 0; i < N; i++) {
		fin >> cows[i];
	}
	memo = new int *[N + 1];
	for (int i = 0; i <= N; i++) {
		memo[i] = new int[K + 1];
		for (int j = 0; j <= K; j++) {
			memo[i][j] = -1;
		}
	}
	fout << calculate(0, 0, 0) << endl;
	fin.close();
	fout.close();
}
