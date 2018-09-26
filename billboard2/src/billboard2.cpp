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
	fin.open("billboard.in");
	fout.open("billboard.out");
	int feedBillboard[4], lawnmowerBillboard[4], xmax=0, ymax=0, xmin=1001, ymin=1001, **board;
	for(int i=0; i<2; i++){
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
			lawnmowerBillboard[0]=x1, lawnmowerBillboard[1]=y1, lawnmowerBillboard[2]=x2, lawnmowerBillboard[3]=y2;
		}else if(i==1){
			feedBillboard[0]=x1, feedBillboard[1]=y1, feedBillboard[2]=x2, feedBillboard[3]=y2;
		}
	}
	if(lawnmowerBillboard[0]==feedBillboard[0] && lawnmowerBillboard[2]==feedBillboard[2] && lawnmowerBillboard[1]<feedBillboard[1] && lawnmowerBillboard[3]>feedBillboard[3]){
		int firsta=lawnmowerBillboard[2]-lawnmowerBillboard[0], firstb=lawnmowerBillboard[3]-lawnmowerBillboard[1];
		cout<<firsta*firstb<<endl;
		return 0;
	}
	if(lawnmowerBillboard[1]==feedBillboard[1] && lawnmowerBillboard[3]==feedBillboard[3] && lawnmowerBillboard[0]<feedBillboard[0] && lawnmowerBillboard[2]>feedBillboard[2]){
		int firsta=lawnmowerBillboard[2]-lawnmowerBillboard[0], firstb=lawnmowerBillboard[3]-lawnmowerBillboard[1];
		cout<<firsta*firstb<<endl;
		return 0;
	}
	xmin=abs(xmin), ymin=abs(ymin);
	lawnmowerBillboard[0]+=xmin, lawnmowerBillboard[1]+=ymin, lawnmowerBillboard[2]+=xmin, lawnmowerBillboard[3]+=ymin;
	feedBillboard[0]+=xmin, feedBillboard[1]+=ymin, feedBillboard[2]+=xmin, feedBillboard[3]+=ymin;
	xmax+=xmin+2, ymax+=ymin+2;
	board=new int*[ymax];
	for(int j=0; j<ymax; j++){
		board[j]=new int[xmax];
	}
	for(int k=lawnmowerBillboard[3]; k>lawnmowerBillboard[1]; k--){
		for(int l=lawnmowerBillboard[2]; l>lawnmowerBillboard[0]; l--){
			board[k][l]=4;
		}
	}
	for(int m=feedBillboard[3]; m>feedBillboard[1]; m--){
		for(int n=feedBillboard[2]; n>feedBillboard[0]; n--){
			board[m][n]=5;
		}
	}
	int topcount=0, bottomcount=0, rightcount=0, leftcount=0;
	for(int q=lawnmowerBillboard[2]; q>lawnmowerBillboard[0]; q--){
		if(board[lawnmowerBillboard[3] ][q]==4){
			topcount++;
		}
		if(board[lawnmowerBillboard[1] +1][q]==4){
			bottomcount++;
		}
	}
	for(int r=lawnmowerBillboard[3]; r>lawnmowerBillboard[1]; r--){
		if(board[r][lawnmowerBillboard[2] ]==4){
			leftcount++;
		}
		if(board[r][lawnmowerBillboard[0] +1]==4){
			rightcount++;
		}
	}
	for(int ab=0; ab<ymax; ab++){
		for(int cd=0; cd<xmax; cd++){
			cout<<board[ab][cd];
		}
		cout<<endl;
	}
	int greaterUp, greaterSide;
	if(topcount>bottomcount){
		greaterUp=topcount;
	}else{
		greaterUp=bottomcount;
	}
	if(rightcount>leftcount){
		greaterSide=rightcount;
	}else{
		greaterSide=leftcount;
	}
	delete[] board;
	cout<<greaterSide*greaterUp<<endl;
	fin.close();
	fout.close();
}
