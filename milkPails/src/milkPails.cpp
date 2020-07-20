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
#define ms(a,b) memset(a,b,sizeof a);
#define mc(a,b) memcpy(a,b,sizeof(a));

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("pails.in");
	fout.open("pails.out");
	int xBucketAmount, yBucketAmount, operationAmount, milkAmount;
	fin >> xBucketAmount >> yBucketAmount>> operationAmount >> milkAmount;
	bool reachable[101][101];
	reachable[0][0] = true;
	for (int moves = 0; moves < operationAmount; moves++) {
		bool next[101][101];
		for (int x = 0; x < xBucketAmount + 1; x++) {
			for (int y = 0; y < yBucketAmount + 1; y++) {
				if (!reachable[x][y]) {
					continue;
				}
				next[x][y] = true;
				next[0][y] = true;
				next[x][0] = true;
				next[xBucketAmount][y] = true;
				next[x][yBucketAmount] = true;
				int toY = min(x,yBucketAmount - y);
				next[x - toY][y + toY] = true;
				int toX = min(xBucketAmount - x,y);
				next[x + toX][y - toY] = true;
			}
		}
		mc(reachable,next);
 	}
	int ans = 1000000000;
	for (int i = 0; i < xBucketAmount + 1; i++) {
		for (int j = 0; j < yBucketAmount + 1; j++) {
			if (reachable[i][j]) {
				ans = min(ans,abs(i + j - milkAmount));
			}
		}
	}
	fout << ans << endl;
	fin.close();
	fout.close();
}
