y# MySQL
 - Structured Query Language
- 정보를 관리하는 전문 관계형 데이터베이스 애플리케이션
- 인덱싱으로 접근이 빠르다
- 프로그래밍적으로 정보 제어
- open source형태로 WEB과 같이 성장한 언어

웹브라우저(Client)->웹서버(Server)->PHP(Client)->MySQL(Server)

#### mysql 모니터 위치
C:\Bitnami\wampstack-5.6.30-1\mysql\bin에 mysql.exe를 다음 명령어로 실행
> cf. cmd에서 작업표시창 우클릭하여 속성->옵션->빠른 편집 모드 선택시
복사& 붙여넣기 기능 활성화

```
mysql -hlocalhost -uroot -p     
```
- hlocalhost : mysql 서버 주소
- uroot : localhost에 존재하는 서버에 root로 접근
- p : 비밀번호 입력 옵션
-----
## MYSQL 명령어
  DATABASE에 여러 TABLE이 있는 구성
- DATABASE 보기
 ```
 show databases;
 ```

 - DATABASE 생성
 ```
CREATE DATABASE opentutorials CHARACTER SET utf8 COLLATE utf8_general_ci;
```

 - DATABASE 설정
 ```
 use opentutorials
 ```

- `topic`이라는 테이블 생성
```
 CREATE TABLE `topic` (
      `id` int(11) NOT NULL AUTO_INCREMENT,
      `title` varchar(100) NOT NULL,
      `description` text NOT NULL,
      `author` varchar(30) NOT NULL,
      `created` datetime NOT NULL,
      PRIMARY KEY(id)
      ) ENGINE=InnoDB DEFAULT CHARSET=utf8;
```
- 테이블 확인
```
show tables;
```

- 데이터 삽입
```
INSERT INTO \`topic\` (\`id\`, \`title\`, \`description\`, \`author\`, \`created\`) VALUES(3, 'Opeartor', 'Operator is ~', 'egoing', '2015-06-18 05:00:00');
```

- 테이블 값 확인
```
SELECT id, title, author, created FROM topic ORDER BY author DESC
SELECT id, title, author, created FROM topic WHERE id=3
```
  1. author순으로 내림차순
2. id가 3인 row를 갖고옴

- 테이블 정보 확인
```
DESC topic;
```

--------
## MYSQL 실습
 php가 제공하는 mysqli(내장함수)를 사용해 mysql을 다룰 수 있다.

 **MYSQL monitor 흐름 : 서버접속 -> DB선택 -> 조회 -> 출력**

**서버접속**
*(아래는 mysql과 대응하는 php코드)*

 mysql> mysql -hlocalhost -uroot -p11111;
- \$conn = mysqli_connect('localhost', 'root', 11111);

**DB선택**
mysql> use opentutorials;
- mysqli_select_db($conn, 'opentutorials');

**조회**
mysql> SELECT *FROM topic;
- \$result = mysqli_query(\$conn, 'SELECT*FROM topic')

**출력**
mysql> 자동 출력
- \$row = mysqli_fetch_assoc(\$result);
\$row['title'];
\$row['description'];

## 실습 목표

1. mysql에 url을 db화시켜 저장
2. 저장한 url을 php에서 쿼리를 보내 db를 얻고 출력
3. 웹에서 mysql로 데이터 보내기

### 1. mysql 연동
(sql에 db넣는 과정 생략)
```
<?php
$conn = mysqli_connect("localhost", "root", "****");        # **** : mysql설치시 설정한 비밀번호
mysqli_select_db($conn, "opentutoridals");                  #DB이름
 $result = mysqli_query($conn, "SELECT * FROM topic");      #쿼리. DB의 테이블(topic)을 받아옴
?>
```

### 2. mysql DB로 웹 head와 body내용 출력
헤더
```
<?php
    do {
        $row = mysqli_fetch_assoc($result);                 #assoc 배열로 row에 접근
        echo '<li><a href="http://localhost:81/php/index.php?id=\
        '.$row['id'].'">'.$row['title'].'</a></li>'."\n";   #출력. 하이퍼링크설정        
    } while ($row);
 ?>
```
리스트
```
<article>
    <?php
      if(empty($_GET['id']) === false ) {           #DB내 table의 모든 내용 출력
          $sql = 'SELECT * FROM topic WHERE id='.$_GET['id'];   #id로 sql접근
          $result = mysqli_query($conn, $sql);      #쿼리 send
          $row = mysqli_fetch_assoc($result);       #assoc 형태로 받음
          echo '<h2>'.$row['title'].'</h2>';        #제목과 내용 출력
          echo $row['description'];
      }
     ?>
</article>
```

### 3. 쓰기 interface 페이지(write.php) 만들기
```
<form action="http://localhost:81/php/process.php" method="post">   #form을 해당 주소에 post방식으로 전송
    <p>제목 : <input type="text" name="title"></p>
    <p>작성자 : <input type="text" name="author"></p>
    <p>본문 : <textarea name="description"></textarea></p>
    <input type="submit" name="name">
</form>
```
### 4. php에서 mysql로 데이터 쓰기(process.php)
```
<?php
$conn = mysqli_connect("localhost", "root", "****");    #mysql 접근
mysqli_select_db($conn, "opentutoridals");              #DB설정

#insert query문 작성
$sql = "INSERT INTO topic (title,description,author,created)\
 VALUES('".$_POST['title']."', '".$_POST['description']."', '".$_POST['author']."', now())";
#echo $sql;             #잘 되나 확인
$result = mysqli_query($conn, $sql);                    #sql로 보냄
header('Location: http://localhost/index.php');         #보낸 후 homepage로 이동
?>
```
## 실습결과
#### mysql에 저장한 url 받아 출력
![3](https://cloud.githubusercontent.com/assets/20148930/24071738/dbf141d0-0c1c-11e7-83a1-68a4fe602d4c.JPG)

#### 쓰기페이지
![4](https://cloud.githubusercontent.com/assets/20148930/24071739/dc30047e-0c1c-11e7-9271-8fa892c9c286.JPG)

#### 쓰기에서 작성한 결과물을 mysql에 insert(id=0)
![2](https://cloud.githubusercontent.com/assets/20148930/24071736/dbad379c-0c1c-11e7-886f-ac7d8ec15c09.JPG)
