/*
ID: colinzh3
PROG: castle
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

struct measurement{
	int day, amount;
	string cow;
};
int convertToInt(string a){
	int result;
	stringstream convert(a);
	if(!(convert>>result)){
		result =-1;
	}
	return result;
}
bool waytosort(measurement a, measurement b){
	return b.day>a.day;
}
int main() {
	ifstream fin;
	ofstream fout;
	fin.open("measurement.in");
	fout.open("measurement.out");
	int a, cowcount=3, changeamount=0, previousmax;
	string leadcow;
	vector<measurement> cows;
	map<string, int> cowsmilk;
	vector<string> previousleaders;
	previousleaders.push_back("Bessie"), previousleaders.push_back("Mildred"),previousleaders.push_back("Elsie");
	cin>>a;
	for(int i=0; i<a; i++){
		measurement temp;
		cin>>temp.day>>temp.cow>>temp.amount;
		cows.push_back(temp);
	}
	sort(cows.begin(), cows.end(), waytosort);
	for(vector<measurement>::iterator itr=cows.begin(); itr!=cows.end(); itr++){
		cowsmilk.insert(pair<string, int>((*itr).cow, 7));
	}
	for(vector<measurement>::iterator it=cows.begin(); it!=cows.end(); it++){
		vector<string> leads;
		cowsmilk.at((*it).cow)+=(*it).amount;
		int max=0;
		for(map<string, int>::iterator its=cowsmilk.begin(); its!=cowsmilk.end(); its++){
			if((*its).second>max){
				max=(*its).second;
			}
		}
		for(map<string, int>::iterator ita=cowsmilk.begin(); ita!=cowsmilk.end(); ita++){
			if((*ita).second==max){
				leads.push_back((*ita).first);
			}
		}
		if(leads!=previousleaders){
			changeamount++;
		}
		previousmax=max;
		previousleaders=leads;
	}
	cout<<changeamount;
	fin.close();
	fout.close();
}
