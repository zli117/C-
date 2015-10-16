//============================================================================
// Name        : The_Triangle.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;

int solve(int layer, int slot, int* _dptable, int* _input);

int main() {
	int* _dptable, * _input, inputlength;
	scanf("%d", &n);
	inputlength = (1 + n) * n / 2;
	_dptable = new int[n * n];
	_input = new int[inputlength];
	//printf("inputlength = %d\n", inputlength);
	for(int i = 0; i < inputlength; i++) {
		scanf("%d", _input + i);
	}
	/*for(int i = 0; i < n * n; i++) {
		_dptable[i] = 0;
	}*/
	std::fill(_dptable, _dptable + n * n - 1, 0);
	int Max = solve(0, 0, _dptable, _input);
	printf("%d", Max);
	return 0;
}

int solve(int layer, int slot, int* _dptable, int* _input) {
	if(layer == n - 1) return _input[(1 + layer) * layer / 2 + slot];
	if(_dptable[layer * n + slot] != 0) return _dptable[layer * n + slot];
	int Maxchild = max(solve(layer + 1, slot, _dptable, _input),
			solve(layer + 1, slot + 1, _dptable, _input));
	int Max = Maxchild + _input[(1 + layer) * layer / 2 + slot];
	_dptable[layer * n + slot] = Max;
	return Max;
}
