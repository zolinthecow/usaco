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

bool sortDescending(int a, int b){
	return a>b;
}
int main() {
	ifstream fin;
	ofstream fout;
	fin.open("lemonade.in");
	fout.open("lemonade.out");
	int a;
	fin>>a;
	vi cows;
	for(int i=0; i<a; i++){
		int temp;
		fin>>temp;
		cows.push_back(temp);
	}
	sort(cows.begin(), cows.end(), sortDescending);
	int count=0;
	vi used;
	for(vi::iterator itr=cows.begin(); itr!=cows.end(); itr++){
		int size=used.size();
		if(*itr>=size){
			count++;
			used.push_back(*itr);
		}else{
			break;
		}
	}
	fout<<count<<endl;
	fin.close();
	fout.close();
}
