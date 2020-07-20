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

map<int, vector<int> > board;
int checkRooms(){
	queue<int> searchTree;
	vector<int> litRooms;
	searchTree.push(0);
	int amount=0;
	while(searchTree.size()!=0){
		if((find(litRooms.begin(), litRooms.end(), searchTree.front())!=litRooms.end()) && amount!=0){
			searchTree.pop();
			continue;
		}
		litRooms.push_back(searchTree.front());
		if(board.find(litRooms.back())!=board.end()){
			vector<int> node=board[litRooms.back()];
			vector<int> possibilities;
			for(vector<int>::iterator it=node.begin(); it!=node.end(); it++){
				possibilities.push_back(*it);
			}
			for(vector<int>::iterator itr=possibilities.begin(); itr!=possibilities.end(); itr++){
				if((*itr/3-1==litRooms.back()/3 || *itr/3+1==litRooms.back()/3 || *itr%3-1==litRooms.back()%3 || *itr%3+1==litRooms.back()%3)||(find(possibilities.begin(), possibilities.end(), *itr/3-1)!=possibilities.end() || find(possibilities.begin(), possibilities.end(), *itr/3+1)!=possibilities.end() || find(possibilities.begin(), possibilities.end(), *itr%3-1)!=possibilities.end() || find(possibilities.begin(), possibilities.end(), *itr%3+1)!=possibilities.end())){
							searchTree.push(*itr);
				}else{
					litRooms.push_back(*itr);
				}
			}
			searchTree.pop();
		}else if(board.find(litRooms.front())==board.end()){
			searchTree.pop();
		}
		amount++;
	}
	return litRooms.size();
}
int main() {
	int dimensions, amount;
	cin>>dimensions>>amount;
	for(int i=0; i<amount; i++){
		int x, y, a, b;
		cin>>x>>y>>a>>b;
		int withSwitch, switchLight;
		x-=1, y-=1, a-=1, b-=1;
		withSwitch=x+y*dimensions, switchLight=a+b*dimensions;
		(board[withSwitch]).push_back(switchLight);
	}
	cout<<checkRooms()<<endl;
}
