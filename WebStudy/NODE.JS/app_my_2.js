//require : express, body-parser, orientdb
const express = require('express');
var app = express();
var OrientDB = require('orientjs');
var server = OrientDB({
  host: 'localhost',
  port: 2424,//orientdb port
  username: 'yourname(defualt: root)',
  password: 'yourpassword'
})
var db = server.use('your orientDB name');//서버이름 작성
var bodyParser = require('body-parser');
app.use(bodyParser.urlencoded({extended: false}));
app.locals.pretty = true;   //pug작성시 html출력 예쁘게

//pug엔진 정의
app.set('view engine', 'pug');
app.set('views', './views_orientdb');

//리슨. 해당 포트는 웹서버 접속 포트
app.listen(3000, ()=>{
  console.log("server connected, 3000!");
})

//add 페이지 작성
app.get('/topic/add', (req, res)=>{
  var sql = "SELECT FROM topic";
  db.query(sql).then((results)=>{
    //add.pug로 연결. 넘길 인자는 리스트 출력을 위한 인자 1개(topic)
    res.render('add', {topics:results});//results query를 topics라는 변수로 add.pug에 주입
  });
})

//add페이지 - submit버튼을 처리하는 부분(post)
app.post('/topic/add', (req, res)=>{
  //title, description, author body-parser로 얻기
  var title = req.body.title;
  var desc = req.body.description;
  var author = req.body.author;
  //삽입(INSERT SQL작성)
  var sql = "INSERT INTO topic (title, description, author) VALUES(:t, :d, :a)";
  //쿼리 작성. params 주의
  db.query(sql, {
    params:{
      t:title,
      d:desc,
      a:author
    }
  }).then((sel)=>{
    //작성한 포스트로 이동. sel에 rid를 통해 접근가능하다
    //제출 후 페이지 되돌리기(redirect). js문법 : encodeURIComponent
    res.redirect('/topic/'+encodeURIComponent(sel[0]['@rid']));
  });
});

//토픽 클릭시 처리 제목과 리스트를 동시에 처리
app.get(['/topic','/topic/:id'], (req, res)=>{
  var sql = "SELECT FROM topic";
  db.query(sql).then((results)=>{
    //req에서 id값 얻기. body-parser가 아님
    var id = req.params.id;
    if(id){
        //리스트 클릭시 id에 따른 처리(sql, query)
        //view.pug로 렌더링. 넘길 인자 topics<-results, selected<-sel[0]
        var sql = "SELECT FROM topic WHERE @rid=:rid";
        db.query(sql,{params:{rid:id}}).then((sel=>{
          res.render('view', {topics:results, selected:sel[0]})
        }));
    }
    //제목 클릭시 view.pug. 넘길 인자는 하나
    else{
      res.render('view', {topics:results});
    }
  });
});

//delete 선택 시 해당 id의 db를 제거. :id는 변수
app.get('/topic/:id/delete', (req, res)=>{
  //전체 목록 조회를 위한 sql 작성
  var sql = "SELECT FROM topic"
  //쿼리 실행
  db.query(sql).then((results)=>{
    var id = req.params.id;
    var sql = "SELECT FROM topic WHERE @rid=:rid";
    db.query(sql, {params:{rid:id}}).then((sel)=>{
      res.render('delete', {topics:results, selected:sel[0]});
    });
  });
});

//delete 버튼 처리(post)
app.post('/topic/:id/delete', (req, res)=>{
  //req에서 id 얻고 sql문 작성
  var id = req.params.id;
  var sql = "DELETE FROM topic WHERE @rid=:rid";
  //쿼리 작성
  db.query(sql, {params:{rid:id}}).then((sel)=>{
    res.redirect('/topic/');
  });
});

//edit 기능. edit이므로 특정 id에 대해 접근해야함
app.get('/topic/:id/edit', (req, res)=>{
  //전체 목록 조회
  var sql = "SELECT FROM topic";
  db.query(sql).then((results)=>{
    var id = req.params.id;
    var sql = "SElECT FROM topic WHERE @rid=:rid";
    db.query(sql, {params:{rid:id}}).then((sel)=>{
      res.render('edit', {topics:results, selected:sel[0]});
    });
  });
});

//edit한 내용을 UPDATE (POST)
app.post('/topic/:id/edit', (req, res)=>{
  //sql에 필요한 정보 title, description, author, rid
  var sql = "UPDATE topic SET title=:t, description=:d, author=:a WHERE @rid=:rid";
  var id = req.params.id;
  var title = req.body.title;
  var desc = req.body.description;
  var author = req.body.author;
  //내용은 body-parser이용
  db.query(sql, {
    params:{
      t:title,
      d:desc,
      a:author,
      rid:id
    }
  }).then((sel)=>{
    res.redirect('/topic/'+encodeURIComponent(id));
  });
})
