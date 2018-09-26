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

bool sorted(vi numbers){
	vi numbersCopy=numbers;
	sort(numbersCopy.begin(), numbersCopy.end());
	if(numbers==numbersCopy){
		return true;
	}
	return false;
}
int main() {
	ifstream fin;
	ofstream fout;
	fin.open("sort.in");
	fout.open("sort.out");
	int a;
	cin>>a;
	vi numbers;
	for(int i=0; i<a; i++){
		int temp;
		cin>>temp;
		numbers.push_back(temp);
	}
	vi numbersCopy=numbers;
	int count=0;
	sort(numbersCopy.begin(), numbersCopy.end());
	for(int i=a-1; i>=0; i--){
		if(numbersCopy[i]!=numbers[i]){
			count++;
			numbersCopy.erase(numbersCopy.begin()+i);
			numbers.erase(numbers.begin()+i);
			i--;
			a--;
		}
	}
	cout<<count+1<<endl;
	fin.close();
	fout.close();
}
