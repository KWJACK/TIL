시작하기 앞서..
-----
- JavaScript와 PHP항목의 순서대로 서로 비교하며 진행
- php를 위해 bitnami의 설정을 다음과 같이 변경
> ### bitnami 설정 변경
> 개발에서는 error를 고쳐야하므로. 실제 배포시에는 Off로 함
>
> - php.ini 파일 오픈 -> display_errors 찾기 -> Off를 On으로 변경
>- opcache.enable=0 수정사항을 바로바로 업데이트하도록 변경
> - /wampstack/manager-windows.exe실행 -> apache web server restart하여 수정사항 적용


# PHP
CSS가 HTML의 스타일을 한 번에 정의하듯,
HTML에 있는 태그, 정보들을 *분리*시켜 다룰 수 있는 지원하는 언어
즉, 하나의 php파일로 여러개의 html파일을 다룰 수 있다.

기본적으로 php파일은 html과 똑같이 반응(html파일을 그대로 넣어도 적용된다는 소리)

### 1. 선언\<?php  ?\>

php 엔진을 통해 만든 소스는 html로 변환되어 삽입.(php소스가 보이지않음)
- 서버단에서 php 인터프리터에게 요청하여 처리해주기 때문
```
<body>
    <?php
                                            #변수
        echo "Hello world";        # Hello world. 페이지소스에서 <?php가 보이지않음
        echo 10+10;                # 20 
        $name = "egoing";          # 변수선언시 $ 표시 
        echo "Hello world ".$name; # 문자열 합침은 '.'기호
        var_dump(1==2);            #false출력

        $result = (2==2);                   # 조건문
        if($result){
            echo "참";
        }else{
            echo "거짓";
        }

        $i = 0;                             # 반복문
        while($i < 10){
          echo "<li>hello world</li>";
          $i = $i + 1;
        }
                                            # 배열
        $list = array("one", "two", "three");
        $list[0];                           # echo count($list); length 출력

                                            # 함수문법 JavaScript도 동일
        function function_name(input){
            return input+1;
        }
        function();         
    ?>
</body>
```
### 2. 디버깅
 디버깅은 apache2/logs/error.log 파일에서 확인 가능.(웹서버)
 가장 최근 메시지를 확인(맨 아래)

### 3. 로그인 기능 구현
```
<body>
    <?php
        $password = $_GET["password"];      # _GET : 값을 받아오는 예약어
        if($password =="1111"){
            echo "환영합니다.";
        }else{
            echo "뉘신지?";
        }
    ?>
</body>
```
### 4. 실습
 php목적 : 여러 html파일을 **index.php**로 합치는 과정. 정보는 여러 파일로 분할
 -> 최종적으로는 여러 파일은 데이터베이스 형태로 존재
#### 1번
```
<?php
    echo $_GET['name'].",".$_GET['id'];        # name & id를  받음 '& == ,'
    file_get_contents("1.txt");                # 파일을 읽어 contents 내용을 return하는 예약어
    file_get_contents($_GET[id].".txt");       # id 값에 따라 읽어오는 txt파일이 다름
?>
```

