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
	fin.open("pails.in");
	fout.open("pails.out");
	int X, Y, M;
	fin >> X >> Y >> M;
	bool dp[1000];
	dp[0] = true;
	for (int i = 0; i < M; i++) {
		if (dp[i]) {
			dp[i + X] = true;
			dp[i + Y] = true;
		}
	}
	int ans = 0;
	for (int i = 0; i < M; i++) {
		if (dp[i]) ans = max(ans,i);
	}
	fout << ans << endl;
	fin.close();
	fout.close();
}
