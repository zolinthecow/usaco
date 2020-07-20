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

bool descending(int a, int b){
	return a>b;
}
int main() {
	ifstream fin;
	ofstream fout;
	fin.open("cbarn.in");
	fout.open("cbarn.out");
	int n;
	fin>>n;
	vi cows(n);
	for(int i=0; i<n; i++){
		fin>>cows[i];
	}
	sort(cows.begin(), cows.end(), descending);
	int count=n-1;
	int answer=0;
	for(int i=0; i<n; i++){
		if(count!=cows[i]+1 && count!=cows[i]){
			answer+=4;
		}else if(count==cows[i]+1){
			answer+=1;
		}
		count--;
	}
	fout<<answer<<endl;
	fin.close();
	fout.close();
}