#### 2번
```
<?php
    if(!empty($_GET['id'])){                   # empty이면 참. !은 부정
        echo file_get_contents($_GET['id'].".txt");
    }
?>
 ```
 #### 최종결과
 ![1](https://cloud.githubusercontent.com/assets/20148930/24066685/0a57af2e-0bb8-11e7-9670-804cc968f11f.JPG)

 --------------
# JavaScript
 html과 css가 정적인 정보만을 기입할 수 있었다면,
 JavaScript는 웹페이지에 명령하여 *동적*으로 웹페이지를 구성할 수 있도록 지원하는 언어
 즉, HTML에 소스를 삽입하거나 조건을 통해 제어할 수 있는 언어.

### 1. 선언 \<script\>  \</script\>
웹에 자바스크립트를 삽입 :  
소스보기 수행시 php와 달리 **script태그의 소스들이 출력.**
- 웹브라우저에서 실행되는 언어이기 때문
```
<script>
    document.write("Hello world");   <!-- Hello world -->
    document.write(10+10);           <!-- 20-->
    name = "이고잉";
    document.write("Hello world"+name);
    document.write(1==2);           <!-- false-->

    result =(1==2);                 <!-- 조건문-->
    if(result){
        document.write("참");
    }else{
        document.write("거짓");
    }

    i = 0;                          <!--반복문-->
    while(i < 10){
     document.write("<li>hello world</li>");
     i = i + 1;
    }
    password = prompt("비밀번호");   <!--웹브라우저 built-in func(프롬프트창 출력)-->
                                    <!--자매품 alert("hello world")도 있음(경고창)-->

    list = new Array("one", "two", "three");<!--배열-->
    list[0];                        <!--list.length 길이-->

</script>
```
### 2. 디버깅
 웹페이지 개발자도구에서 확인 가능

### 3. 로그인 기능 구현
```
<body>
    <form action="8-2.php">
        <p>비밀번호를 입력해주세요</p>
        <input type="text" name="password">
        <input type="submit" />
        <!--submit이 위치한 form의 action속성이 가리키는 웹에 정보들을 전송하도록 되어있음-->
    </form>
</body>
```

### 4. 실습

#### 1번 버튼만들기. alert 함수
```
    <input type="button" value="white" onclick="alert('Hello world')"/>    
    <!--클릭했을 때 js코드 실행. script밖에서 js코드가 실행된다는 것에 주목 -->
    
    <input type="text" onfocus="alert('focus')" onblur="alert('blur')"/>
    <!-- focus발생시 focus출력, focus해제시 blur 출력-->
```

#### 2번 text에 입력후 버튼 클릭시 내용을 출력하는 예제
```
    <input type="text" id="user_input"/>        
    <input type="button" value="white" onclick="alert(document.getElementById('user_input').value)"/>
```

#### 3번 버튼 클릭시 id target에 있는 모든 내용에 밑줄 긋는 예제
```
 <head>
	<meta charset="utf-8"/>
    <style media="screen">
        .em{                            <!-- class 접근자는  '.'를 적용 -->
            text-decoration: underline;
        }
    </style>
</head>
<body>
    <ol id="target">
        <li>html</li>
        <li>css</li>
        <li>JavaScript</li>
    </ol>
    <ul>
        <li class ="em">최진혁</li>    <!-- class를 통해 컴포넌트 각각에 접근 가능 -->
        <li>최유빈</li>
        <li>한이름</li>
        <li>한이은</li>
    </ul>
    <input type="button" value="강조" onclick="document.getElementById('target').className='em'" />
    <!-- 'ol id = target'에 있는 컴포넌트에 class em html을 추가 -->
<body>
```
#### 4번. 버튼 클릭시 웹페이지 바탕색, 글자색 바꾸기
\<div id="control"\>    //아무런 특징이 없는 태그. 내부적으로 묶으려고 사용
- css 파일에서 편집
```
#control{
    float: right;
    padding: 30px;
}
body.white{
    background-color: white;
    color:black;
}
body.black{
    background-color: black;
    color: white;
}
```
- js 파일 편집
```
<body id="targetBody">
...생략...
<div id="control">
    <input type="button" value="white" onclick="document.getElementById('targetBody').className='white'"/>
    <input type="button" value="black" onclick="document.getElementById('targetBody').className='black'"/>
</div>
```

#### 5번. 4번에서 html상에 있는 js코드 분리
- html 소스의 js 코드를 id로 대체
```
<div id="control">
    <input type="button" value="white" id="white_btn"/>
    <input type="button" value="black" id=black_btn"/>
</div>
```

- 별도의 js 파일을 새로 생성하여 html에서 js파일을 읽어오게 구성

> \<script = "http://localhost/script.js\>\</script\>
- js 파일에서 js 코드를 구현
    addEventListener()함수 이용
```
    wbtn = document.getElementById('white_btn');
    wbtn.addEventListener('click', function(){
        document.getElementById('targetBody').className='white';
    })

    bbtn = document.getElementById('black_btn');
    bbtn.addEventListener('click', function(){
        document.getElementById('targetBody').className='black';
    })
```

#### 마지막. 댓글, 채팅 기능 추가
> 손쉽게 모듈을 웹에 부착할 수 있다.
- 댓글기능 : disqus { disqus.com, livere.com(국내서비스) }
disqus.com 사이트에 접속. universal code install에 내용 copy&paste하여 적용
```
<div id="disqus_thread"></div>
<script>
/**
*  RECOMMENDED CONFIGURATION VARIABLES: EDIT AND UNCOMMENT THE SECTION BELOW TO INSERT DYNAMIC VALUES FROM YOUR PLATFORM OR CMS.
*  LEARN WHY DEFINING THESE VARIABLES IS IMPORTANT: https://disqus.com/admin/universalcode/#configuration-variables*/
/*
var disqus_config = function () {
this.page.url = PAGE_URL;  // Replace PAGE_URL with your page's canonical URL variable
this.page.identifier = PAGE_IDENTIFIER; // Replace PAGE_IDENTIFIER with your page's unique identifier variable
};
*/
(function() { // DON'T EDIT BELOW THIS LINE
var d = document, s = d.createElement('script');
s.src = 'https://saengkowebaepeulrikeisyeonmandeulgi-kwjack.disqus.com/embed.js';
s.setAttribute('data-timestamp', +new Date());
(d.head || d.body).appendChild(s);
})();
</script>
<noscript>Please enable JavaScript to view the <a href="https://disqus.com/?ref_noscript">comments powered by Disqus.</a></noscript>
```

- 채팅기능 : tawk.to 사이트 접속. admin에서 사이트 생성하여 widget code 복사
```
<!--Start of Tawk.to Script-->
<script type="text/javascript">
var Tawk_API=Tawk_API||{}, Tawk_LoadStart=new Date();
(function(){
var s1=document.createElement("script"),s0=document.getElementsByTagName("script")[0];
s1.async=true;
s1.src='https://embed.tawk.to/58cb75df2dfdd91cf6f4c34f/default';
s1.charset='UTF-8';
s1.setAttribute('crossorigin','*');
s0.parentNode.insertBefore(s1,s0);
})();
</script>
<!--End of Tawk.to Script-->
```
#### 최종결과
![2](https://cloud.githubusercontent.com/assets/20148930/24066686/0b12d75e-0bb8-11e7-9f77-65f0b2e760cf.JPG)
