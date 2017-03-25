# python 문법

### dictionary
 - for문으로 출력시 순서를 보장하지 않는다
```
webster = {
   "Aardvark" : "A star of a popular children's cartoon show.",
   "Baa" : "The sound a goat makes.",
   "Carpet": "Goes on the floor.",
   "Dab": "A small amount."
}

for key in webster:
   print webster[key]
 ```
 - 이 때문에 내장함수인 `enumerate`를 사용해 인덱스로 접근한다.
 ```
choices = ['pizza', 'pasta', 'salad']
for index, item in enumerate(choices):
    print index+1, item
 ```
 1 pizza, 2 pasta, 3 salad

 #### 사전형 반복
```
d = {'x': 9, 'y': 10, 'z': 20}  #key : value

for key in d:                   # d에서 key값이 key로 넘어옴
    print key, d[key]           # ,를 통해서 붙여서 출력 가능
```
y 10, x 9, z 20
#### zip과 리스트
- 두 개의 리스트를 한 번에 반복 가능. `zip`을 통하면 요소의 쌍을 생성
 - 세 개 뿐아니라 더 많은 리스트도 가능. 짧은 리스트 끝부분에서 생성 종료
```
list_a = [3, 9, 17, 15, 19]
list_b = [2, 4, 8, 10, 30, 40, 50, 60, 70, 80, 90]
for a, b in zip(list_a, list_b):
    if a>=b:
        print a,
    else:
        print b,
```
3,9, 17, 15, 30
#### items : 순서 보장x
```
my_dict = {"name": "jack", "age": 23, "job": "student"}
print my_dict.items()
```
[('job', 'student'), ('age', 23), ('name', 'jack')]
#### For/else 문
- break없이 for문 종료시 else문 실행.
```
fruits = ['banana', 'apple', 'orange', 'tomato', 'pear', 'grape']
for f in fruits:
    if f == 'tomato':
        print 'A tomato is not a fruit!'
        break
    print 'A', f
else:
    print 'A fine selection of fruits!'
```
#### 문자열 뒤집기
- 음의 배열로 접근하면 뒤에서 부터 올라간다
```
def reverse(text):
    result= ""
    for char in range(-1,-len(text)-1,-1):
        result = result + text[char]
    return result
```
reverse("abcd") => dcba

#### 문자열 모음제거
```
def anti_vowel(text):
    new = ""
    for n in text:
        if n not in "aeiouAEIOU":   #해당 모음이 n과 일치하지않으면
            new = new + n
    return new
```
print anti_vowel(hey mr.lee) => hy mrl
#### 특정 문자열 *대체
```
def censor(text, word):
    a_txt=[]
    str_list = text.split()     # token
    print str_list
    for x in str_list:
        if x == word:
            a_txt.append('*'*len(x))
        else:
            a_txt.append(x)
    txt=" ".join(a_txt)         # join : 리스트를 " "에 따라 합침
    print txt
    return txt

def censor(text, word):
    return text.replace(word, ("*" * len(word)))
```
print censor('hi bob', 'bob') => hi ***


#### keys()와 values()
```
my_dict = {"name": "jack", "age": 23, "job": "student"}

def keys(dic):
    for x in dic:
        print x,

def values(dic):
    for x in dic:
        print dic[x],       # 쉼표는 공백추가와 다음 내용을 이어서 출력

print my_dict.keys(), my_dict.values()  
```
['job', 'age', 'name'] ['student', 23, 'jack']

#### 리스트 작성
- for/in으로 결합. 조건추가
```
evens_to_20 = [i for i in range(21) if i % 2 == 0]
print evens_to_20

even_squares = [x**2 for x in range(1,11) if x%2==0]
print even_squares
```
[0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20]
[4, 16, 36, 64, 100]

#### 슬라이싱
- `[start:end:stride]` start부터 end전까지 stride 간격으로
```
l = [i ** 2 for i in range(1, 11)]
# [1, 4, 9, 16, 25, 36, 49, 64, 81, 100]
print l[2:9:2]
```
[9, 25, 49, 81]

#### 람다 + filter
- `filter`는 무엇을 걸러낼지 판단하는데 람다를 사용
- `lambda variable: expression`
```
my_list = range(16)
print filter(lambda x: x % 3 == 0, my_list)

languages = ["HTML", "JavaScript", "Python", "Ruby"]
print filter(lambda x : x=="Python", languages)
```
[0, 3, 6, 9, 12, 15]
['Python']

### 이진법
#### 표현 `0b이진수`
```
print 0b1, #1
print 0b10, #2
print 0b11, #3
print "******"
print 0b1 + 0b11,
print 0b11 * 0b11
```
1 2 3
\*\*\*\*\*\*
4 9
#### 출력 `bin(), oct(), hex()`
```
print bin(1),
print bin(2)
print int("11001001",2) # int 두 번째 인자는 2진수임을 알려준다
```
0b1 0b10
201
