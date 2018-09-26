/*
ID: colinzh3
PROG: frac1
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

struct fraction{
	int num, denom;
};

bool waytosort(fraction a, fraction b){
	double z=a.num, c=a.denom, d=b.num, e=b.denom;
	return z/c<d/e;
}
bool cannotSimplify(fraction a){
	int b=a.denom, c=a.num;
	while(b!=c){
		if(c>b){
			c-=b;
		}else{
			b-=c;
		}
	}
	if(c==0||c==1){
		return true;
	}else{
		return false;
	}
}
int main() {
	ifstream fin;
	ofstream fout;
	fin.open("frac1.in");
	fout.open("frac1.out");
	int a;
	fin>>a;
	vector<int> denominators;
	vector<int> numerators;
	vector<fraction> allFractions;
	for(int i=1; i<=a; i++){
			denominators.push_back(i);
			numerators.push_back(i);
	}
	for(vector<int>::iterator itr=denominators.begin(); itr!=denominators.end(); itr++){
		for(vector<int>::iterator it=numerators.begin(); it!=numerators.end(); it++){
			fraction temp;
			temp.num=*it, temp.denom=*itr;
			if(temp.denom>=temp.num){
				allFractions.push_back(temp);
			}
		}
	}
	sort(allFractions.begin(), allFractions.end(), waytosort);
	fout<<"0/1"<<endl;
	for(vector<fraction>::iterator its=allFractions.begin(); its!=allFractions.end(); its++){
		if(cannotSimplify(*its)){
			fout<<(*its).num<<"/"<<(*its).denom<<endl;
		}
	}
	fin.close();
	fout.close();
}
