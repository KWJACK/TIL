#include "NODE.h"
#include "mStack.h"
#include "stack_ex.h"
#include <stack>
#include <iostream>
using namespace std;
int main() {
	/*mStack myStack;
	stack<pair<int, int>> stlStackPair;
	cout << " Stack에 해당 순서로 삽입 합니다." << endl;
	for (int i = 0; i < 6; i++) {
	cout << myStack.push(new NODE(i * 5)) << "\t";
	stlStackPair.push(make_pair(i * 5, i * 3));
	}
	cout <<"\n Linked_List Stack 출력입니다."<< endl;
	for (int i = 0; i < 6; i++) {
	cout << myStack.pop() << "\t";
	}
	cout <<"\n Pair 출력 입니다."<<endl;
	for (int i = 0; i < 6; i++) {
	cout <<"\""<< stlStackPair.top().first << "," << stlStackPair.top().second << "\"" << "\t";
	stlStackPair.pop();
	}
	cout << endl;*/

	stack_ex<int> exStack;
	for (int i = 0; i < 6; i++) {
		exStack.push(i + 1);
	}
	exStack.swap_top();
	cout << endl;
	for (int i = 0; i < 6; i++) {
		cout << exStack.top() << "\t";
		exStack.pop();
	}
	cout << endl;

	return 0;
}
