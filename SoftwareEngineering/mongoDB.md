
## mongo DB 설치
https://velopert.com/457 에 자세히 나와있음. 생략
http://www.w3ii.com/ko/mongodb/mongodb_data_modeling.html 한글 메뉴얼 페이지

## mongoDB 사용
- db목록 확인
`show dbs`

### Database
- db 선택
`use mongodb_tutorial` //해당 이름의 db사용. 없어도 선택


- db에 데이터 넣기
`db.sample.insert({"name": "sample"});` // db가 없어도 새로 데이터 추가시 db가 생성됨.


 - db 제거
  `db.dropDatabase()`  // 데이터 베이스가 선택되어 있어야함

### Collection
  - 컬렉션 생성.
  `db.createCollection(name, [option])` //컬렉션을 정의해서 만드는 방법. option은 선택
  `db.people.insert({"name": "jack"})`  //컬렉션이 없어도 'people' 컬렉션을 자동으로 생성. 데이터 삽입


  - 컬렉션 조회
  `show collections` // collection에 s가 붙는거에 유의


  - 컬렉션 제거
  `db.people.drop()`

### Document
  - document 삽입
`db.books.insert({"name": "NodeJS", "author":"jack"})`
`db.books.insert([
  {"name" : "Book1", "author": "jack"},
  {"name" : "Book2", "author": "jack"}
  ])`
  //배열 형태로 넣으면 여러개 삽입 가능


  - document 제거
  `db.collection_name.remove(criteria, [justOne])`

  justone을 true로 두면 criteria와 일치하는 데이터중 한 개만 삭제
  false가 기본값. 일치하는 데이터 모두를 지움

  `db.books.remove({"name": "NodeJS"})`

  `db.books.remove({"name": "NodeJS"}, true)`


- document 조회
  `db.books.find()`

  `db.books.find().pretty()` //멀티라인으로 출력

  `db.books.find({"value": 56})`  //56인 document를 찾아서 조회

  `db.books.find({"value": { $gt: 100} })`  //100보다 큰 document를 연산자 gt를 이용해 출력

  `db.books.find({"value": {$gt:0, $lt:100}})` //0~100사이의 document조회

  `db.books.find({"value": {$gt:0, $lt:100, $nin: [12,33]}})` //0~100사이, 12,33제외

- document 업데이트
`db.books.update({"post": post_id}, {"$inc" : {"comments.0.votes": 1}})` // comment가 배열일 때 첫 번째 배열 doc에 접근해 votes를 1 올림
`db.books.update({"coments.author": "John"}, {"$set" : {"comments.$.author": "Jim"}})`
// `$`연산자를 통해 쿼리 문서와 일치하는 배열의 요소와 해당 요소의 위치를 알아내 갱신할 수 있음.
// 단 첫 번째로 일치하는 것만 갱신


-  쿼리연산자

|Operator | Description |
|:----------|:-------|
|$eq|eqaul 주어진 값과 일치하는 값|
|$gt|geater than 주어진 값보다 큰 값|
|$gte|gt에 eq 크거나 같은 값|
|$lt|less than 주어진 값보다 작은 값|
|$lte| 작거나 같은값|
|$ne|not equal 주어진 값과 일치하지 않는 값|
|$in|주어진 배열 안에 속하는 값|
|$nin|주어진 배열 안에 속하지 않는 값|

- 논리연산자

|Operator | Description |
|:----------|:-------|
|$or|하나라도 true일 때 true|
|$and|모든 조건이 true일 때 true |
|$not|주어진 조건이 false일 때 true|
|$nor|주어진 모든 조건이 false일 때 true|

`db.books.find( { $and: [ { “writer”: “Velopert” }, { “likes”: { $lt: 10 } } ] } )`
and의 또 다른 방법: 찍기
` db.books.find( { “writer”: “Velopert”, “likes”: { $lt: 10 } } )`


- regex 연산자(정규식)

|Option | Description |
|:----------|:-------|
|i |	대소문자 무시|
|m| 	정규식에서 anchor(^) 를 사용 할 때 값에 \n 이 있다면 무력화|
|x| 	정규식 안에있는 whitespace를 모두 무시|
|s| 	dot (.) 사용 할 떄 \n 을 포함해서 매치|

`db.articles.find( { “title” : /article0[1-2]/ } )`

- where 연산자
`$where` 연산자를 통하여 javascript expression를 사용
comments field 가 비어있는 Document 조회
`db.articles.find( { $where: "this.comments.length == 0" } )`


## mongoose
- nodejs에서 mongodb를 지원하는 모듈
--------------
### ORM(Object-relational mapping)
 - 데이터베이스를 프로그램의 object로 생성,  함수명령어를 만들어 데이터베이스를 조작하는 개념
 - `모델` : 데이터베이스의 데이터와 직접 연결되는 object
 - `스키마` : 이 데이터의 구조
 - `collection` 이름은 항상 복수, `model` 이름은 단수로 쓰는게 원칙

