#ifndef MAXIMUM_GATES_H
#define MAXIMUM_GATES_H

#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;


// TODO: Your answer for question 2 goes here

int maximumGates(vector<int> arrives, vector<int> departs) {

	int gatesInUse = 0;
	int maxGates = 0;

	std::sort (departs.begin(), departs.end());
	int i = 0;
	int j = 0;

	while ((i < arrives.size() && j < departs.size())) {

			if (arrives[i] < departs[j]) {
				gatesInUse++;
				i++;
			} else {
				gatesInUse--;
				j++;
			}

			if (maxGates < gatesInUse) {
				maxGates = gatesInUse;
			}
	}
	return maxGates;
}

// Do not write any code below this line


#endif
