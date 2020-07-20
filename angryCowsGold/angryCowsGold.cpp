#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define pb push_back
#define INF 2000000000

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
	setIO("angry");
	int N; cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i] *= 2;
	}
	sort(A.begin(), A.end());
	A.resize(unique(A.begin(), A.end()) - A.begin());
	
	vector<int> DP[2];
	for (int it = 0; it < 2; it++) {
		int lstj = 0;
		DP[it].resize(N, INF);
		DP[it][0] = -2;
		for (int i = 1; i < N; i++) {
			//if dist from lstj to i + 2 < dp[lstj + 1] + 2 then just
			//directly blow up lstj
			//not satisfied when abs(i - lstj) + 2 > 
			while (lstj + 1 < i && abs(A[i] - A[lstj + 1]) >
				   DP[it][lstj + 1] + 2) {
				lstj++;	   
			}
			DP[it][i] = min(abs(A[i] - A[lstj]), DP[it][lstj + 1] + 2);
		}
		reverse(A.begin(), A.end());
	}
	reverse(DP[1].begin(), DP[1].end());

	int i = 0;
	int j = N - 1;
	int result = INF;
	while (i < j) {
		result = min(result, max((A[j] - A[i]) / 2, 2 + 
					 max(DP[0][i], DP[1][j])));
		if (DP[0][i + 1] < DP[1][j - 1]) {
			i++;
		} else {
			j--;
		}
	}
	cout << result / 2 << '.' << (result % 2 ? 5 : 0) << '\n';
}
