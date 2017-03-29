# Node.js
//모던 웹을 위한 Node.js프로그래밍 대출필요
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

server.listen(port, hostname, () => {   //node.js는 각 입력에 대해 라우트로 처리
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
-필수 선언 요소
`const express = require('express');`
`var app = express();` : express를 app으로 사용가능
```
app.use(express.static('public'));//정적인 파일이 있는 경로 작성
                                  //이를 통해서 정적일 파일을 가져올 수 있다.
                                  //서버를 종료치 않고도 업데이트 가능

app.get('/',(req, res)=>{   //'/' : home. 홈으로 접속하면 함수 실행
                            //(request와 response를 입력하도록 되어있음)
    res.send('Hello home page');
});
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
### Express 미들웨어
 Express 프레임워크에서 여러 동작을 지원하는 모듈을 미들웨어라고 함
 ##### 대표적인 미들웨어

 `body-parser` - post방식의 전송정보를 파싱하도록 지원하는 패키지
 - 필수 선언 요소
 `var bodyParser = require('body-parser');`
 `app.use(bodyParser.urlencoded({extended: false }));`
 ```
 app.post('/topic', (req, res)=>{
     var title = req.body.title; //body-parser 미들웨어를 통한 구현
     var description = req.body.description;
     fs.writeFile('data/'+title, description, (err)=>{        
        res.redirect('/topic/'+title);//리다이렉션: 생성한 해당 페이지로 사용자를 보냄
     });
 })
 ```
 `multer` - 파일전송을 위한 패키지

- 필수 선언 요소
`var multer = require('multer');`
`var upload = multer({storage: _storage});`
 ```
 var _storage = multer.diskStorage({
   destination: (req,file, cb)=>{
     cb(null, '/uploads');//디렉터리 지정
   },
   filename: (req,file,cb)=>{
     cb(null, file.originalname);//파일이름지정
   }
 })
 ```

## 템플릿 엔진 pug(jade)
express에서 html코드를 쉽게 작성하도록 돕는 템플릿 엔진
```
app.locals.pretty = true;           //pug로 만든 소스를 보기 좋게
app.set('view engine', 'pug');      //pug 엔진 셋(npm install pug를 한 상태)
app.set('views', './views');        //pug파일은 views 디렉터리에서 사용
app.get('/template', (req, res)=>{    
    res.render('temp', {time=Date()});  //render는 엔진파일 실행을 의미. 변수를 넘겨주려면 {}기호
});

```
`temp.pug`
```
html
  head
    title= title
  body
    h1 Hello Jade
    ul
      -for(var i=0; i<5; i++)
        li coding
    div= time //주입받은 변수 사용시 = 기호를 붙여 받음
```
#### 문법(기호) 정리
|기호|설명|예제|
|:---:|:------------:|------|
| `-`| 이하 자바 문법 적용|  - rid = encodeURIComponent(topic['@rid']) <br> a(href='/topic/'+rid)= topic['title']|
|`=`|nodejs에서 받은 변수 사용|h2= selected.title (selected는 query)|
|`\`+<kbd>shift</kbd>| 태그 없이 내용 작성 가능(text)|This is server side JavaScript tutorial |

 -----------------

## Query string
`http://a.com/topic?id=1` : topic이라는 라우트에 전달되는 값에 따라 보여지는 페이지가 달라지게 할 수 있다
이 때 `?id=1`을 query string이라고 한다

## OrientDB
`Table`이라는 용어 대신 `Class`라는 용어로 대체

(*java jdk가 설치되어 있어야함*)
##### 설치 위치: `C:\Users\Coms7\Documents\orientdb-community-2.2.17\bin`

##### 실행 : `server.bat` 입력

http://localhost:2480 에서 orientDB를 컨트롤할 수 있다.
`new database` 버튼으로 DB 생성

 class의 구조 생성
`Schema(컬럼)` ->`Generic Classes`->`click`->`New Property`

madantory 옵션 : 내용 입력되지 않으면 db에 추가하지 않음

`CRUD` : 데이터를 다루는 기초 작업(`C`reate, `R`ead, `U`pdate, `D`elete). sql과 동일 명령어
|작업|sql 문법|
|:--:|:--|
|`CEATE` | `INSERT INTO topic (title, description, author) VALUES(:t, :d, :a)`|
|`READ` | `SElECT FROM topic WHERE @rid=:rid`|
|`UPDATE` | `UPDATE topic SET title=:t, description=:d, author=:a WHERE @rid=:rid`|
|`DELETE` | `DELETE FROM topic WHERE @rid=:rid`|

**`DELETE`와 `UPDATE`를 사용할 때 WHERE을 똑바로 사용하지 않으면 대참사 발생**
