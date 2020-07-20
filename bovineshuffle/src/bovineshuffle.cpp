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

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("shuffle.in");
	fout.open("shuffle.out");
	int cowCount;
	fin>>cowCount;
	int *move = new int[cowCount];
	int *to = new int[cowCount];
	for(int i = 0; i < cowCount; i++){
		fin>>to[i];
		to[i] -= 1;
		move[ to[i] ]++;
	}
	queue<int> noParent;
	int neverEmpty = cowCount;
	for(int i = 0; i < cowCount; i++){
		if( move[i] == 0 ){
			noParent.push(i);
			neverEmpty--;
		}
	}
	while( !noParent.empty() ){
		int on = noParent.front();
		noParent.pop();
		if( --move[ to[on] ]==0 ){
			noParent.push( to[on] );
			neverEmpty--;
		}
	}
	fout<<neverEmpty<<endl;
	fin.close();
	fout.close();
}
