//#include <set>
//#include <stdio.h>
//
//using namespace std;
//
//void main()
//{
//	set<int> iSet;
//
//	for (int i = 19; i>0; i -= 3)
//		iSet.insert(i); //역순으로 데이터를 추가한다.
//
//	set<int>::iterator itSet;
//
//	printf("Set : ");
//	for (itSet = iSet.begin(); itSet != iSet.end(); itSet++)
//		printf("%d ", *itSet);//하지만, 결과는 오름차순으로 정렬된 상태!
//	printf("\n");
//
//	for (int i = 1; i <= 10; i++)
//		iSet.insert(i); //기존 데이터에 1부터 10까지 모든 데이터를 추가.
//
//	printf("Set : ");
//	for (itSet = iSet.begin(); itSet != iSet.end(); itSet++)
//		printf("%d ", *itSet); //데이터는 중복되지 않는다.
//	printf("\n");
//
//	for (int i = 0; i <= 19; i += 2)
//		iSet.erase(i); //데이터를 지운다. 데이터가 없어도 에러는 나지않는다.
//
//	printf("Set : ");
//	for (itSet = iSet.begin(); itSet != iSet.end(); itSet++)
//		printf("%d ", *itSet);
//	printf("\n");
//
//
//	set<int>::reverse_iterator ritSet; //내림차순으로 정렬하기
//
//	printf("ReverseSet : ");
//	for (ritSet = iSet.rbegin(); ritSet != iSet.rend(); ritSet++)
//		printf("%d ", *ritSet);
//	printf("\n");
//}

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
	cout << myStack.puch(new NODE(i * 5)) << "\t";
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
