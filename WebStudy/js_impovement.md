# JavaScript 심화

 *생활코딩 인프런강좌(JavaScript)를 보고 정리한 글*

탈웹브라우저 추세에 따라 자바스크립트를 웹서버에서도 동작할 수 있도록 Node.js가 등장
즉, 웹브라우저든 웹서버든 Node.js로 모든걸 짜도 된다는 의미

여러 환경(웹브라우저, Node.js, googleSpreadSheet)에서 언어(JavaScript)라는 공통 분모
## 기본 문법 심화
 https://opentutorials.org/course/50 js문법 정리 주소
####  함수를 정의하는 방법
```
방법 1)
numbering = function(){
    i=0;
    while(i<10){
        document.write(i++);
    }
}
numbering();

방법2)
function numberint(){
    i=0;
    while(i<10){
        document.write(i++);
    }
}

방법3) 정의와 함께 호출. 람다식
(function (){
    i=0;
    while(i<10){
        document.write(i++);
    }
})();
```

#### 배열 조작
```
var li=['a','b','c','d','e'];
li.push('f');                   //element 추가
li=li.concat(['f', 'g']);       //array 추가
li.unshift('z');                //z를 첫 원소로 하고 나머지원소의 인덱스가 1씩 증가

li.splice(2, 0, 'B');           //특정구간 추출 or 배열 추가(index, howmany, element1,...)
                                //두번째 index가 0이면 insert, 아니면 append모드                                
```
#### 라이브러리 사용
- 버튼 클릭시 empty가 coding everyday로 바뀌는 예제
- 준비물 jquery 라이브러리
```
<html>
 <head>
     <script type="text/javascript" src="jquery-3.2.0.js"></script>
</head>
<body>
    <ul id="list">
        <li>empty</li>
        <li>empty</li>
        <li>empty</li>
        <li>empty</li>
    </ul>
    <input type="button" value="EX_button" id="exbtn1" />
    <script type="text/javascript">
        $('#exbtn1').click(function(){      #jquery라이브러리가 제공하는 문법 $
            $('#list li').text('coding everyday');
        })
    </script>
</body>
```

#### 콜백
- 리턴값으로의 함수 사용
```
function cal(mode){
    var funcs = {
        'plus' : function(left, right){return left + right},
        'minus' : function(left, right){return left - right}
    }
    return funcs[mode];
}
alert(cal('plus')(2,1));
alert(cal('minus')(2,1));
```
- 배열로서의 함수 사용
```
var process = [
    function(input){ return input + 10;},
    function(input){ return input * input;},
    function(input){ return input / 2;}
];
var input = 1;
for(var i = 0; i < process.length; i++){
    input = process[i](input);
}
alert(input);
```
- 콜백
 함수가 수신하는 인자가 함수인 경우
 ```
 <script type="text/javascript">
     var numbers = [20,10,9,8,7,6,5,4,3,2,1];
     var sortfunc = function(a,b){
         return a-b;                          //양수면 true, 음수면 false
     }
     console.log(numbers.sort(sortfunc));     //sortfunc을 객체로
     //1,2,3,4,5,6,7,8,9,10,20 으로 정렬
 </script>
 ```
#### 비동기와 콜백
동기 : 순차적으로 작업을 수행.
비동기 : 순차적으로 작업을 하지않을 때, 새로 요청이 오면 처리
 시간이 오래 걸리는 작업이 있을 때, 작업이 완료된 후에 처리해야할 일을 콜백으로 지정하면 해당 작업이 끝났을 때 *미리 등록한* 작업을 실행하도록 할 수 있다.
--> 이런 것을 javascript에서는 Ajax(asynchronous javascript and xml)이라고함.
--> 더 이상 웹이 아닌 웹 어플리케이션이 될 수 있던 결정적인 기술

## 클로저
#### 클로저 소개
 `내부함수가 외부함수의 맥락에 접근할수 있는 것.`
- 내부함수
 자바스크립트는 함수 안에서 또 다른 함수를 선언할 수 있다.
 - 외부함수
 내부함수의 맥락에서 내부함수를 갖는 함수
```
function outter(){
    var title = 'coding everyday';
    function inner(){
        alert(title);
    }
    inner();
    //inner에서 알맞은 변수를 못찾으면 밖에서 찾게됨
    //이것이 클로저
}
```
#### 클로저 이해
클로저는 `javascript`에서 private 변수를 갖도록 지원해주는 문법
```
function factory_moive(title){
    return{
        get_title : function (){
            return title;
        },
        set_title : function(_title) {
            if(typeof _title === 'String'){
                title = _title;
            }else{
                alert('제목은 문자열이여야 합니다.');
            }
        }
    }
}

ghost = factory_moive('Ghost in the shell');
matrix = factory_moive('Matrix');

alert(ghost.get_title());
alert(matrix.get_title());

ghost.set_title(1);         //제목은 문자열이여야 합니다
alert(ghost.get_title());
alert(matrix.get_title());
```
#### 클로저 응용
```
var arr = []
for(var i = 0; i<5; i++){
    arr[i]=function(id){
        return function(){
            return id;           
        }
    }(i);       //매개변수 - id에 i를 전달. id를 통해 클로저 구현
}

for(var index in arr){
    console.log(arr[index]());
}
```
