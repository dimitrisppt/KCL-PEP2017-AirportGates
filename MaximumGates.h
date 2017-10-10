#ifndef MAXIMUM_GATES_H
#define MAXIMUM_GATES_H

#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;


// TODO: Your answer for question 2 goes here

int maximumGates(vector<int> arrives, vector<int> departs) {
	
	int gatesInUse = 0;
	int maxGates = 0;
	
	for (int i=1; i<arrives.size(); i++) {
			
		for (int j=0; j<i; j++) {
			
			if (arrives[i] < departs[j]) {
				gatesInUse++;
				std::cout << gatesInUse << endl;
			} 
			if (maxGates < gatesInUse) {
				maxGates = gatesInUse;
			}
			
		}
		
	
	}
	
	return maxGates;
	
}



// Do not write any code below this line


#endif
