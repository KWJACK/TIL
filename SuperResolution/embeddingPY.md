# 파이썬 모듈 to CPP
- `extending` 파이썬에서 빠른 처리가 필요하는 코드를  cpp에서 실행
- `exbedding` cpp에서 유연한 처리가 필요한 코드를 python에서 실행


## Embedding Setup Tutorial

1. 프로젝트를 Debug에서 Release로 변경
- (Debug에서도 하는 방법이 제시되어 있지만 해보진 않았음 http://kjk92.tistory.com/28)

2. 예제 코드 작성
```
#include <Python.h>
int main(int argc, char *argv[])
{
	Py_SetProgramName(argv[0]);
	Py_SetPythonHome("C:/Python27");
	Py_Initialize();
	PyRun_SimpleString("print 'Hello World'");

	Py_Finalize();
	return 0;
}
```

3. 프로젝트 속성 변경
- C:Python27\\include 경로를 다음에서 추가
- `프로젝트`-`속성`-`C/C++`-`일반`-`추가 포함 디렉터리`

![1](/assets/1.PNG)
(이 단계가 지켜지지 않으면 #include<Python.h> 가 안됨)
- C:Python27\\Lib 경로를 다음에서 추가
- `프로젝트`-`속성`-`링커`-`일반`-`추가 라이브러리 디렉터리`

![2](/assets/2.PNG)

	(이 단계가 지켜지지 않으면 python27_d.lib 파일을 열 수 없다는 에러 발생. d는 debug. 이 에러를 보면 release로 바꿔서 실행)

## func 메뉴얼
https://docs.python.org/2/c-api/init.html#PySys_SetArgv
- `PySys_SetArgvEx(int argc, char **argv, int updatepath)`
:main()의 argc, argv를 파이썬에 전달하는 함수
 updatepath != 0 이면 argv[0]의 절대 경로가 sys.path 목록 처음에 삽입
만약 argv[0]경로 정확치 않다면 상대 경로 "."이 목록 처음 삽입


- `PySys_SetArgv(int argc, char **argv)`
:축약형. updatepath=1.

- `PyRun_SimpleString`

- `Py_GetPath()`
: sys.path에 있는 모든 path 출력
