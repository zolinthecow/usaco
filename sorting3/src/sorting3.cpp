/*
ID: colinzh3
PROG: sort3
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

deque< vector<int> > tree;

bool sorted(vector<int> vec){
	vector<int> temp=vec;
	sort(vec.begin(), vec.end());
	if(temp==vec){
		return true;
	}else{
		return false;
	}
}
bool oneIsSorted(){
	for(deque< vector<int> >::iterator itr=tree.begin(); itr!=tree.end(); itr++){
		if(sorted(*itr)){
			return true;
		}
	}
	return false;
}

int findChildren(vector<int> numbers){
	int count=0;
	for(vector<int>::iterator itr=numbers.begin()+1; itr!=numbers.end(); itr++){
		for(vector<int>::iterator it=numbers.begin(); it!=itr; it++){
			if(*it>*itr){
				vector<int> temp=numbers;
				temp.at(it-numbers.begin())=*itr;
				temp.at(itr-numbers.begin())=*it;
				tree.push_back(temp);
				count++;
			}
		}
	}
	return count;
}
int buildTree(int count){
	/*if(oneIsSorted()){
		return count;
	}else{
		deque< vector<int> > children;
		for(deque< vector<int> >::iterator itr=tree.begin(); itr!=tree.end(); itr++){
			deque< vector<int> > temp=findChildren(*itr);
			for(deque< vector<int> >::iterator it=temp.begin(); it!=temp.end(); it++){
				children.push_back(*it);
			}
			tree.pop_front();
		}
		for(deque< vector<int> >::iterator its=children.begin(); its!=children.end(); its++){
			tree.push_back(*its);
		}
		return buildTree(count+1);
	}*/
	vector<int> lastOne=tree.back();
	while(!sorted(tree.front())){
		deque< vector<int> >::iterator itr=tree.begin();
		vector<int> layer;
		if((*itr).size()==2){
			count++;
			tree.pop_front();
			vector<int> layer;
			layer.push_back(1), layer.push_back(0);
			tree.push_back(layer);
			continue;
		}
		int acount=findChildren(*itr);
		cout<<acount<<" "<<tree.size()<<endl;
		tree.pop_front();
	}
	return count;
}
int main() {
	ifstream fin;
	ofstream fout;
	fin.open("sort3.in");
	fout.open("sort3.out");
	int a;
	cin>>a;
	vector<int> unsortedNumbers, layer;
	for(int i=0; i<a; i++){
		int temp;
		cin>>temp;
		unsortedNumbers.push_back(temp);
	}
	if(sorted(unsortedNumbers)){
		cout<<0<<endl;
		return 0;
	}
	tree.push_back(unsortedNumbers);
	layer.push_back(1), layer.push_back(0);
	tree.push_back(layer);
	cout<<buildTree(0)<<endl;
	fin.close();
	fout.close();
}
