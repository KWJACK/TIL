STL_Stack
=========

STL를 소개하기 전에 링크드 리스트로 구현하는 스택을 설명한다.

(STL의 간편함.., 링크드 리스트가 익숙하지 않다면, STL_Stack으로 바로 넘어갑니다.)

Stack by Linked-List
--------------------

설명에 쓰일 스택의 자료형인 노드 소개

##### NODE 구조

> | 멤버변수                    | 멤버함수         |
> |:---------------------------:|:----------------:|
> |        int형 데이터         | SetData, GetData |
> | 다음 노드를 가리키는 포인터 | SetNext, GetNext |

```
  class NODE
 {
 private:
    int m_data;    //데이터
    NODE* p_next;  //다음 노드를 가리키는 포인터
 public:
    NODE() :m_data(0), p_next(nullptr) {}              //초기화
    NODE(int data) : m_data(data), p_next(nullptr) {}  //생성자 오버로딩
    ~NODE() {}

    void setData(int data) { m_data = data; }          //멤버변수 set,get
    void setNext(NODE* next) { p_next = next; }

    int getData() { return m_data; }    
    NODE* getNext() { return p_next; }
 };
```

#### STACK 구현

스택은 Last In First Out(LIFO)의 구조를 갖는다.

> | 멤버변수      | 멤버함수                                      |
> |:-------------:|:----------------------------------------------|
> | Stack pointer | push : sp의 다음 노드에 새 노드 추가          |
> | Base pointer  | pop : sp가 가리키는 노드 삭제, sp는 이전 노드 |

```
#include "NODE.h"
class mStack
{
private:
    NODE *SP,*BP;//stack pointer, base pointer
public:
    mStack() : SP(nullptr), BP(nullptr) {}
    ~mStack() {}

    int puch(NODE* pNew) {
        if (!BP) {  //베이스 포인터가 없으면 새로 지정
            BP = SP = pNew;
        }
        else {      //베이스가 있으면 SP를 움직여 새 노드를 SP가 가리키는 노드에 추가
            SP->setNext(pNew);
            SP = pNew;  //sp는 새로 추가한 노드를 가리킴
        }
        return pNew->getData(); //없어도 되는 부분.(top)
    }

    int pop() {
		int value = SP->getData();
		NODE* pCur = BP;
		if (BP == SP) {   //스택에 남은 노드가 한 개인 경우
			BP = nullptr;
			delete SP;
		}
		else {
			while (pCur->getNext() != SP)  //SP 이전 노드까지 접근
			{
				pCur = pCur->getNext();
			}
			pCur->setNext(nullptr);  
			delete SP; //SP가 가리키는 노드 삭제
			SP = pCur; //SP는 이전 노드
		}
		return value; //없어도 되는 부분 (pop에서 삭제는 하되 출력은 자유)
	}
};
```

본격 STL_Stack 소개
-------------------

(STL은 Standard Template Library의 약자)

-	템플릿Template 문법이 적용되어 자료형이나, 클래스를 사용자 정의에 따라 제약없이 사용할 수 있다.
-	Stack은 컨테이너 어뎁터의 한 종류(STL 컨테이너 어뎁터는 stack, queue, priority_queue가 있다)
-	컨테이너 어뎁터란? **기존 컨테이너의 인터페이스를 제한하여 만든, 기능이 제한된 컨테이너.**
-	**특징 : 반복자(iterator)를 지원하지 않음. (stack 구조상 당연한 일)**

-	#include \<stack\>으로 추가

```
stack<int> stlStack;
for (int i = 0; i < 10; i++) {
    stlStack.push(i * 5); //데이터 push
 }
for (int i = 0; i < 10; i++) {
   stlStack.pop();      // 데이터 pop
}
  std::cout<< stlStack.size() <<"\n";   // 스택 사이즈
  std::cout<< stlStack.empty() <<"\n";  // 스택이 empty면 TRUE, 아니면 FALSE
```

> ### 부록* Pair 소개
>
> -	pair는 데이터를 쌍으로 묶는다. ex) pair<int, char> pr;
>
> -	클래스 객체이며 마찬가지로 template 문법 적용
>
> -	make_pair를 통해 pair를 생성한다. ex) pr.make_pair(5, 'a')
>

Example(Linked-List Stack, STL_Stack + pair)
--------------------------------------------

```
#include "NODE.h"
#include "mStack.h"
#include "stack_ex.h"
#include <stack>
#include <iostream>
using namespace std;
int main() {
    mStack myStack;
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
    cout << endl;
    return 0;
}
```

#### 출력 결과

![Result](https://cloud.githubusercontent.com/assets/20148930/23029052/9c9f58dc-f4ac-11e6-8575-3d57be95224c.jpg)

Stack 기능 확장해보기
---------------------

-	너무 단순한데? stack의 내용물을 스왑해볼까?
-	컨테이너를 재정의 해봅시다.

```
#include <stack>
#include <iterator>
template <typename T, typename Container = std::deque<T>>
class stack_ex : public std::stack<T, Container>    // STL_Stack을 상속해 stack_ex 정의
{
private:
public:
  using stack_ex::stack::container_type;
  void swap_top() {  //top에 인접 노드를 swap하는 부분
                   //c는 stack을 이루는 container. (<stack>에 선언)
      auto last = c.end();    //c에서 end이므로 가장 최근에 들어간 부분(top)
      auto start = c.begin(); //c에서 begin이므로 stack에 가장 처음 들어간 부분
      auto before_last = std::prev(last,2); //top에서 두 칸 떨어진 애의 prev -> top 이전 노드
      std::iter_swap(start, before_last);   //iter_swap을 이용해 swap
  }
};
```

> ### 실행 예제 코드

```
stack_ex<int> exStack;
    for (int i = 0; i < 6; i++) {
        exStack.push(i +1);
    }
    exStack.swap_top();
    cout << endl;
    for (int i = 0; i < 6; i++) {
        cout << exStack.top()<< "\t";
        exStack.pop();
    }
    cout << endl;
```

#### 출력 결과

**6 1 4 3 2 5**

---

### *왜 이렇게 됬을까?*

6 (5) 4 3 2 (1) -> **6 1 4 3 2 5**

iter_swap에서 before_last(5), start(1) 이기 때문.

container_type으로 받았기 때문에 **stack의 start가 top부분이라고 착각**할 수 있으니 주의한다.
