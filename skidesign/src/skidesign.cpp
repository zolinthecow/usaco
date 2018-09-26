/*
ID: colinzh3
PROG: skidesign
LANG: C++
 */
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

int shortenHills(vector<int> hill, int a){
	if(hill.back()-hill.front()<=17){
		return 0;
	}
	vector<int> costs;
	for(int z=1; z<=hill.back()-17; z++){
		if(z+17<hill.back()){
			int min=z;
			int max=z+17;
			int totalcost=0;
			for(vector<int>::iterator it=hill.begin(); it!=hill.end(); it++){
				if(*it<min){
					totalcost+=pow(min-*it,2);
				}else if(*it>max){
					totalcost+=pow(*it-max,2);
				}
			}
			costs.push_back(totalcost);

		}
	}
	int min, count=0;
	for(vector<int>::iterator its=costs.begin(); its!=costs.end(); its++){
		if(count==0){
			min=*its;
		}
		if(*its<min){
			min=*its;
		}
		count++;
	}
	return min;
}
int main(){
	ifstream fin;
	ofstream fout;
	fin.open("skidesign.in");
	fout.open("skidesign.out");
	int a;
	fin>>a;
	vector<int> hills;
	for(int i=0; i<a; i++){
		int hill;
		fin>>hill;
		hills.push_back(hill);
	}
	sort(hills.begin(), hills.end());
	int temp=shortenHills(hills, a);
	fout<<temp<<endl;
	fin.close();
	fout.close();
}