ex) 로그인 기능이 있는 게시판
- 유저(user)모델과 게시글(post)모델로 구성
-  유저스키마는 아이디, 비밀번호가 필요
- 게시글스키마는 글제목, 글내용, 작성자, 작성시간이 필요

------------------------
### 사용 A to Z
- #### 설명에 필요한 npm
`var mongoose = require('mongoose');`
`var autoIncrement = require('mongodb-autoincrement')`
`var MongoStore = require('connect-mongo')(session);` // express-session npm 필요


- #### mongoose 사용
  - 콜렉션에 접근할 객체를 선언하고 객체의 메서드를 통해 작업하는 구조.
  - Built-in된 메서드를 사용하거나 사용자 정의 메서드를 만들어 사용할 수 있다.
  - 스키마 선언시 지원하는 데이터형
      `String, Number, Date, Buffer, Boolean, Mixed, ObjectId, Array`
```
mongoose.Promise = global.Promise; //몽구스 사용시 promise 선언필수
mongoose.connect('mongodb://localhost/mongodb_tutorial');  // local mongodb에서 mongodb_tutorial 컬렉션에 커넥트

var boardSchema = mongoose.Schema({ // boardSchema 선언
    "idx": Number,
    "creator_id": String,
    "title": String,
    "content": String,
    "password": String,
    "image": Array,
    "hit": Number
}, {versionKey: false}/*__v버전키 필드 제거*/);

var Board = mongoose.model('boards', boardSchema);//Board를 통해 method(ex:  CRUD)를 적용함

//Select
Board.findOne({idx:idx}, (err, doc)=>{
  /* 작업내용, db에서 가져온 정보는 doc 객체에 저장되어있어 이를 이용 */
});

//Select and Update: 조건, update, option
Board.findOneAndUpdate({idx:idx}, {$inc: {hit: 1}}, {new:true}, (err, doc)=>{
  /* $inc로 hit을 1로 업데이트. new:true옵션으로 업데이트 결과를 페이지에 적용*/
});

//Insert: 해당 컬렉션에 맞는 객체를 선언하고 save를 통해 가능
var board1 = new Board({
        idx: 1,
        creator_id: creator_id,
        title: title,
        content: content,
        password: password,
        image: imageArray,
        hit: 0
    });

  //Update: 내용이 많아 항목으로 따로 정리

board1.save((err, doc)=>{//Board collection에 doc를 저장
  /* 작업 내용 */
});

//Delete: 조건으로 projection후 remove함
Board.remove({idx:idx}, (err)=>{
  /* 작업 내역 */
});
```
- #### mongoose update  
  - update시 데이터 삽입
    - Array 사용시 배열 선언하고 push메서드를 사용
    - push 는 object를 array에 추가. [1,2] + [4,5] >> [1,2], [4,5]
    - pushAll은 array를 array에 추가.[1,2] + [4,5] >> [1,2,4,5]
    - `upsert: bool(T/F) - creates the object if it doesn't exist. defaults to false.`
    ```
    Board.update({idx:idx}, {$pushAll: {image: imageArray}}, {upsert:true}, (err, doc)=>{ });
    ```
    ```
    ex) var imageArray=[];
        for(var i=0;i<image.length;i++){
          imageArray.push(image[i].filename);
        }
    ```
  -  update시 데이터 삭제
      - `new: true이면 삭제 한 데이터 반환 x, false이면 삭제한 데이터 반환`
      ```
      Board.findOneAndUpdate({idx:idx}, {$pull: {image: {$in: array}}},
         {'new':true}, (err, doc)=>{};
      ```

- #### mongodb-autoincrement 모듈을 통한 autoIncrement 기능
  - mongo에서 자체적으로 autoIncrement기능을 제공하지 않기 때문에 이 같은 모듈을 적용.
  - (추가) : 모듈을 쓰기에 자잘한 버그가 생길 수 있음. 그럴때는 만든 collection을 drop하고 사용..
```
//npm mongodb-autoincrement를 통해 idx 자동 증가 예시
autoIncrement.setDefaults({
  collection: "boards",   // 세팅 옵션 설정
  field: "idx",           // 적용할 필드
  step: 1                 // 얼마씩 올릴건지
});

mongoose.plugin(autoIncrement.mongoosePlugin, null);
```
https://www.npmjs.com/package/mongodb-autoincrement 참고


- #### mongoose에서 세션 사용하기
```
var db = mongoose.connection;
router.use(session({//express-session 필요.
  secret: '1234DSFs@adf1234!@#$asd', //secret , session id로 넣을 값. ()아무렇게쓰면 됨)
  resave: false,    // session을 계속 발생시키지 않도록
  saveUninitialized: true,  //session을 사용전까지 발급안함
  store:new MongoStore({mongooseConnection: db})
}));
```

- #### 참고사항
  - 다른 파일에서 connection으로 접근시 에러 발생. 아래와 같이 적용
`mongoose.createConnection('mongodb://localhost/mongodb_tutorial');`
