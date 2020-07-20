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
	ifstream fin;
	ofstream fout;
	fin.open("citystate.in");
	fout.open("citystate.out");
	int a;
	fin>>a;
	vector< pair<string, string> > temp;
	for(int i=0; i<a; i++){
		pair<string, string> name;
		fin>>name.first>>name.second;
		temp.push_back(name);
	}
	vector< pair<string, string> > cityCode;
	for(auto it : temp){
		cityCode.push_back(pair<string, string>(it.first.substr(0, 2), it.second.substr(0, 2)));
	}
	vector< pair<string, string> > used;
	int count=0;
	for(auto it : cityCode){
		pair<string, string> reversed(it.second, it.first);
		if(find(used.begin(), used.end(), reversed)!=used.end()){
			count++;
		}
		used.push_back(it);
	}
	fout<<count<<endl;
	fin.close();
	fout.close();
}
