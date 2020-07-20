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
#define vii vector<int>
#define vs vector<string>
#define ll long long

int N;
vi balloons;

int balloonValue(int i) {
	if (i == 0) {
		return balloons[i]*balloons[i + 1];
	} else if (i == N - 1) {
		return balloons[i]*balloons[i - 1];
	} else{
		return balloons[i - 1] * balloons[i] * balloons[i + 1];
	}
}

int main() {
	cin >> N;
	balloons.resize(N);
	int **dp = new int*[N];
	for (int i = 0; i < N; i++) {
		cin >> balloons[i];
		dp[i] = new int[N];
		for (int j = 0; j < N; j++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		dp[i][i] = balloonValue(i);
	}
	for (int len = 1; len < N; len++) {
		for (int i = 0; i < N; i++) {
			int j = i + len;
			for (int k = i; k <= j && k < N; k++) {
				int possibleValue = 0;
				if (k > 0) possibleValue += dp[i][k - 1];
				if (k < N - 1) possibleValue += dp[k + 1][j];
				int leftBalloon = i == 0 ? 1 : balloons[i - 1];
				int rightBalloon = j == N - 1 ? 1 : balloons[j + 1];
				possibleValue += leftBalloon * balloons[k] * rightBalloon;
				if (dp[i][j] < possibleValue) dp[i][j] = possibleValue;
			}
		}
	}
	cout << dp[0][N - 1] << endl;
}
