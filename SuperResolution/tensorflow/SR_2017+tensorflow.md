# SR_2017 Session
## 리눅스 서버 접속
### putty 세팅
 >`sudo nohup python ./main.py &` : 프로세스 중단을 무시하고 명령어 실행
 `cat nohup.out` :  프로세스 진행 사항 기록 확인
 `ps -ef` : 모든 프로세스 확인(백그라운드 포함)
 `sudo kill -9 pid` : 프로세스 종료

 ### notepad++를 이용한 소스편집
 >셋업 : notepad++, 플러그인 : nppftp설치
설정 : `플러그인` - `NppFTP` - `Show NppFTP Window` - `NppFTP window` - `profile setting`
hostname : `접속 ip`
port :`22`
connection type : `SFTP`

-------------
# Tensorflow Session

## 텐서보드 활용
`writer = tf.summary.FileWriter("./logs/logs1", sess.graph)`
명령어실행 : `tensorboard --logdir=/logs/log1`
실행 후 뜨는 url에 접속하여 확인

## 텐서 객체가 갖고 있는 값 확인
텐서 distances의 값을 보고 싶은 상황
콘솔에 값을 확인해보고 싶으면(텐서 객체가 아닌) 다음과 같이 적용
```
test_distance_val =  sess.run(distances)
print test_distance_val
```

##
- session(run)
  - 필수파라미터 fetches 와
  - 세 개의 옵션 파라미터(feed_dict, options, run_metadata) 존재
  - fetches가 리스트라면 run()의 출력은 요청된 항목들 출력 값 리스트 형태
  - feed_dict : 입력 객체는 딕셔너리 형태

## 주요함수
tensorflow 1.0.0 버전으로 업그레이드 되면서 이름이 바뀐 함수들 참고 URL
https://tensorflow.blog/2016/12/22/tensorflow-api-changes/

|함수|설명|예시|
|----|-------|-------|
|tf.shape| 텐서의 구조 확인|
|tf.size|텐서의 크기 확인|
|tf.rank|텐서의 랭크|
|tf.reshape|텐서의 원소는 그대로 유지하면서 구조 변경|
|tf.squeeze|텐서에서 크기가 1인 차원 삭제|
|tf.expand_dims(vectors, 0:channel)|텐서에 차원 추가|
|tf.slice|텐서의 일부분 삭제|
|tf.split|텐서를 한 차원 기준으로 여러 개의 텐서로 나눔|
|tf.tile|한 텐서를 여러번 중복해 늘려 새 텐서를 만듬|
|tf.concat|한 차원을 기준으로 텐서를 이어붙임|
|tf.reverse|텐서의 지정된 차원을 역전시킴|
|tf.transpose|텐서를 transpose|
|tf.gather|주어진 인덱스에 따라 텐서의 원소를 모음|
|||
|tf.argmin|지정한 차원을 따라 가장 작은 값의 원소가 있는 인덱스 리턴|
|tf.argmax|큰 값의 원소가 있는 인덱스 리턴 |
|tf.where| |
|tf.assign|add처럼 표현 그래프의 일종. run()으로 해당 표현을 실행해야 실제 대입연산을 수행|
```
tf.slice(v1, [0, 2], [1, 2])        # [[3 4]] 0행 2열이 시작, 1차원 배열로 2개 갖고옴
tf.slice(v1, [0, 2], [2, 2])        # [[3 4] [9 0]] 2차원 배열로 2개 갖고옴
tf.slice(v1, [0, 2], [2,-1])        # [[3 4 5 6] [9 0 1 2]] 2차원 배열로 끝까지
tf.vectors의 shape를 확인하고 싶을 때
print vectors.get_shape()
```
## 텐서 생성 함수
아래 함수로 텐서를 생성시킬 수 있다

|함수|설명|
|------|-----------|
|tf.zeros_like|모든 원소를 0으로 초기화한 텐서 |
|tf.ones_lie|모든 원소를 1로 초기화|
|tf.fill|주어진 스칼라 값으로 원소 초기화|
|tf.constant|함수 인수로 지정된 값을 이용해 상수 텐서 생성|
|||
|tf.random_normal|정규분포를 따르는 난수로 텐서 생성|
|tf.truncated_normal|정규분포이되, 크기가 표준편차의 2배수보다 큰 값은 제거|
|tf.random_uniform|균등분포를 따르는 난수로 텐서 생성|
|tf.random_shuffle|첫 번째 차원을 기준으로 텐서의 원소를 섞음|
|tf.set_random_seed|난수 시드를 설정|

```
v5 = tf.Variable([[False, True], [True , False]])
functions.showOperation(tf.where(v5))               # [[0 1] [1 0]]
```
