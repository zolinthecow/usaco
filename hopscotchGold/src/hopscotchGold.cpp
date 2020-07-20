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
#define ii pair<ll, ll>
#define vi vector<ll>
#define vii vector<ii>
#define vs vector<string>
#define ll long long

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("hopscotch.in");
	fout.open("hopscotch.out");
	int height, width, maxInt;
	fin >> height >> width >> maxInt;
	int **grid, **dp;
	grid = new int *[height];
	dp = new int *[height];
	for (int i = 0; i < height; i++) {
		grid[i] = new int[width];
		dp[i] = new int[width];
		for (int j = 0; j < width; j++) {
			fin >> grid[i][j];
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (dp[i][j] >= 1) {
				for (int k = i + 1; k < height; k++) {
					for (int l = j + 1; l < width; l++) {
						if (grid[k][l] != grid[i][j]) dp[k][l] += dp[i][j];
					}
				}
			}
		}
	}
	fout << dp[height - 1][width - 1] << endl;
	fin.close();
	fout.close();
}
