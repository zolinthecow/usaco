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
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<ll,ll> pll;
typedef push_back() pb;

int main() {
	int cowAmount;
	cin >> cowAmount;
	vector< pair<int,pll> > cows;
	for (int i = 0; i < cowAmount; i++) {
		pll temp;
		cin >> temp.first >> temp.second;
		pair<int,pll> temp1;
		temp1.first = i, temp1.second = temp;
		cows.push_back(temp1);
	}
}
