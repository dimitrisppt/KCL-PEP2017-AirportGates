#ifndef STACK_H
#define STACK_H

#include "vector.h"
#include <string>
#include <iostream>



using pep::vector;
using std::string;
using std::endl;
using std::cout;




// TODO: Your code for question 3 goes here
class Stack {
	
	private:
		bool isEmpty;
		vector<double> elements;
		
	public:	
		bool empty() {
			return elements.empty();
		}
		
		double pop() {
			double tempElement = elements.back();
			elements.pop_back();
			return tempElement;
			
		}
		
		void push(double element) {
			elements.push_back(element);
		}
};

double evaluate(string expression) {
	
	Stack stack;
	double num1;
	double num2;
	
	int position = 0;
	int lastpos = 0;
	

	while (!expression.empty() && position < expression.size()) {
		
			
			position = expression.find(' ',lastpos+1);
			
			if(position == -1) {
				position = expression.size();
			}
			if(lastpos != 0) {
				lastpos++;
			}
			
		
			if (expression.substr(lastpos, position-lastpos) == "+") {
				num1 = stack.pop();
				num2 = stack.pop();
				stack.push(num1+num2);
				
				cout << "Push a+b" << endl;
				cout << endl;
				
			} else if (expression.substr(lastpos, position-lastpos) == "-") {
				num1 = stack.pop();
				num2 = stack.pop();
				stack.push(num2-num1);
				
				cout << "Push b-a" << endl;
				
			} else if (expression.substr(lastpos, position-lastpos) == "*") {
				num1 = stack.pop();
				num2 = stack.pop();
				stack.push(num2*num1);
				
				cout << "Push b*a" << endl;
				
			} else if (expression.substr(lastpos, position-lastpos) == "/") {
				num1 = stack.pop();
				num2 = stack.pop();
				stack.push(num2/num1);
				cout << "Push b/a" << endl;
				
			} else {
				stack.push(std::stod(expression.substr(lastpos, position-lastpos)));	
				cout << "Push a" << endl;
			}
			
			lastpos = position;
	
	}

	return stack.pop();
	
}

// Do not write anything below this line

#endif
