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

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("shuffle.in");
	fout.open("shuffle.out");
	int a;
	fin>>a;
	int *positions;
	positions=new int[a];
	int *cows;
	cows=new int[a];
	for(int i=0; i<a; i++){
		int z;
		fin>>z;
		z-=1;
		positions[i]=z;
	}
	for(int j=0; j<a; j++){
		fin>>cows[j];
	}
	for(int k=0; k<3; k++){
		int *cowcopy;
		cowcopy=new int[a];
		for(int l=0; l<a; l++){
			cowcopy[l]=cows[ positions[l] ];
		}
		for(int m=0; m<a; m++){
			cows[m]=cowcopy[m];
		}
	}
	for(int n=0; n<a; n++){
		fout<<cows[n]<<endl;
	}
	fin.close();
	fout.close();
}
