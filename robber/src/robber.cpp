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
	int housesAmount;
	cin >> housesAmount;
	vi houses(housesAmount);
	for (int i = 0; i < housesAmount; i++) {
		cin >> houses[i];
	}
	int *dp = new int [housesAmount];
	dp[0] = houses[0];
	dp[1] = max(houses[0],houses[1]);
	for (int i = 2; i < housesAmount; i++) {
		dp[i] = max(houses[i] + dp[i - 2],dp[i - 1]);
	}
	cout << dp[housesAmount - 1] << endl;
}
