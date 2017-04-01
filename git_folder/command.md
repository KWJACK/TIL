Git 새 저장소 만들기
====================
### 로컬에 git 아이디 추가하기

```
git config --global user.email "your@example.com"
git config --global user.name "Your name"
```
 아이디를 추가함으로써 협업시 누가 수정했는지 어디서 작업했는지 구분 가능

### 새 저장소 만들기

> 1.	**git init**
> 2.	**git remote add origin 원격 서버 주소**

원하는 폴더에서 **git init** 로 사전 준비

원격 서버 주소에 링크

원격저장소에 내용 push & pull
=============================

### 새 내용 업데이트 하기

> 1.	git add 파일 이름 or git add \*
> 2.	**git commit -m "설명 메시지"**
> 3.	**git push origin master**

### git 원격저장소에 있는 내용 로컬에 합치기

> 1.	**git pull origin master**
> 2.	**git merge origin master**

여러 디렉토리에서 특정 디렉토리만 pull하기
==========================================

주어진 디렉토리 계층에서 Example2만 pull하고 싶을 때

-	mainProject

	-	Example1

	-	Example2

> 1.	git init examGit // 어디에 저장할지, init으로 설정
> 2.	cd examGit
> 3.	git remote add -f origin [remote url]
> 4.	git config core.sparseCheckout TRUE // .git/config에 해당 내용 추가
> 5.	echo "mainProject/Example2">> .git/info/sparse-checkout
> 6.	git pull origin master //원격저장소로부터 pull

#  
