# jQuery :http://api.jquery.com/
- jQuery는 자바스크립트 DOM 작업을 쉽게 도와주는 third party 라이브러리
   - `DOM(Document Object Model)`이란?
    - 브라우저가 HTML 파일을 읽어서 마크업 태그와 1:1 매칭으로 DOM 객체를 생성
    - 웹 출력시 DOM 객체 사용
    - DOM 문서는 인터페이스 정의 문서(IDL)언어로 작성되어 있음

- jQuery의 기능 4가지
  - DOM객체를 다루는 property 와 method 제공
  - 서버와 데이터를 주고받는 ajax기능
  - 여러 가지 기능의 집합, 플러그인 제공
  - 애니메이션 효과
- http://jqueryui.com/themeroller/  에서 jquery가 제공하는 테마속성 다운 가능
  - gallery에서 선택하거나 커스텀하게 이용 가능
  - 다운 받은 폴더를 해당 프로젝트에 위치시키고 import
  - `<link rel="stylesheet" href="/jqueryui/jquery-ui.css"/>`
  - `<script type="text/javascript" src="/jqueryui/jquery-ui.js"></script>`



- $() 축약기호는 jQuery 를 뜻함. jQuery객체를 리턴
- `var $header = $("#header");` 처럼 jQuery 객체를 받는 변수는 `앞에 $기호 해주는게 일반적`


- jQuery의 메인은 ready()
ready()는 DOMContentLoaded 이벤트를 포장한 메서드임
```
방법1)
$(documnet).ready(function(){

  });

방법2)
$(function(){

  });
```
`(주의사항)` ready() 메서드는 이미지 같은 무거운 콘텐츠 로드 전에 동작하므로,
 경우에 따라 window.onload()로 대체해서 사용한다.
  DOMContentLoaded 이벤트 발생 후 모든 콘텐츠가 로드된 후에 load이벤트가 발생하는 구조기 때문

## 여러가지 메소드
- length() : 길이 반환(노드 갯수)
- eq(index) : 노드에 접근
- get(index) : DOM 객체에 접근
```
var $liList = $("ul.menu li");
var $li_eq = $liList.eq(1);  //eq는 node에 접근함.
var li_get = $(liList).get(1); //DOM 객체로 변수명에 $를 제외함

$li_eq.css("border", "4px solid #e00"); //노드라면 jQuery객체 메소드 사용
li_get.style.border="4px solid #e00";   //DOM이라면 DOM의 메서드로 접근
```
DOM의 경우 더 low한 레벨이기 때문에 jQuery가 포함치않는 많은 속성을 다룰 수 있음.

- each(function(param){ }) + $(this)
```
var $liList = $("ul.menu li");
$liList.each( function(index){  
  var indexpx = (index+1)*2;
  $(this).css("border",indexpx+"px solid #f00"); //$(this)는 대상 스크립트 DOM
})
```
- filter("선택자") : 현재 노드 중에서 특정 노드만 걸러 내고 싶을 때 사용(자식 탐색 X)
```
$liList.filter(".select").css("border", "4px solid #f00"); //.select 클래스에만 접근
```
- find("선택자") : 현재 노드의 자식 노드에서 탐색. 검색 대상에서 현재 노드 제외
- \$대상.index() or \$목록.index(\$대상) or \$목록.index(대상 DOM)

- $("#username").val() 해당 id태그의 value 출력
- $("#login").html("로그아웃") #login이 버튼일 때 버튼 이름 출력
- $("#login").show() hide된 태그를 보여줌. 반대는 `hide()`
- $("#address").focus() input 태그의 focus를 줌

## ajax
```
var userinfo = { //ajax로 넘길때는 튜플로
  username: $("#username").val(),
  password: $("#password").val()
};

$.ajax({
      type: 'POST',
      data: JSON.stringify(userinfo),
      contentType: 'application/json',
      url: 'http://funfunbox.azurewebsites.net/join/login',
      success: function(data) {
          alert("로그인 완료");
          location.href ="http://funfunbox.azurewebsites.net/board"; //redirect 기능
      }
  });
```
