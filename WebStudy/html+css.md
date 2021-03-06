# HTML

### index.html

index.html : (보통) 사이트의 대문

index.html은 웹사이트에서 홈페이지의 정보를 담고 있는 파일

주소입력시 index.html을 우선적으로 찾는다

### 태그

\<ol\> : ordered list 숫자나 알파벳 등 순서가 있는 목록

\<ul\> : unordered list 순서가 없는 목록

\<p\> : paragraph. 단락 구분 태그

\<a href= "http주소"\> : 하이퍼링크 \</a\>

\<link\> : 링크 태그에 적힌 속성을 보고 외부 파일을 읽어올 수 있다.

\<style\> : css 파일태그

\<script\> : js 태그

\<input\> : 인풋 상자 타입으로 텍스트나 버튼 가능
- type="button" or "submit" or "password" or "text"

\<textarea\> : 줄바꿈이 가능한 textArea.
-  readonly, disabled 속성
 글 수정 방지 가능. disabled는 마우스 커서도 안잡히고 form으로 전송이 안됨

\<form\> action="주소"</form\>  form 태그 안의 정보를 action이 가리키는 주소로 보냄

> ex) \<form action="http://localhost:81/php/3.php" method="GET"\> 보내는 정보 </form\>
> POST 방식(php서버에서 받아냄), GET 방식(웹url에 담아서 보냄)

```
<stlye>
#selected{                         //#뒤에는 id값. 해당 id content를 다룸
    //style에서 속성값을 정의하는 예
    width:200px;                    //크기
    height: 600px;
    border: 1px solid gray;         //경계선(border-right 등..)
    float: left;                    //이미지와 글자를 나란히
    padding: 30px;                  //content사이의 간격
}

nav ol{//id값 말고도 태그로도 접근 가능. 태그의 태그도 가능

}
</stlye>

 ...
<li\> id="selected"</li\>           //html내에서 id를 가리킬 때는 #을 사용
```

## 의미론적 웹 태그

<nav\> : navigator를 위한 컨텐츠임을 밝힌다. 이 태그로 웹사이트 탐색에 유리하게 적용</nav\>

<article\> : 페이지의 본문</article\>

Client Side Tech : HTML, CSS, JavaScript <<웹브라우저>>

Server Side Tech : PHP, MySQL <<웹서버>>

## 사이트 만들기

### Bitnamit를 통해 보는 방법

_localhost연결문제 해결 :_

1. C:\Bitnami\wampstack-5.6.30-1\php로 이동
2. 해당 디렉터리의 php.ini 파일을 다른 장소에 백업한 뒤 아래와 같이 수정
3. On windows: 밑에 주석을 풀고 아래처럼 수정 후 비트나미 재실행

  ```
  > extension_dir = "C:/Bitnami/wampstack-5.6.30-1/php/ext"
  ```

4. bitnami>버전>apache2>htdocs에 있는 파일오픈(run localhost)은 다음과 같은 형식으로 적용 "<http://localhost:81/index.html>"

--------------------------------------------------------------------------------

#### (번외) 아톰에디터를 이용하는 방법

준비 패키지 : **atom-html-preview**

 <kbd>ctrl</kbd>+<kbd>shift</kbd>+<kbd>h</kbd> : atom-html-preview에서 html뷰 생성

  ##### 기타 아톰 추천 패키지

  - emmet, (minimap), script

      emmet 활용예 li\*20 + <kbd>Tab</kbd> --> 20개의 li생성

      \! + <kbd>Tab</kbd> --> html default setting

      li>a\*20 --> li에 a href 가 20개 생성

      div>ul>li --> sub태그들이 생성

  emmet을 설치하면 코드 생산성이 매우 좋아짐.   (ex)<kbd>!</kbd>+ <kbd>Tab</kbd> : !DOCTPYE 이후 자동 세팅


------

# CSS
## 개념
html의 정보를 스타일이 좋게 표현하도록, **디자인** 을 지원하는 언어

html에서 stlye을 각 html파일에 만들면 유지보수하기 어렵다.

- style을 분리하여 css파일에 stle 태그의 본문을 css파일에 작성
- css파일의 경로를 html에서 head아래에 다음과 같이 적으면 css style이 적용

```
<link rel="stylesheet" type="text/css" href="<http://localhost:81/style.css">
//link하고 tab하여 자동완성
```
- cf. 크롬 플러그인 chrome extension stylebot을 이용하면 스타일을 실험적으로 디자인 가능.
    - 실험적이지만 stylebot을 저장하면 실제 웹페이지도 바뀜(자신의 로컬에서)
----------
#### html에서 스타일링을 통하는 세가지 방법
1. internal style 방식 \<head\> 태그 사이에 `<style>`태그로 주는 방법

2. external css 방식 : \<head\>태그 사이에 외부 경로 삽입

    `<link rel="stylesheet" type="text/css" url="외부css파일경로"\>`

3. inline style 방식 : html 마크업 자체에서 속성값 지정
    `<div style="background:#000; color:#fff;"></div>`
-------
## 문법
클래스 :  `.NAME {속성들}` : 앞에 쩜을 찍고 접근
아이디 : `#NAME {속성들}` :  앞에 #을 찍음
(아이디를 남발하기 보다는 클래스를 통하는 것이 좋음)
(아이디는 유일하기 때문에 접근이 개별적이지만, 클래스는 모든 엘리먼트에 대해 접근하기 때문)

jQeury에서 css를 사용할 때 문법을 비슷하게 적용 가능
`css`---`#header{ border : 4px solid #ff0000; }`
`jQuery`---`$("#header").css("border", "4px solid #ff0000")`

#### 선택자
 엘리먼트를 선택하는 기능.

|CSS|jQeury|설명|
|---|---|:---|
|*|$("*")|모든 엘리먼트 선택|
|#I|$("#I")|아이디가 I인 엘리먼트 선택|
|E|$("E")|태그 이름이 E인 모든 엘리먼트 선택|
|.C|$(".C")|C라는 클래스 선택자를 가진 모든 엘리먼트|
|E F|$("E F")|E의 자식 노드 중 태그 이름이 F인 모든 엘리먼트 선택|
|E.C|$("E.C")|태그 이름이 E인 엘리먼트중 C라는 클래스 선택자를 가진 모든 엘리먼트 선택|
|E .C|$("E .C")|E의 자식노드 중 C라는 클래스 선택자를 가진 모든 엘리먼트 선택|
|E>F|$("E>F")|E의 바로 아래 자식 태그 이름이 F인 모든 엘리먼트 선택|

## 속성 정리

- margin : 5px  태그 외부 간격(크면 태그와 태그 사이 거리 멀어짐 left,bottom, top, right으로 세분화 가능)
- padding : 5px 태그 내부 간격(작으면 태그 영역 좁아짐 left,bottom, top, right로 세분화 가능)
- float: left   부모 태그에서 선언하면 자식 태그들이 아래로 내려가지 않고 가로로 정렬됨
