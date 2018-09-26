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

unordered_map<int, vi> fields;
int bessieSpeed, elsieSpeed, piggySpeed, fieldCount, connectionsCount;
int best=1000000;

void calculateSmallest(int bessiePlace, int elsiePlace, int count){
	if(bessiePlace==fieldCount-1 && elsiePlace==fieldCount-1){
		best=min(best, count);
		return;
	}else{
		if(bessiePlace==fieldCount-1){
			for(vi::iterator itr=fields[elsiePlace].begin(); itr!=fields[elsiePlace].end(); itr++){
				calculateSmallest(bessiePlace, *itr, count+elsieSpeed);
			}
		}
		if(elsiePlace==fieldCount-1){
			for(vi::iterator itr=fields[bessiePlace].begin(); itr!=fields[bessiePlace].end(); itr++){
				calculateSmallest(*itr, elsiePlace, count+bessieSpeed);
			}
		}
		if(bessiePlace==elsiePlace){
			for(vi::iterator itr=fields[bessiePlace].begin(); itr!=fields[bessiePlace].end(); itr++){
				calculateSmallest(*itr, *itr, count+piggySpeed);
			}
		}
		if(bessiePlace!=fieldCount-1 && elsiePlace!=fieldCount-1){
			for(vi::iterator itr=fields[bessiePlace].begin(); itr!=fields[bessiePlace].end(); itr++){
				calculateSmallest(*itr, elsiePlace, count+bessieSpeed);
			}
			for(vi::iterator it=fields[elsiePlace].begin(); it!=fields[elsiePlace].end(); it++){
				calculateSmallest(bessiePlace, *it, count+elsieSpeed);
			}
		}
	}
}
int main() {
	ifstream fin;
	ofstream fout;
	fin.open("piggyback.in");
	fout.open("piggyback.out");
	cin>>bessieSpeed>>elsieSpeed>>piggySpeed>>fieldCount>>connectionsCount;
	int first, second;
	for(int i=0; i<connectionsCount; i++){
		int a, b;
		cin>>a>>b;
		if(i==0){
			first=a-1;
		}else if(i==1){
			second=a-1;
		}
		fields[a-1].push_back(b-1);
	}
	int count=0;
	calculateSmallest(0, 1, 0);
	cout<<best<<endl;
	fin.close();
	fout.close();
}
