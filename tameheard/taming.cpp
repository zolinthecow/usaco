#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define pb push_back
#define LSOne(S) (S & (-S))
#define INF 1e9;

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	//freopen((s + ".out").c_str(), "w", stdout);
}

const int mxN = 1e2 + 5;

int N;
int A[mxN];

int dp[mxN][mxN][mxN];

int main() {
	setIO("taming");
	cin >> N;
	memset(dp, 0xF, sizeof(dp));
	for(int i=0;i<N;i++)
		cin >> A[i];
	if(A[0] == 0)
		dp[0][0][1] = 0;
	else
		dp[0][0][1] = 1;
	for(int i=1;i<N;i++)
	{
		for(int j=0;j<=i;j++)
			for(int k=1;k<=i+1;k++)
			{
				if(j < i) 
					dp[i][j][k] = dp[i-1][j][k];
				else
					for(int j1=0;j1<i;j1++)
						dp[i][j][k] = min(dp[i][j][k], dp[i-1][j1][k-1]);
				if(A[i] != i-j) 
					dp[i][j][k]++;
			}
	}
	for(int k=1;k<=N;k++)
	{
		int low = INF;
		for(int j=0;j<N;j++)
			low = min(low, dp[N-1][j][k]);
		cout << low << '\n';
	}
}
