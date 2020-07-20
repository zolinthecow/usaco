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

int ** board;


int main() {
	ifstream fin;
	ofstream fout;
	fin.open("billboard.in");
	fout.open("billboard.out");
	int dimensions1[4], dimensions2[4], truck[4];
	int xmax=0, ymax=0, ocount=0, tcount=0, xmin=1001, ymin=1001;
	for(int i=0; i<3; i++){
		int x1, y1, x2, y2;
		cin>>x1>>y1>>x2>>y2;
		if(x1>xmax){
			xmax=x1;
		}
		if(x2>xmax){
			xmax=x2;
		}
		if(y1>ymax){
			ymax=y1;
		}
		if(y2>ymax){
			ymax=y2;
		}
		if(x1<xmin){
			xmin=x1;
		}
		if(x2<xmin){
			xmin=x2;
		}
		if(y1<ymin){
			ymin=y1;
		}
		if(y2<ymin){
			ymin=y2;
		}
		if(i==0){
			dimensions1[0]=x1, dimensions1[1]=y1, dimensions1[2]=x2, dimensions1[3]=y2;
		}else if(i==1){
			dimensions2[0]=x1, dimensions2[1]=y1, dimensions2[2]=x2, dimensions2[3]=y2;
		}else{
			truck[0]=x1, truck[1]=y1, truck[2]=x2, truck[3]=y2;
		}

	}
	xmin=abs(xmin), ymin=abs(ymin);
	dimensions1[0]+=xmin, dimensions1[1]+=ymin, dimensions1[2]+=xmin, dimensions1[3]+=ymin;
	dimensions2[0]+=xmin, dimensions2[1]+=ymin, dimensions2[2]+=xmin, dimensions2[3]+=ymin;
	truck[0]+=xmin, truck[1]+=ymin, truck[2]+=xmin, truck[3]+=ymin;
	xmax+=xmin+1, ymax+=ymin+1;
	board=new int*[ymax];
	for(int j=0; j<ymax; j++){
		board[j]=new int[xmax];
	}
	/*for(int y=0; y<ymax; y++){
		for(int z=0; z<xmax; z++){
			board[y][z]=-1;
		}
	}*/
	for(int k=dimensions1[3]; k>dimensions1[1]; k--){
		for(int l=dimensions1[2]; l>dimensions1[0]; l--){
			board[k][l]=5;
			ocount++;
		}
	}
	for(int m=dimensions2[3]; m>dimensions2[1]; m--){
		for(int n=dimensions2[2]; n>dimensions2[0]; n--){
			board[m][n]=5;
			ocount++;
		}
	}
	for(int o=truck[3]; o>truck[1]; o--){
		for(int p=truck[2]; p>truck[0]; p--){
			if(board[o][p]==5){
				tcount++;
			}
			board[o][p]=1;
		}
	}
	cout<<ocount-tcount<<endl;
	fin.close();
	fout.close();
}
