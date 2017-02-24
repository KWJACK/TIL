__STL_Set__
=======

set은 데이터 중복없이, 빠르게 정렬(정렬되있으니 __검색도 유리__)하고자 할 때 쓰는 컨테이너이다.

 ( Default 정렬은 비교 클래스인 less()가 설정되있다. )

내부 구조는 [Black_Red Tree](https://github.com/KWJACK/TIL/blob/master/TIPS_DS/Red_Black_Tree.md)로 구성되어 있다. 트리이므로 자료 검색의 복잡도는 O(lgN)이다.

접근은 iterator를 통해 가능하고, reverse_iterator를 활용해 rbegin, rend도 사용가능하다.

set 클래스에서 제공하는 멤버함수를 다음 예를 통해 살펴본다.
```
// http://newms.tistory.com/39 의 자료를 가져왔습니다.
#include <set>
#include <stdio.h>

using namespace std;
void main()
{
    set<int> iSet;

    for (int i = 19; i>0; i -= 3)
        iSet.insert(i); //역순으로 데이터를 추가한다.

    set<int>::iterator itSet;

    printf("Set : ");
    for (itSet = iSet.begin(); itSet != iSet.end(); itSet++)
        printf("%d ", *itSet);//하지만, 결과는 오름차순으로 정렬된 상태!
    printf("\n");

    for (int i = 1; i <= 10; i++)
        iSet.insert(i); //기존 데이터에 1부터 10까지 모든 데이터를 추가.

    printf("Set : ");
    for (itSet = iSet.begin(); itSet != iSet.end(); itSet++)
        printf("%d ", *itSet); //데이터는 중복되지 않는다.
    printf("\n");

    for (int i = 0; i <= 19; i += 2)
        iSet.erase(i); //데이터를 지운다. 데이터가 없어도 에러는 나지않는다.

    printf("Set : ");
    for (itSet = iSet.begin(); itSet != iSet.end(); itSet++)
        printf("%d ", *itSet);
    printf("\n");


    set<int>::reverse_iterator ritSet; //내림차순으로 정렬하기

    printf("ReverseSet : ");
    for (ritSet = iSet.rbegin(); ritSet != iSet.rend(); ritSet++)
        printf("%d ", *ritSet);
    printf("\n");
}
```
실행 결과
-----

![setResult](https://cloud.githubusercontent.com/assets/20148930/23121360/64a95e56-f7a3-11e6-9abc-76ad497e1ea6.jpg)


Set의 확장
=====
#### (Ref. std::set cpluscplus)
- Default는 오름차순인데 내림차순으로 쓰고 싶다거나
- 기본타입(int, double ,...)이 아닌 사용자타입에 대해 set을 적용하는 방법에 대해 살펴 본다.

```
#include <set>
#include <iostream>
#include <functional>

bool fncomp(int lhs, int rhs) { return lhs > rhs; } //기존 set의 오름차순을 -> 내림 차순 정렬로 변경

class classcomp {					//struct으로 선언해도 된다.
public:								//private이면 에러
  bool operator() (const int& lhs, const int& rhs) const
  {
    return lhs > rhs;			//기존 set의 오름차순을 -> 내림 차순 정렬로 변경
  }
};

int main() {

	std::set<int> first;                           // empty set of ints

	int myints[] = { 10,20,30,40,50 };
	std::set<int> second(myints, myints + 5);        // range

	std::set<int> third(second);                         // a copy of second
	std::set<int> fourth(second.begin(), second.end());  // iterator ctor.

	//클래스를 이용해 선언하는 방법
	std::set<int, classcomp> fifth;                 
	for(int i=1;i<=5;i++)
		fifth.insert(10*i);

	//함수 포인터로 선언하는 방법
	bool(*fn_pt)(int, int) = fncomp;
	std::set<int, bool(*)(int, int)> sixth(fn_pt);   
	for (int i = 1; i<=5; i++)
		sixth.insert(10*i);

	//for each 출력방법
	for (auto& a : second) {
		std::cout<< a<<" ";
	}
	std::cout << "\n";

	//iterator를 이용한 출력
	std::set<int>::iterator set_it = fifth.begin();
	for(;set_it != fifth.end();set_it++)
		std::cout << *set_it << " ";
	std::cout << "\n";

	//간단하게 내림차순은 비교연산자 클래스 greater(오름차순)로 가능하다(...)
	//less랑 greater의 의미는 최상위 index를 less냐 greater냐 하는 관점
	std::set<int, std::greater<int> > seventh; //greater는 functional에서 제공

	return 0;
}
```
__당연한 말이지만 <=나 >=로 연산자를 설정하면 에러가 난다 ...__


## Set을 사용자 타입으로 생성
```
// ... 헤더 생략
struct TIPS {
	int order;     //member variables
	int age;
	double score;

	TIPS(int o, int e, double s) : order(o), age(e),score(s) {}  //constructor

	bool operator<(const TIPS& rhs) const {
		return this->order < rhs.order;    //first condition  (less)
	}  

	friend std::ostream& operator<<(std::ostream& os, const TIPS& obj) {
		os << obj.order << " :: " << obj.age << " :: " << obj.score;
		return os;                        //출력용
	}
};

struct orderLess{
	bool operator()(const TIPS& lhs, const TIPS& rhs) const
	{		
		return (lhs < rhs);  //set정렬에 쓰일 규칙을 재정의합니다.
	}
};


int main() {
	std::set<TIPS, orderLess> s;     //class +
	for (int i = 0; i < 5; ++i) {
		s.insert(TIPS(15 - i, i, (double)i / 10 * 3));
	}
	for (int i = 0; i < 10; i++) {
		s.insert(TIPS(16 + i, i, (double)i / 10 * 5));
	}
	std::cout << "order::age::score" << std::endl;
	std::copy(s.begin(), s.end(), std::ostream_iterator<TIPS>(std::cout, "\n"));
    //copy() by <algorithm>
    //copy는 시작부터 끝(개구간) 범위를 복사해 세번째 인자로 넘겨준다.
    //ostream_iterator를 이용해 반복자로 각 element 출력
	return 0;
```
### 주의사항

비교조건에 opertor == 을사용하지 않도록 한다. set의 기본 형태를 위반하기도 하고
set에서 find할 시 operator== 이 사용되기 때문
ex)
bool operator==(const TIPS& rhs) const {  
     return this->age == rhs.age;
}
---

#### 여기까지, set에 대해 알아보았다.
set의 확장형인, [multiset]()에서는 equal_range(), lower_bound(), upper_bound()에 대해 살펴본다.
