#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <functional>
using namespace std;
#define pb push_back
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vs vector<string>
#define ll long long
#define INF 1000000000

int N, K;
int A[401];
int dp[401][401];

double f(int n)  {
	if (n == 1) {
		return 9000;
	} else {
		return (0.9) * f(n - 1) + 800;
	}
}

int main() {
	cout << f(1000) << endl;
	ifstream fin;
	ofstream fout;
	fin.open("snakes.in");
	fout.open("snakes.out");
	fin >> N >> K;
	int tot = 0;
	int high = 0;
	for (int i = 1; i <= N; i++) {
		fin >> A[i];
		high = max(high, A[i]);
		dp[i][0] = high * i;
		for (int j = 1; j <= i; j++) {
			dp[i][j] = INF;
			int mx = A[i];
			for (int b = i - 1; b >= 0; b--) {
				dp[i][j] = min(dp[i][j], dp[b][j - 1] + mx * (i - b));
				mx = max(mx, A[b]);
			}
		}
		tot += A[i];
	}
	fout << dp[N][K] - tot << '\n';
	fin.close();
	fout.close();
}
