## 서버 실행 A to Z

1. bitnami에서 mysql 서버가 running 중인지 확인
2. HeidiSQL 실행
3. `C:\Users\Coms7\Desktop\assigment2\joinForm` 에서 npm start실행
4. `http://localhost:3000/board` 로 접속

## 이미지 삽입하기
- img폴더 생성

- form 방식에 enctype속성 추가
`<form action="/board/write" method="post" onsubmit="return onWriteSubmit()" enctype="multipart/form-data">`
 (enctype는 파일을 서버로 전송할 수 있도록 함)


- 파일업로드 버튼 추가
`<input type="file" name="attachFile">`
<input type="file" name="attachFile">


- multer 추가(`npm install multer --save`)
var multer = require('multer');
var upload = multer({dest: 'public/images'}); //multer의 저장 디렉토리 옵션 설정


- post 함수에 upload 추가
`router.post('/write', upload.single('avatar'), (req, res, next)=>{`
 upload(multer) 미들웨어가 우선 실행. req에 file property를 추가해준다.


## 글 삭제하기
글 삭제시 비밀번호를 확인하여 맞았을 때만 삭제
삭제 시 게시글에 이미지가 있는 경우 DB뿐만 아니라 서버에서 파일 이미지도 삭제해야함
`Server side(nodejs)`
```
router.post('/deleteConfirm/:idx', (req, res)=>{//POST형식
  var passwd = req.body[0].value;  //JSON형태에서 value(passwd를 받음)
  var idx = req.params.idx;
  pool.getConnection((err, connection)=>{//connection하여 sql 쿼리 보냄
    var sql = "SELECT passwd, image FROM board WHERE idx=?";
    connection.query(sql, idx, (err, results)=>{//passwd와 image는 results에 저장
      var sql = "DELETE FROM board WHERE idx=?";
      if(results[0].passwd == passwd){  //passwd가 일치하면
        if(results[0].image==""){       //image가 없는 글일 경우
          connection.query(sql, idx, (err, results)=>{
            res.redirect('/');          //redirect후 read.ejs에서 처리
          });
        }else{//이미지가 있으면 DB뿐아니라 서버에서 이미지 파일도 같이 삭제해야함
          fs.unlink('public/images/'+ results[0].image, (err)=>{//unlink=파일삭제
            if(err)console.log(err);
            else{
               connection.query(sql, idx, (err, results)=>{
                 console.log("delete the board in DB");
                 res.redirect('/');
               });
            }
          });
        }//image가 있다면(else)
      }

      else{/*pass가 일치하지 않는 경우*/}
      connection.release();       //connection 해제
    });
  });
});
```
`Client side(jqeury)`
```
$.ajax({  //nodejs쪽에 POST형태로 ajax
      type: 'POST',
      data: JSON.stringify(password.serializeArray()),  //JSON 오브젝트 형태로 넘김
      contentType: 'application/json',
      url: 'http://localhost:3000/board/deleteConfirm/<%=row.idx%>',  //URL표시는 완벽하게
      success: function(data) { //redirect(success)시 해당 실행
          alert("삭제완료");
          location.href ="http://localhost:3000/board";
      }
  });
```

## 레이어창 만들기
`javascript`
1. dialog로 쓸 div 태그 등록
```
<div id="dialog-login" title="로그인">
    <p>id:  <input type="text" name="username" id="username" palceholder="username"></p>
    <p>pw: <input type="password" name="password" id="password" palceholder="password"></p>
</div>
```
2. dialog창 객체 생성
```
var dialog_newlogin = $("#dialog-newlogin").dialog({
  autoOpen: false, //이벤트 발생시 오픈
  height: 250, //높이
  width: 300, //넓이
  modal: true,//레이어창 생성시 부모창 선택 불가
  buttons:{
        "확인": confirmLogout,
        "취소": closeDialog,
      } });

function confirmLogout(){
  location.href ="http://localhost:3000/join/logout";//redirect
  $(this).dialog( "close" );//레이어창 종료
}
```
3. 버튼 태그 생성
`<input type="button" id="login" name="join" value="가입">`

4. jquery를 이용해 버튼 함수 등록, 내용 채우기
```
$("#login").button().on("click", function(e){ //button().on()은 jquery의 css 속성이 적용
  if($(this).html()=='로그인'){          // html()은 버튼 이름을 뜻함
    $("#dialog-login").dialog("open");  //1에서 쓴 div 태그 이름
    e.preventDefault();
  }else{
    location.href ="http://localhost:3000/join/logout";
  }
});
```

## jquery로 ajax 통신방법
```
var userinfo = {  //ajax로 넘겨줄 데이터는 튜플식으로 작성
  username: $("#username").val(),
  password: $("#password").val()
};

$.ajax({
      type: 'POST',
      data: JSON.stringify(userinfo), //JSON형태로 넘김
      contentType: 'application/json',
      url: 'http://localhost:3000/join/login',
      success: function(data) { //완료시 취할 행동 정의. 옵션으로 없어도 됨
          alert("로그인 완료");
          location.href ="http://localhost:3000/board";
      }
  });
```

## passport + session을 이용한 게시물 삭제
https://github.com/KWJACK/TIL/blob/master/WebStudy/Nodejs.md passport + 암호화 설명 참고

- board.js (nodejs)
```
router.post('/deleteConfirm/:idx', (req, res)=>{//POST형식
  var passwd = req.body.password;  //JSON형태의 값에서 value(passwd를 받음)    
  var idx = req.params.idx;
  hasher({password: passwd, salt: req.user.salt},function(err, pass, salt, hash){ //복호화  
    pool.getConnection((err, connection)=>{         // DB connection
      var sql = "SELECT password, image FROM board WHERE idx=?";
      connection.query(sql, idx, (err, results)=>{  // passwd와 image는 results에 저장
        var sql = "DELETE FROM board WHERE idx=?";  // DB 삭제하는 sql
        if(results[0].password == hash){            // passwd가 일치하면
          if(results[0].image==""){                 // image가 없는 글일 경우
            connection.query(sql, idx, (err, results)=>{
              res.redirect('/');                    //글 삭제 후 board로 돌아옴
            });
          }else{      //이미지가 있으면 DB뿐아니라 서버에서 이미지 파일도 같이 삭제해야함
            fs.unlink('public/images/'+ results[0].image, (err)=>{    //unlink=파일삭제
              if(err)console.log(err);
              else{
                 connection.query(sql, idx, (err, results)=>{
                   console.log("delete the board in DB");
                   res.redirect('/');
                 });
              }
            });
          }//image가 있다면(else)
        }
        else{/*pass가 일치하지 않는 경우*/}
        connection.release();
      });
    });
  });
});
```

- read.ejs(javascript 부분)
```
password 대상 html소스 : <input type="password" name="mypassword" id="mypassword">
-------------------------------------------------------------------------------------
<script>
...

var password = { password: $("#mypassword").val() }; id mypassword 태그의 value를 튜플로 저장
$.ajax({
      type: 'POST',
      data: JSON.stringify(password),     //오브젝트 형태로 넘김
      contentType: 'application/json',
      url: 'http://localhost:3000/board/deleteConfirm/<%=row.idx%>',  //보낼 위치
      success: function(data) {   // 정상 처리후 취할 액션
          alert("삭제완료");
          location.href ="http://localhost:3000/board";
      }
  });

...
</script>
```
