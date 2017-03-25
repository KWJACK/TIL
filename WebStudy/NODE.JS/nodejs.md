# Node.js
예제
```
const http = require('http');
const hostname = '127.0.0.1';
const port = 1337;

const server = http.createServer((req, res) => {    #람다식. => function 축약기호
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/plain');
  res.end('Hello World\n');
});

server.listen(port, hostname, () => {
  console.log(`Server running at http://${hostname}:${port}/`);
});
```
이정도만 해도 쉽지만, 다른 사람들이 만들어 놓은 프레임웍을 사용하면 더 빠르게 웹서버를 만들 수 있다.

## NPM
Node.js 계의 앱스토어
`npm install` 으로 설치 가능.  global 옵션과 로컬이 있다.

#### uglify-js로 실습
`uglify pretty.js` : 코드의 공백, 띄어쓰기 제거
`uglify pretty.js -m` : 변수 이름 변경(name -> o).
`uglify pretty.js -m -o unglified.js` : 변경 사항이 적용된 상태로 저장

#### 설치
`npm init` : npm 디렉토리 설정. package.json파일 자동생성
json이 있는 폴더에서 npm 패키지를 다운 받을수 있다
(- -save 옵션으로 dependencies에 등록할 수 있다)

## Express Framework
`npm install --save express`를 통해 express를 json파일안의 dependencies 추가

app.js <-관습적인 main.c역할
```
const express = require('express');
var app = express();//express를 쓰려면 이렇게
app.use(express.static('public'));//정적인 파일이 있는 경로 작성
                                  //이를 통해서 정적일 파일을 가져올 수 있다.
                                  //서버를 종료치 않고도 업데이트 가능

app.get('/',(req, res)=>{   //'/' : home. 홈으로 접속하면 함수 실행
                            //(request와 response를 입력하도록 되어있음)
    res.send('Hello home page');
});
app.get('/dynamic', (req, res)=>{
    var output = ``
    res.send()
})
app.get('/router', (req, res)=>{
    res.send('Hello router, <img src="/1.jpg">')
});
app.get('/login', (req, res)=>{ //get: router역할(길을 찾아주는 것)
    res.send('<h1>login please</h1>');
});

app.listen(3000, ()=>{
    console.log('Conneted 3000 port');
});   //포트 지정
```
정적인 파일을 이용하면(app.use(express)를 사용하면) nodejs 실행을 종료하지 않아도 업데이트 가능

## 템플릿 엔진 pug(jade)
express에서 코드를 쉽게 작성하도록 돕는 템플릿 엔진의 사용법을 살펴봅니다
```
app.locals.pretty = true;           //pug로 만든 소스를 보기 좋게
app.set('view engine', 'pug');      //pug 엔진 셋(npm install pug를 한 상태)
app.set('views', './views');        //pug파일은 views 디렉터리에서 사용
app.get('/template', (req, res)=>{    
    res.render('temp', {time=Date()});
});
```
temp.pug
```
html
  head
    title= title
  body
    h1 Hello Jade
    ul
      -for(var i=0; i<5; i++)
        li coding
    div= time

```
## Query string
`http://a.com/topic?id=1` : topic이라는 라우트에 전달되는 값에 따라 보여지는 페이지가 달라지게 할 수 있다
이 때 `?id=1`을 query string이라고 한다

## OrientDB
`Table`이라는 용어 대신 `Class`라는 용어로 대체

(*java jdk가 설치되어 있어야함*)

설치 위치: `C:\Users\Coms7\Documents\orientdb-community-2.2.17`
`bin`으로 이동
`server.bat` 입력

http://localhost:2480 에서 orientDB를 컨트롤할 수 있다.
`new database` 버튼으로 DB 생성

 class의 구조 생성
`Schema(컬럼)` ->`Generic Classes`->`click`->`New Property`

madantory 옵션 : 내용 입력되지 않으면 db에 추가하지 않음

`CRUD` : 데이터를 다루는 기초 작업
`CEATE` :
`READ` :
`UPDATE` :
`DELETE` :
