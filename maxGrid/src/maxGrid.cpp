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

int main() {
	int rows, columns;
	cin >> rows >> columns;
	int **grid = new int *[rows];
	int **dp = new int *[rows];
	for (int i = 0; i < rows; i++) {
		grid[i] = new int[columns];
		dp[i] = new int[columns];
		for (int j = 0; j < columns; j++) {
			cin >> grid[i][j];
			dp[i][j] = 0;
		}
	}
	dp[0][0] = grid[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			int up = 0, left = 0;
			if (i > 0) {
				up = dp[i - 1][j];
			}
			if (j > 0) {
				left = dp[i][j - 1];
			}
			dp[i][j] = max(up + grid[i][j], left + grid[i][j]);
		}
	}
	cout << dp[rows - 1][columns - 1] << endl;
}
