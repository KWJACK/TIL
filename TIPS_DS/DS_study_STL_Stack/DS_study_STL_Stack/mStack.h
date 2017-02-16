#pragma once
#include "NODE.h"
class mStack
{
private:
	NODE *SP, *BP;//stack pointer, base pointer
public:
	mStack() : SP(nullptr), BP(nullptr) {}
	~mStack() {}

	int puch(NODE* pNew) {
		if (!BP) {
			BP = SP = pNew;
		}
		else {
			SP->setNext(pNew);
			SP = pNew;
		}
		return pNew->getData();
	}

	int pop() {
		int value = SP->getData();
		NODE* pCur = BP;
		if (BP == SP) {
			BP = nullptr;
			delete SP;
		}
		else {
			while (pCur->getNext() != SP)
			{
				pCur = pCur->getNext();
			}
			pCur->setNext(nullptr);
			delete SP;
			SP = pCur;
		}
		return value;
	}
};

