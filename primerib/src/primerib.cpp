/*
ID: colinzh3
PROG: sprime
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

bool checkPrime(int a){
	if(a<=1){
		return false;
	}else if(a<=3){
		return true;
	}else if(a%2==0||a%3==0){
		return false;
	}
	long long i=5;
	while(i*i<=a){
		if(a%i==0||a%(i+2)==0){
			return false;
		}
		i+=6;
	}
	return true;
}
vector<int> allPrimeRibs(int size){
	vector<int> results;
	vector<int> firstrib;
	firstrib.push_back(2), firstrib.push_back(3), firstrib.push_back(5), firstrib.push_back(7);
	if(size==1){
		return firstrib;
	}
	for(vector<int>::iterator itr=firstrib.begin(); itr!=firstrib.end(); itr++){
		if(size==2){
			for(int i=1; i<10; i+=2){
				if(checkPrime((*itr)*10+i)){
					results.push_back((*itr)*10+i);
				}
			}
		}
		if(size==3){
			for(int i=1; i<10; i+=2){
				if(checkPrime((*itr)*10+i)){
					for(int j=1; j<10; j+=2){
						if(checkPrime((*itr)*100+i*10+j)){
							results.push_back((*itr)*100+i*10+j);
						}
					}
				}
			}
		}
		if(size==4){
			for(int i=1; i<10; i+=2){
				if(checkPrime((*itr)*10+i)){
					for(int j=1; j<10; j+=2){
						if(checkPrime((*itr)*100+i*10+j)){
							for(int k=1; k<10; k+=2){
								int temp=(*itr)*1000+i*100+j*10+k;
								if(checkPrime(temp)){
									results.push_back(temp);
								}
							}
						}
					}
				}
			}
		}
		if(size==5){
			for(int i=1; i<10; i+=2){
				if(checkPrime((*itr)*10+i)){
					for(int j=1; j<10; j+=2){
						if(checkPrime((*itr)*100+i*10+j)){
							for(int k=1; k<10; k+=2){
								int temp=(*itr)*1000+i*100+j*10+k;
								if(checkPrime(temp)){
									for(int l=1; l<10; l+=2){
										temp=(*itr)*10000+i*1000+j*100+k*10+l;
										if(checkPrime(temp)){
											results.push_back(temp);
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(size==6){
			for(int i=1; i<10; i+=2){
				if(checkPrime((*itr)*10+i)){
					for(int j=1; j<10; j+=2){
						if(checkPrime((*itr)*100+i*10+j)){
							for(int k=1; k<10; k+=2){
								int temp=(*itr)*1000+i*100+j*10+k;
								if(checkPrime(temp)){
									for(int l=1; l<10; l+=2){
										temp=(*itr)*10000+i*1000+j*100+k*10+l;
										if(checkPrime(temp)){
											for(int m=1; m<10; m+=2){
												if(checkPrime((*itr)*100000+i*10000+j*1000+k*100+l*10+m)){
													results.push_back((*itr)*100000+i*10000+j*1000+k*100+l*10+m);
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(size==7){
			for(int i=1; i<10; i+=2){
				if(checkPrime((*itr)*10+i)){
					for(int j=1; j<10; j+=2){
						if(checkPrime((*itr)*100+i*10+j)){
							for(int k=1; k<10; k+=2){
								int temp=(*itr)*1000+i*100+j*10+k;
								if(checkPrime(temp)){
									for(int l=1; l<10; l+=2){
										temp=(*itr)*10000+i*1000+j*100+k*10+l;
										if(checkPrime(temp)){
											for(int m=1; m<10; m+=2){
												if(checkPrime((*itr)*100000+i*10000+j*1000+k*100+l*10+m)){
													for(int n=1; n<10; n+=2){
														temp=(*itr)*1000000+i*100000+j*10000+k*1000+l*100+m*10+n;
														if(checkPrime(temp)){
															results.push_back(temp);
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(size==8){
			for(int i=1; i<10; i+=2){
				if(checkPrime((*itr)*10+i)){
					for(int j=1; j<10; j+=2){
						if(checkPrime((*itr)*100+i*10+j)){
							for(int k=1; k<10; k+=2){
								int temp=(*itr)*1000+i*100+j*10+k;
								if(checkPrime(temp)){
									for(int l=1; l<10; l+=2){
										temp=(*itr)*10000+i*1000+j*100+k*10+l;
										if(checkPrime(temp)){
											for(int m=1; m<10; m+=2){
												if(checkPrime((*itr)*100000+i*10000+j*1000+k*100+l*10+m)){
													for(int n=1; n<10; n+=2){
														temp=(*itr)*1000000+i*100000+j*10000+k*1000+l*100+m*10+n;
														if(checkPrime(temp)){
															for(int o=1; o<10; o+=2){
																temp=(*itr)*10000000+i*1000000+j*100000+k*10000+l*1000+m*100+n*10+o;
																if(checkPrime(temp)){
																	results.push_back(temp);
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return results;
}
int main() {
	ifstream fin;
	ofstream fout;
	fin.open("sprime.in");
	fout.open("sprime.out");
	int size;
	fin>>size;
	vector<int> ribs=allPrimeRibs(size);
	for(vector<int>::iterator itr=ribs.begin(); itr!=ribs.end(); itr++){
		fout<<*itr<<endl;
	}
	fin.close();
	fout.close();
}
