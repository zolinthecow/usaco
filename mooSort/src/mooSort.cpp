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
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;

int *nums;

int mooCount(int a){
	int count=0;
	bool sorted=false;
	while(!sorted){
		sorted=true;
		bool swapped=false;
		count++;
		for(int i=0; i<a-1; i++){
			if(nums[i+1]<nums[i]){
				swap(nums[i], nums[i+1]);
				/*int first=nums[i+1];
				nums[i+1]=nums[i];
				nums[i]=first;*/
				sorted=false;
				swapped=true;
			}
		}
		if(swapped==false){
			break;
		}
	}
	return count;
}
int main() {
	ifstream fin;
	ofstream fout;
	fin.open("sort.in");
	fout.open("sort.out");
	int a;
	cin>>a;
	nums=new int[a];
	for(int i=0; i<a; i++){
		cin>>nums[i];
	}
	cout<<mooCount(a)<<endl;
	fin.close();
	fout.close();
}
