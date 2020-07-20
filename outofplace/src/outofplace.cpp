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

int swapSort(vector<int> cows){
	vector<int> sortedCows=cows;
	sort(sortedCows.begin(), sortedCows.end());
	int count=0;
	while(cows!=sortedCows){
		int outOfPlace;
		for(unsigned int i=0; i<sortedCows.size(); i++){
			if(cows[i]!=sortedCows[i]){
				outOfPlace=i;
				break;
			}
		}
		for(unsigned int j=0; j<sortedCows.size(); j++){
			int swap1=cows[j];
			int swap2=cows[outOfPlace];
			if(sortedCows[j]==cows[outOfPlace] && swap1!=swap2){
				cows[j]=swap2, cows[outOfPlace]=swap1;
				break;
			}
		}
		count++;
	}
	return count;
}
int main() {
	ifstream fin;
	ofstream fout;
	fin.open("outofplace.in");
	fout.open("outofplace.out");
	int amount;
	cin>>amount;
	vector<int> cows;
	for(int i=0; i<amount; i++){
		int a;
		cin>>a;
		cows.push_back(a);
	}
	cout<<swapSort(cows)<<endl;
	fin.close();
	fout.close();
}
