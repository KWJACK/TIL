# Manual of MarkDown

마크다운 사용 정리 페이지 -jack

## 글자크기

글자 크기는 #의 갯수로 나뉜다.


# # First

## ## Second

## 글자 서식

**굵게** :  \*\*굵게\*\*

*기울기* :  \*기울기\*

$Itelic$ : \$Itelic\$

~~글자취소~~ : \~\~글자취소\~\~

~아래첨자~ : \~아래첨자\~

`글자 배경색` :   \`글자 배경색\`


<kbd>Ctrl+E</kbd>  : \<kbd\>Ctrl+E\</kbd\>


**참고)** \*,\~ 과 같이 예약어를 본문에 삽입하고자 할 때는 \\를 앞에 붙여 만든다.


## Tables

| 기호를 통해 만든다. 직접 테이블을 그린다고 보면 댐

| Item | Value |
 |----------|-------|
 | Computer | $1600 |
  | Phone | $12 |
   | Pipe | $1 |

| | Item | Value |

|----------|--------|

| Computer | \$1600 |

| Phone | \$12 |

| Pipe | \$1 |

행을 정렬하고 싶으면 ':' 기호를 사용 ':'이 왼쪽에 있으면 왼쪽 정렬,

오른쪽으면 오른쪽 정렬 둘다 있으면 중앙
칸 내에서 줄바꿈은 `<br>`을 통해 가능.
Item     | Value | Qty
:------- | ----: | :-:
Computer | $1600 |  5
Phone    |   $12 | 12
Pipe     |    $1 | 234



## 배경 바꿔보기

문단 배경색 전환 ``` 기호

```
// Foo
var bar = 0;
```
편집 child2
배경이 끝날 때 ```으로 마무리

**참고)** \'글자\'는 글자배경색을 지정함.


## 하이퍼링크

[하이퍼링크](웹주소)

[구글](www.google.com)

## 글 서식

- 선(대시) 글 머리 기호 -를 시용

> 인용문은 \>를 통해 가능하다.

## 주석달기
주석을 달아봅니다 [^1]. 문법 : \[\^1\]
주석을 달고 적당한 곳에서 `[^1]: 내용 입력` 으로 내용 기입
## 기타

줄 바꿈은 엔터 두 번
강제 개행 `<br>`

## 아톰 에디터
<kbd>shift</kbd> + <kbd>alt</kbd> + <kbd>p</kbd> : project-manager가 저장한 목록 불러오기
<kbd>ctrl</kbd> + <kbd>shift</kbd> + <kbd>i</kbd> : 이미지 추가(markdown_enhance필요)


## markdown2html
pandoc 설치 후 다음 명령어 적용
`pandoc test1.md -f markdown -t html -s -o test1.html`

[^1]: 테스트용 주석 입니다
