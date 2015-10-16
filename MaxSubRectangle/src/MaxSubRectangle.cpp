//============================================================================
// Name        : MaxSubRectangle.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int maxsubstring(int* _input, int start, int end);

int main() {
	int n, Max = 0;
	scanf("%d", &n);
	int* _table = new int[n * n];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &_table[i * n + j]);
		}
	}
	int* _temptable = new int[n];
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j <= n; j++) {
			int temp = 0;
			for(int k = 0; k < n; k++) {
				for(int d = i; d < j; d++){
					temp += _table[d * n + k];
				}
				_temptable[k] = temp;
				temp = 0;
			}
		int t = maxsubstring(_temptable, 0, n);
		Max = max(Max, t);
		}
	}
	printf("%d\n", Max);
	return 0;
}

int maxsubstring(int* _input, int start_, int end_) {
	int maxleft = 0, maxright = 0, length = end_ - start_, tempsum = 0;
	if(length == 1) return _input[start_];
	for(int i = length / 2 + start_ - 1; i >= start_ ; i--) {
		tempsum += _input[i];
		if(tempsum > maxleft) maxleft = tempsum;
	}
	tempsum = 0;
	for(int i = length / 2 + start_; i < end_; i++) {
		tempsum += _input[i];
		if(tempsum > maxright) maxright = tempsum;
	}
	int max1 = maxsubstring(_input, start_, length / 2 + start_);
	int max2 = maxsubstring(_input, length / 2 + start_, end_);
	return max(maxleft + maxright, max(max1, max2));
}
