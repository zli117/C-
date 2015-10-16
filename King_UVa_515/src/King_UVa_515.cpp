//============================================================================
// Name        : King_UVa_515.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct point {
	vector<point*> minus;
	vector<int> values;
	int visited = 0;
	int value = 100;
	int name;
	int outdegree = 0;
};

bool toposort(point* p);

int main() {
	int n, m, from, to, value;
	char comparision[3];
	while (true) {
		scanf("%d", &n);
		if (n == 0)
			break;
		scanf("%d", &m);
		bool result = true;
		point* points = new point[n + 1];
		for (int i = 0; i < n + 1; i++) {
			points[i].name = i;
		}
		for (int i = 0; i < m; i++) {
			scanf("%d%d%s%d", &from, &to, comparision, &value);
			to = to + from;
			from--;
			if (comparision[0] == 'g') {
				value++;
			}
			if (comparision[0] == 'l') {
				to = to + from;
				from = to - from;
				to = to - from;
				//value = 0 - value;
				value--;
				value = -value;
			}
			//printf("from %d, to %d, value %d\n", from, to, value);
			points[to].minus.push_back(&points[from]);
			points[to].values.push_back(value);
			points[to].outdegree++;
		}
		for (int i = 0; i < n + 1; i++) {
			result = result && toposort(&points[i]);
		}
		if (result)
			cout << "true" << endl;
		else
			cout << "false" << endl;
		delete[] points;
	}
	return 0;
}

bool toposort(point* p) {
	queue<point*> Queue;
	Queue.push(p);
	while (Queue.size() > 0) {
		point* _current = Queue.front();
		Queue.pop();
		//_current->visited = 1;
		for (int i = 0; i < _current->outdegree; i++) {
			int maximum = _current->value - _current->values[i];
			//printf("current at %d, with value = %d, visiting %d, with value = %d, maximum = %d\n", _current->name, _current->value, _current->minus[i]->name, _current->minus[i]->value, maximum);
			//printf("current at %d, visited = %d, visiting %d, visited %d\n", _current->name, _current->visited, _current->minus[i]->name, _current->minus[i]->visited);
			if (_current->minus[i]->visited == 0) {
				//cout << "first visit" << endl;
				_current->minus[i]->value = maximum;
			} else if (_current->minus[i]->value > maximum) {
				//cout << "returned false" << endl;
				return false;
			} else {
				_current->minus[i]->value = maximum;
			}
			if (_current->minus[i]->visited == 0) {
				Queue.push(_current->minus[i]);
				_current->minus[i]->visited = 1;
			}
		}
	}
	return true;
}
