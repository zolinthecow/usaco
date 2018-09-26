/*
ID: colinzh3
PROG: milk3
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

int a, b, c;
vector<int> success;
struct milkamt{
	int a, b, c;
};
bool operator==(const milkamt& x, const milkamt& y){
	return (x.a==y.a&&x.b==y.b&&x.c==y.c);
}
vector<milkamt> used;
void addSolution(int c){
	if(find(success.begin(), success.end(), c)==success.end()){
		success.push_back(c);
	}
}
void findMilk(int aAmt, int bAmt, int cAmt){
	milkamt check;
	check.a=aAmt, check.b=bAmt, check.c=cAmt;
	if(find(used.begin(), used.end(), check)!=used.end()){

		return;
	}else{
		milkamt justused;
		justused.a=aAmt, justused.b=bAmt, justused.c=cAmt;
		used.push_back(justused);
		if(aAmt==0){
			addSolution(cAmt);
		}
		if(aAmt>0){
			int saveda=aAmt, savedb=bAmt, savedc=cAmt;
			//pull a to b
			if(b-bAmt>=aAmt){
				//b had enough for a.
				bAmt+=aAmt;
				aAmt=0;
			}else{
				//b doesnt have enough for a.
				int bspace=b-bAmt;
				aAmt-=bspace;
				bAmt=b;
			}
			findMilk(aAmt, bAmt, cAmt);
			//pull a to c
			aAmt=saveda;
			bAmt=savedb;
			cAmt=savedc;
			saveda=aAmt, savedb=bAmt, savedc=cAmt;
			if(c-cAmt>=aAmt){
				cAmt+=aAmt;
				aAmt=0;
			}else{
				int cspace=c-cAmt;
				aAmt-=cspace;
				cAmt=c;
			}
			findMilk(aAmt, bAmt, cAmt);
			aAmt=saveda;
			bAmt=savedb;
			cAmt=savedc;
		}
		if(bAmt>0){
			int saveda=aAmt, savedb=bAmt, savedc=cAmt;
			if(a-aAmt>=bAmt){
				aAmt+=bAmt;
				bAmt=0;
			}else{
				//b to a
				int aspace=a-aAmt;
				bAmt-=aspace;
				aAmt=a;
			}
			findMilk(aAmt, bAmt, cAmt);
			aAmt=saveda;
			bAmt=savedb;
			cAmt=savedc;
			saveda=aAmt, savedb=bAmt, savedc=cAmt;
			if(c-cAmt>=bAmt){
				cAmt+=bAmt;
				bAmt=0;
			}else{
				//b to c
				int cspace=c-cAmt;
				bAmt-=cspace;
				cAmt=c;
			}
			findMilk(aAmt, bAmt, cAmt);
			aAmt=saveda;
			bAmt=savedb;
			cAmt=savedc;
		}
		if(cAmt>0){
			int saveda=aAmt, savedb=bAmt, savedc=cAmt;
			if(a-aAmt>=cAmt){
				aAmt+=cAmt;
				cAmt=0;
			}else{
				//c to a
				int aspace=a-aAmt;
				cAmt-=aspace;
				aAmt=a;
			}
			findMilk(aAmt, bAmt, cAmt);
			aAmt=saveda;
			bAmt=savedb;
			cAmt=savedc;
			findMilk(aAmt, bAmt, cAmt);
			if(b-bAmt>=cAmt){
				bAmt+=cAmt;
				cAmt=0;
			}else{
				//c to b
				int bspace=b-bAmt;
				cAmt-=bspace;
				bAmt=b;
			}
			findMilk(aAmt, bAmt, cAmt);
			aAmt=saveda;
			bAmt=savedb;
			cAmt=savedc;
		}
	}
}
int main() {
	ifstream fin;
	ofstream fout;
	fin.open("milk3.in");
	fout.open("milk3.out");
	fin>>a>>b>>c;
	findMilk(0, 0, c);
	sort(success.begin(), success.end());
	for(vector<int>::iterator itr=success.begin(); itr!=success.end(); itr++){
		if(*itr!=c){
			fout<<*itr<<" ";
		}else{
			fout<<*itr<<endl;
		}
	}
	fin.close();
	fout.close();
}
