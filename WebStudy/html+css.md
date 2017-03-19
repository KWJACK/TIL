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

\<input\> : 인풋 상자 타입으로 텍스트나 버튼 가능 ex) type="text"

\<textarea\> : 줄바꿈이 가능한 textArea

\<form\> action="주소"</form\>  form 태그 안의 정보를 action이 가리키는 주소로 보냄

> ex) \<form action="http://localhost:81/php/3.php" method="GET"\> 보내는 정보 </form\>
> POST 방식(php서버에서 받아냄), GET 방식(웹url에 담아서 보냄)

```
<stlye>
# selected{                         //#뒤에는 id값. 해당 id content를 다룸
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

      emmet 활용예 li_20 Tab --> 20개의 li생성

      li>a_20 --> li에 a href 가 20개 생성

      div>ul>li --> sub태그들이 생성

  emmet을 설치하면 코드 생산성이 매우 좋아짐.   (ex)<kbd>!</kbd>+ <kbd>Tab</kbd> : !DOCTPYE 이후 자동 세팅


# CSS

html의 정보를 스타일이 좋게 표현하도록, **디자인**을 지원하는 언어

html에서 stlye을 각 html파일에 만들면 유지보수하기 어렵다.

- style을 분리하여 css파일에 stle 태그의 본문을 css파일에 작성
- css파일의 경로를 html에서 head아래에 다음과 같이 적으면 css style이 적용

```
<link rel="stylesheet" type="text/css" href="<http://localhost:81/style.css">
//link하고 tab하여 자동완성
```
- cf. 크롬 플러그인 chrome extension stylebot을 이용하면 스타일을 실험적으로 디자인 가능.
    - 실험적이지만 stylebot을 저장하면 실제 웹페이지도 바뀜(자신의 로컬에서)
