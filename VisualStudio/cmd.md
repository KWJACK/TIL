# 해당 포스트는..
cmd로 할 수 있는 것을 정리하는 포스트 입니다.

------------------------
### 노트북 wifi AP 만들기
#### Set up
  - 아래 내용을 순차적으로 수행합니다.
  - 노트북에 랜선을 꼽아 이더넷 네트워크 연결 확인

#### cmd
- netsh wlan show drivers
  - 호스트된 네트워크 지원 : 예 확인
- netsh wlan set hostednetwork mode=allow ssid=name key=password
- netsh wlan start hostednetwork
  - 호스트된 네트워크를 시작했습니다  
  - 이 단계에서 노트북 wifi활성화
> **참고**
>- netsh wlan show hostednetwork
>  - 연결된 내역 확인
>- netsh wlan stop hostednetwork
>    - 연결 중지
>- netsh wlan set hostednetwork mode=disallow
>    - hostednetwork 제거


#### 네트워크 속성
`제어판`-`네트워크 및 인터넷`- `네트워크 연결`-`이더넷 속성`-`공유`

공유에서 체크 박스 모두 클릭. 홈네트워킹 연결시 hostednetwork에 맞는 로컬 선택

#### 실행
 모바일 기기로 접근.
  완료

 ---------------------------

### 데스크탑 화면 변경
데스크탑이 추가되어 있어야함

<kbd>ctrl</kbd>+<kbd>window</kbd>+<kbd><-</kbd>
