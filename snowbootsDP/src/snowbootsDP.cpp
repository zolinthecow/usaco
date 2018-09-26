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
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;
#define INF 1000000000

int N, B, F[250], S[250], D[250], best = 9999;
bool beenthere[250][250];

int solve() {
	for (int b = 0; b < B; b++)
		for (int i = 0; i < N; i++) {

			if (F[i] > S[b]) {
				beenthere[i][b] = false;
				continue;
			}

			if (i == 0 && b == 0)
				beenthere[i][b] = true;

			for (int i2 = 0; i2 < i; i2++)
				if (beenthere[i2][b] && i2 + D[b] >= i)
					beenthere[i][b] = true;

			for (int b2 = 0; b2 < b; b2++)
				if (beenthere[i][b2])
					beenthere[i][b] = true;

			if (i == N - 1 && beenthere[i][b])
				return b;
		}
}

int main(void) {
	cin >> N >> B;
	for (int i = 0; i < N; i++)
		cin >> F[i];
	for (int i = 0; i < B; i++)
		cin >> S[i] >> D[i];

	cout << solve() << "\n";
	return 0;
}
