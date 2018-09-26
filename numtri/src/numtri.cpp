/*
ID: colinzh3
PROG: numtri
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

int **tree;
int a;

void getBiggestCombos(){
	for(int i=1; i<a; i++){
		for(int j=0; j<a; j++){
			if(tree[i][j]==-1){
				break;
			}
			if(j==0){
				tree[i][j]+=tree[i-1][j];
			}else if(j==i){
				tree[i][j]+=tree[i-1][j-1];
			}else{
				int first, second;
				first=tree[i][j]+tree[i-1][j];
				second=tree[i][j]+tree[i-1][j-1];
				if(first>second){
					tree[i][j]=first;
				}else{
					tree[i][j]=second;
				}
			}
		}
	}
}
int main() {
	ifstream fin;
	ofstream fout;
	fin.open("numtri.in");
	fout.open("numtri.out");
	fin>>a;
	tree=new int*[a];
	for(int l=0; l<a; l++){
		tree[l]=new int[a];
	}
	for(int i=1; i<=a; i++){
		for(int j=0; j<i; j++){
			int b;
			fin>>b;
			tree[i-1][j]=b;
		}
		for(int k=i; k<a; k++){
			tree[i-1][k]=-1;
		}
	}
	getBiggestCombos();
	int max=0;
	for(int m=0; m<a; m++){
		if(tree[a-1][m]>max){
			max=tree[a-1][m];
		}
	}
	fout<<max<<endl;
	fin.close();
	fout.close();
}
