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

int main() {
	int count, time;
	cin>>count>>time;
	vii cows;
	for(int i=0; i<count; i++){
		ii temp;
		cin>>temp.first>>temp.second;
		cows.push_back(temp);
	}
	vii positions=cows;
	for(int i=0; i<(int)positions.size(); i++){
		int moved=positions[i].second *= time;
		positions[i].second += moved+positions[i].first;
	}
	int answer=0;

}
