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

int size;
int **board;
map< pair<int, int>, vector< pair<int, int> > > switchRooms;

int fillBoard(pair<int, int> room){
	int height=room.first, width=room.second;
	if(board[height][width]==1){
		return 0;
	}else if(switchRooms.find(room)==switchRooms.end()){
		board[height][width]=1;
		return 1;
	}else{
		board[height][width]=1;
		int topCount=0, bottomCount=0, leftCount=0, rightCount=0;
		if(height==0 && width==0){
			pair<int, int> bottom;
			bottom.first=height+1, bottom.second=width;
			if(switchRooms.find(bottom)!=switchRooms.end()){
				bottomCount+=fillBoard(bottom);
			}
			pair<int, int>right;
			right.first=height, right.second=width+1;
			if(switchRooms.find(right)!=switchRooms.end()){
				rightCount=+fillBoard(right);
			}
		}else if(height==0 && width==size-1){
			pair<int, int> bottom;
			bottom.first=height+1, bottom.second=width;
			if(switchRooms.find(bottom)!=switchRooms.end()){
				bottomCount+=fillBoard(bottom);
			}
			pair<int, int>left;
			left.first=height, left.second=width-1;
			if(switchRooms.find(left)!=switchRooms.end()){
				leftCount+=fillBoard(left);
			}
		}else if(height==size-1 && width==0){
			pair<int, int> top;
			top.first=height-1, top.second=width;
			if(switchRooms.find(top)!=switchRooms.end()){
				topCount+=fillBoard(top);
			}
			pair<int, int>right;
			right.first=height, right.second=width+1;
			if(switchRooms.find(right)!=switchRooms.end()){
				rightCount=+fillBoard(right);
			}
		}else if(height==size-1 && width==size-1){
			pair<int, int> top;
			top.first=height-1, top.second=width;
			if(switchRooms.find(top)!=switchRooms.end()){
				topCount+=fillBoard(top);
			}
			pair<int, int>left;
			left.first=height, left.second=width-1;
			if(switchRooms.find(left)!=switchRooms.end()){
				leftCount+=fillBoard(left);
			}
		}else if(height==0){
			pair<int, int> bottom;
			bottom.first=height+1, bottom.second=width;
			if(switchRooms.find(bottom)!=switchRooms.end()){
				bottomCount+=fillBoard(bottom);
			}
			pair<int, int>left;
			left.first=height, left.second=width-1;
			if(switchRooms.find(left)!=switchRooms.end()){
				leftCount+=fillBoard(left);
			}
			pair<int, int>right;
			right.first=height, right.second=width+1;
			if(switchRooms.find(right)!=switchRooms.end()){
				rightCount=+fillBoard(right);
			}
		}else if(width==0){
			pair<int, int> top;
			top.first=height-1, top.second=width;
			if(switchRooms.find(top)!=switchRooms.end()){
				topCount+=fillBoard(top);
			}
			pair<int, int>right;
			right.first=height, right.second=width+1;
			if(switchRooms.find(right)!=switchRooms.end()){
				rightCount=+fillBoard(right);
			}
			pair<int, int> bottom;
			bottom.first=height+1, bottom.second=width;
			if(switchRooms.find(bottom)!=switchRooms.end()){
				bottomCount+=fillBoard(bottom);
			}
		}else if(height==size-1){
			pair<int, int> top;
			top.first=height-1, top.second=width;
			if(switchRooms.find(top)!=switchRooms.end()){
				topCount+=fillBoard(top);
			}
			pair<int, int>right;
			right.first=height, right.second=width+1;
			if(switchRooms.find(right)!=switchRooms.end()){
				rightCount=+fillBoard(right);
			}
			pair<int, int>left;
			left.first=height, left.second=width-1;
			if(switchRooms.find(left)!=switchRooms.end()){
				leftCount+=fillBoard(left);
			}
		}else if(width==size-1){
			pair<int, int> bottom;
			bottom.first=height+1, bottom.second=width;
			if(switchRooms.find(bottom)!=switchRooms.end()){
				bottomCount+=fillBoard(bottom);
			}
			pair<int, int>left;
			left.first=height, left.second=width-1;
			if(switchRooms.find(left)!=switchRooms.end()){
				leftCount+=fillBoard(left);
			}
			pair<int, int> top;
			top.first=height-1, top.second=width;
			if(switchRooms.find(top)!=switchRooms.end()){
				topCount+=fillBoard(top);
			}
		}else{
			pair<int, int> bottom;
			bottom.first=height+1, bottom.second=width;
			if(switchRooms.find(bottom)!=switchRooms.end()){
				bottomCount+=fillBoard(bottom);
			}
			pair<int, int>left;
			left.first=height, left.second=width-1;
			if(switchRooms.find(left)!=switchRooms.end()){
				leftCount+=fillBoard(left);
			}
			pair<int, int> top;
			top.first=height-1, top.second=width;
			if(switchRooms.find(top)!=switchRooms.end()){
				topCount+=fillBoard(top);
			}
			pair<int, int>right;
			right.first=height, right.second=width+1;
			if(switchRooms.find(right)!=switchRooms.end()){
				rightCount=+fillBoard(right);
			}
		}
		return topCount+bottomCount+leftCount+rightCount;
	}
}
int main() {
	int amount;
	cin>>size>>amount;
	board=new int*[size];
	for(int i=0; i<size; i++){
		board[i]=new int[size];
	}
	for(int j=0; j<amount; j++){
		int x, y, a, b;
		cin>>x>>y>>a>>b;
		pair<int, int> withSwitch, switchLight;
		x-=1, y-=1, a-=1, b-=1;
		withSwitch.first=x, withSwitch.second=y, switchLight.first=a, switchLight.second=b;
		(switchRooms[withSwitch]).push_back(switchLight);
	}
	pair<int, int> first;
	first.first=0, first.second=0;
	cout<<fillBoard(first)<<endl;
}
