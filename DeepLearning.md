# Deep learning 정리글
매우 매우 초보.

**regression**
> 변수 간의 관계를 추측해나가는 것.
    ex)토지와 집의 상관관계 linear regression : 선형 회귀

**머신러닝**
 > 큰 데이터에 담긴많은 사례(example)을 제공,  학습결과를 바탕으로 데이터가 없는 경우에도 추론을 통해 답을 낼 수 있도록 만드는 것
 > - regression analysis에서 현재 가설이 얼마나 맞았는지 틀렸는지 **오류의 양**을 측정, 그 요유를 줄어나가면서 인공지능을 학습

**numerical optimization**
> 가설의 오류가 이상적으로 0이되는 적당한 가설을 찾는 과정에 적용되는 방법(기술)

**MSE**
> 모든 사례들에 대해 오차의 제곱을 더해 평균을 내는 것
> *전반적으로 얼마나 틀렸는지*를 파악하기 위해 사용

**feature scaling**
> 서로 다른 두 변수의 범위를 비슷하게 맞춰주는 것

### 토막상식
#include <assert.h>
assert()는 주어진 조건이 거짓이면 오류 메시지를 출력하고 프로그램을 종료한다
```
int a=100, b=0;
aseert(b!=0);

--> 중지됨.
```
 assert 함수를 프로젝트에서 많이 활용했는데, 프로그램 최종 빌드시 assert를 제외하는 방법
#define NDEBUG 를 #include <assert.h> 앞에 선언하면 자동으로 assert()코드를 제거하고 컴파일

converge : 수렴
