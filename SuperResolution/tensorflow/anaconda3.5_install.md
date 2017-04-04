# Anaconda3.5 설치 & 오류 해결 방법

설치 오류가 나지 않는다면 다음 블로그를 참고하여 설치한다.(잘 되있음)
https://brunch.co.kr/@mapthecity/15

## python 3.5 설치
- 아나콘다 공식홈페이지에 접속
- 3.6버전이 올라와있는 관계로 zip파일을 통해 구버전인 3.5를 받는다.
- 윈도우즈에서도 tensorflow를 실행하려면 3.5 버전이 있어야하기 때문

![1](/assets/1_fvy51j60b.JPG)


## 오류 발생
 위와 같이 설치했는데 오류가 뜨는 경우가 있다.
 아래부터는 해결책에 대한 정리 글이다.
#### 설치 오류 현상
- https://github.com/ContinuumIO/anaconda-issues/issues/732 와 같은 증상이다
- 즉, zip 파일을 풀고 설치 파일을 통해 install을 하였건만, 설치 마지막에 설치 오류가 났다고 뜨는 오류이다.

- 이 오류는 Anaconda prompt가 뜨지 않는다.
- 제어판에서 uninstall할 수 없다.

## 오류 해결 1
`아래 모든 해결 방법에서 cmd 환경은 관리자권한이여야 함!`

cmd에서 마법의 주문을 친다. (경로는 anaconda3 설치 위치여야함.)
```
"C:\Program Files\Anaconda3\pythonw.exe" -E -s "C:\Program Files\Anaconda3\Lib_nsis.py" addpath
"C:\Program Files\Anaconda3\pythonw.exe" -E -s "C:\Program Files\Anaconda3\Lib_nsis.py" mkdirs
"C:\Program Files\Anaconda3\pythonw.exe" -E -s "C:\Program Files\Anaconda3\Lib_nsis.py" mkmenus
```
결과 ) 제어판 uninstall이 생긴다.

## 오류해결 2
해당 에러는 환경변수 등록문제와도 관련있다.
- `내 PC`-`고급 시스템 설정`-`고급`-`환경변수` 순으로 들어간다
- 시스템 변수(S)에서 PATH를 찾아 아래와 같이 아나콘다 위치경로를 새로만들기로 추가

![2](/assets/2_r1yjfrd8k.JPG)


- `시스템 변수(S)`- `새로 만들기`에서 다음과 같이 추가한다

![3](/assets/3_vckrgn229.JPG)

결과) cmd에서 python이 실행된다.

하지만 여전히 conda --version이 되지 않고 있다.
**pip install tensorflow 실행도 안된다..**

## 오류해결 3

- 아래 그림의 경로에서 `setuptools-27.2.0-py.3.5.egg`를 찾아 관리자 권한으로 해제한다.

![4](/assets/4_ayugqo21b.JPG)

- 해제한 폴더로 접근한다.

![5](/assets/5_wnqhrhlm8.JPG)

- cmd를 통해 `해당 패스로 이동`,  `python easy_install.py requests` 를 입력한다.
- 이제 기적 같이 cmd에서 `pip install tensorflow`로 패키지를 다운받을 수 있다.

## pycharm에서 설치 확인하기

![6](/assets/6.JPG)


포스트 참고 URL : http://codingdojang.com/scode/370
