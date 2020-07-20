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
#define pb push_back
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vs vector<string>
#define ll long long
#define pb push_back

int **memo;

vi bales;
int baleCount;

int calculate(int on, int b1Size, int b2Size, int b3Size) {
	ll result = 100000000;
	if (on == baleCount - 1) {
		if (b1Size >= b2Size && b2Size >= b3Size) {
			if (b2Size + bales[on] >= b1Size || b3Size + bales[on] >= b2Size) {
				result = 0;
			} else {
				result = bales[on];
			}
		}
	} else {
		ll b1Result = b1Size + calculate(on + 1, b1Size + bales[on], b2Size, b3Size);
		ll b2Result = b1Size + calculate(on + 1, b1Size, b2Size + bales[on], b3Size);
		ll b3Result = b1Size + calculate(on + 1, b1Size, b2Size, b3Size + bales[on]);
		result = min(result, b1Result);
		result = min(result, b2Result);
		result = min(result, b3Result);
	}
	return result;
}

int main() {
	cin >> baleCount;
	bales.assign(baleCount,0);
	for (int i = 0; i < baleCount; i++) {
		cin >> bales[i];
	}
	cout << calculate(0,0,0,0) << endl;
}
