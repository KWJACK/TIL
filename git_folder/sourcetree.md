# **SourceTree**

## 1\. Setting

우선 범용성을 위해 source tree를 영어로 바꾼다 tools(도구)에서 언어를 영어로 변경

### 1-1\. 로컬에 git 아이디 추가하기

- Tools Options 에서 Uer information란을 채워 local 이용자를 설정함

### 1-2\. 새 저장소 만들기

- clone/new에서 repositoy 추가가능.

- create new repository에서 어떤 프로젝트를 추가할지 path 설정

### 1-3\. 용어 정리

- repository -> repository는 관리할 프로젝트의 디렉토리

- commit -> 버전 하나를 만드는 행위

- add -> git에 변경된 파일을 추가하는 행위

- idex / staging area > Log / History에서 Unstaged files(working copy)상에 수정된 파일 존재

  add된 파일은 staged files에 올라간다. 해당 영역은 index 또는 staging area 라고 함

  staging area에 있는 파일에 대해 commit하면 repository에 등록됨.

--------------------------------------------------------------------------------

## 2\. 수정전 상태로 돌아가기

(Discard 메뉴에서 지원)

commit 하기전의 내용을 discard를 통해 이전 상태로 돌아갈 수 있다

불필요한 수정을 줄이기 위해 **commit 하기 직전 리뷰하는 습관**을 기른다.

빨간 줄(삭제) / 초록 줄(수정)

### 2-1\. Reset

돌아가고 싶은 commit으로 간다면 커밋에서 우클릭 하여 Reset to commit으로 이동 Using mode에 따라 다름

_Hard - discard all working copy changes(매우 조심해서 사용)_

- 선택 commit이 최신으로 되고 이전 최신사항이 **모두** 사라진다.

- 프로젝트의 내용물도 같이 수정됨

  _Mixed(Default) - keep working copy but reset index_

- 선택 commit을 최신으로 바꾸면서 이전 최신 commit을 모두 삭제,

- but, **working copy의 내용은 update하고 싶지 않을 때** 사용

  _Soft - keep all local changes_

### 2-2\. Revert

선택한 version을 취소하고 이전 version으로 돌아가는 것. commit된 버전을 삭제하지 않으면서 이전 commit의 내용으로 돌아가고 싶을 때 사용

- revert 실행시 돌아가고 싶은 version의 새로운 commit이 자동 생성되며 header 이동
- Revert된 commit에서 다른 Revert를 설정하려면 **역순으로 commit을 역전시켜 가야한다.**
- 역순으로 revert하지 않으면 **충돌(conflict)이** 발생할 수 있다.

--------------------------------------------------------------------------------

## 3\. Branch

안정적인 작업과 불안정한 작업을 동시에 할 때 사용 -

branch를 이용해 불안정한 작업이 **취소(drop)되면 해당 부분을 도려낼 수 있다.**

혹은 불안정한 작업을 안정적인 곳에 합칠 때(merge) 편리하게 합칠 수 있다.

### 3-1\. branch 만들기

New Branch로 생성할 수 있다.

branch간 이동은 더블클릭(current branch)가 된다.

### 3-2\. branch 합치기

master와 example 브랜치가 있을 때, example의 내용을 마스터로 추가하는 상황

1. 받는 쪽의 브랜치를 선택한 다음(master를 current branch로)
2. 병합하고자 하는 branch(example)를 merge example into current branch로 선택.

  이를 master 브랜치로 **체크아웃** 했다고 한다.

### 3-3\. branch 충돌의 해결

두 브랜치에서 서로 같은 라인을 수정하고 merge한 경우 conflict가 발생한다.

발생한 지역에 대해 다음과 같은 형태로 발생한다.

```
  >>>>> HEAD
      master 브랜치에서 새롭게 수정한 내역
  ========
      example 브랜치에서 새롭게 수정한 내역
  <<<<< example
```

git이 병합하지 않고 개발자에게 수정권한을 넘기는 형태이다.

> #### 해결방법

> 1. master에서 코드에 있는 >>>> ==== \<\<\<< 부분의 conflict를 수정
> 2. sourcetree에서 [!]파일을 우클릭하여 resolve conflict -> mark resolved 클릭
> 3. 다시 commit하여 수정적용 - 이 때에는 git에서 conflict를 수정한 상태로 인식하여 자동 commit 내역이 남아있다.
> 4. 여기에 보충해 commit을 작성한다

### 3-4\. branch 충돌 최소화

## cf. 아이콘 상태

[?] : 아직 Git에 추적되기전 상태의 파일

[...] : Git에 의해서 추적되고 있는 파일. commit하여 저장소에 보관할 수 있는 파일

[+] : 새롭게 Git이 추적하도록 추가되었다는 상태 표시

[!] : conflict 발생
