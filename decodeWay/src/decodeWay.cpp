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
	string n;
	cin >> n;
	vector<string> code;
	int *dp = new int[n.length()];
	for (int i = 0; i < (int)n.length(); i++) {
		code.pb(n.substr(i,1));
		dp[i] = 0;
	}
	dp[0] = 1;
	for (int j = 1; j < (int)n.length(); j++) {
		dp[j] = dp[j - 1];
		if (stoi(n.substr(j - 1,1) + n.substr(j,1)) <= 26) dp[j]++;
	}
	cout << dp[n.length() - 1] << endl;
}
