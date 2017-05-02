# VS Tip 모음

## 단축키
단축키|설명
:---:|---
<kbd>Ctrl</kbd> + <kbd>Tab</kbd> | 탭 문서 이동
<kbd>Ctrl</kbd> + <kbd>o</kbd> | 클래스 간 이동
<kbd>Ctrl</kbd> + <kbd>Space</kbd> | 자동완성
<kbd>Ctrl</kbd> + <kbd>k</kbd> + <kbd>c</kbd> | 블럭 친 부분 주석 처리
<kbd>Ctrl</kbd> + <kbd>k</kbd> +<kbd>u</kbd> | 블럭 친 부분 주석 해제
<kbd>Ctrl</kbd> + <kbd>l</kbd>| 한 줄 잘라 내기
<kbd>Alt</kbd> + <kbd>Enter</kbd>| 속성창 열기

자매품 windows 유용키 모음 https://support.microsoft.com/ko-kr/help/12445/windows-keyboard-shortcuts

## 컴파일러 옵션
- /Gz
 함수에 명시적으로 호출 규정을 선언하지 않으면 기본으로 `__stdcall` 적용
- /Gr
함수에 명시적으로 호출 규정을 선언하지 않으면 기본으로 `__fastcall` 적용
- /Gd
함수에 명시적으로 호출 규정을 선언하지 않으면 강제적으로 `__cdecl` 적용

#### stdcall cdecl
||__stdcall|__cdecl|
|---:|:---:|:---:|
|인자전달 순서|오른쪽-> 왼쪽|오른쪽-> 왼쪽|
|스택정리 책임|피호출자|호출자|
|호출 규정이<br>적용되는 함수|매개인자 개수가 고정된 함수|매개인자 개수가 가변적인 함수|

- `fastcall` : 함수 호출시 두 개의 인자를 레지스터에 나머지는 스택에 저장
두개 인자 이하의 경우 스택에 인자를 저장하지 않아도 되므로 수행속도 향상

참고 : http://www.tipssoft.com/bulletin/board.php?bo_table=FAQ&wr_id=625

## 에러 리포팅
### fetal error C1083
- winsock2.h 파일이 없다고 컴파일 되지않는 오류
- 해결로 progma를 쓰니 뭐니 하기 전에 다음 창에서 Windows SDK 버전이 8.1로 되있는 건 아닌지 확인
- 아래 처럼 최신으로 바꾸면 수정 완료
![12](http://i.imgur.com/048kvG6.png)
