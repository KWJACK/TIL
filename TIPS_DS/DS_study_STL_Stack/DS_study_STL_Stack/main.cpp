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
//		iSet.insert(i); //�������� �����͸� �߰��Ѵ�.
//
//	set<int>::iterator itSet;
//
//	printf("Set : ");
//	for (itSet = iSet.begin(); itSet != iSet.end(); itSet++)
//		printf("%d ", *itSet);//������, ����� ������������ ���ĵ� ����!
//	printf("\n");
//
//	for (int i = 1; i <= 10; i++)
//		iSet.insert(i); //���� �����Ϳ� 1���� 10���� ��� �����͸� �߰�.
//
//	printf("Set : ");
//	for (itSet = iSet.begin(); itSet != iSet.end(); itSet++)
//		printf("%d ", *itSet); //�����ʹ� �ߺ����� �ʴ´�.
//	printf("\n");
//
//	for (int i = 0; i <= 19; i += 2)
//		iSet.erase(i); //�����͸� �����. �����Ͱ� ��� ������ �����ʴ´�.
//
//	printf("Set : ");
//	for (itSet = iSet.begin(); itSet != iSet.end(); itSet++)
//		printf("%d ", *itSet);
//	printf("\n");
//
//
//	set<int>::reverse_iterator ritSet; //������������ �����ϱ�
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
	cout << " Stack�� �ش� ������ ���� �մϴ�." << endl;
	for (int i = 0; i < 6; i++) {
	cout << myStack.puch(new NODE(i * 5)) << "\t";
	stlStackPair.push(make_pair(i * 5, i * 3));
	}
	cout <<"\n Linked_List Stack ����Դϴ�."<< endl;
	for (int i = 0; i < 6; i++) {
	cout << myStack.pop() << "\t";
	}
	cout <<"\n Pair ��� �Դϴ�."<<endl;
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
