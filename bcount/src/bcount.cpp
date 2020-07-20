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

int main() {
	int a = 20, b = 4, c = 2, d = 100, e =3;
	for (int i = 1; i <= 4; i++) {
		if (a/i > d/b) {
			b += 1;
		} else {
			d -= 20;
		}
		if (b + 3 * i < a * c) {
			b += 1;
		} else {
			c += 1;
		}
		if (pow(c,e) > pow(e,c)) {
			c += 1;
		} else {
			e += 1;
		}
	}
	cout << 4 * (a/e + b/c) - a/(b+2) + pow(d,2)/a * 2;
}
