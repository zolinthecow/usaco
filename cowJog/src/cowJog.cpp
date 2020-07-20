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
	ifstream fin;
	ofstream fout;
	fin.open("cowjog.in");
	fout.open("cowjog.out");
	int count, time;
	fin>>count>>time;
	vi cows;
	for(int i=0; i<count; i++){
		ii temp;
		fin>>temp.first>>temp.second;
		cows.pb(time * temp.second + temp.first);
	}
	int ans = 1, slowest = cows.back();
	for (int i = count - 2; i >= 0; i--) {
		if (cows[i] < slowest) ans++;
		slowest = min(slowest,cows[i]);
	}
	fout << ans << endl;
	fin.close();
	fout.close();
}
