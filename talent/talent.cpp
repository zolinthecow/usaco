#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define pb push_back
#define LSOne(S) (S & (-S))
#define INF 1e12

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	//freopen((s + ".out").c_str(), "w", stdout);
}

const int mxN = 250 + 5, mxW = 1e3 + 5;

int N, M; 
ii cows[mxN];

int dp[
