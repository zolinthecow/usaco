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
	int n; string sentence;
	cin >> n >> sentence;
	vector<string> dictionary;
	bool *dp = new bool[sentence.length() + 1];
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		dictionary.pb(t);
		dp[i] = false;
	}
	dp[0] = true, dp[n] = false;
	for (int i = 1; i < (int)sentence.length() + 1; i++) {
		for (int j = 0; j < n; j++) {
			string dictWord = dictionary[j];
			if (i - (int)dictWord.length() >= 0) {
				string word = sentence.substr(i - dictWord.length(), dictWord.length());
				if (dictWord == word) {
					if (dp[i - dictWord.length()]) dp[i] = true;
				}
			}
		}
	}
	cout << (dp[sentence.length()] ? "Yes" : "No") << endl;
}
