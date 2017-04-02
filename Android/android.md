# Android 정리
## XML 속성 정리
```
<LinearLayout
       android:layout_width="match_parent"
       android:layout_height="match_parent"
       android:id="@+id/layout_page1"
       <!-- insert your item -->
</LinearLayout>
```
- wrap_content : item 크기만큼
- match_parent : parent layer에 귀속

## Btn listner를 만드는 방법
#### xml + C스타일로 만들기
- layout_xml - 버튼 속성 onClick 추가
`android:onClick="btnOFF"`

- 생성 버튼에 대한 함수 선언
```
Button btnLEDOff = (Button)findViewById(R.id.yourid);
public void btnOFF(View v){
  /*your code*/
}
```
## Thread 이용 방법
#### Thread 클래스 생성
```
public class SendData implements Runnable{//쓰레드 객체 클래스
        String flag="";
        public SendData(String param){//생성자에서 쓰레드 인자를 받을 수 있음
            this.flag = param;
        }
        @Override
        public void run() {//쓰레드 실행 함수
            /*your code*/
    }
```

#### Thread 실행
```
Runnable LEDOFF = new SendData("1");//Thread 생성, String 으로 "1" 전달
new Thread(LEDOFF).start();//run
```

## UDP 연결
(for me : TESTUDP 프로젝트에 생성)
- 필수 임포트
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
- manifest 선언문 추가
<uses-permission android:name="android.permission.INTERNET" />

- UDP 코드
  ```
  try{
     DatagramSocket socket = new DatagramSocket();
     //ip 할당
     InetAddress serverAddr = InetAddress.getByName("yourIPAddress");

     //버퍼 할당
     byte buf[1024];
     DatagramPacket packet = new DatagramPacket(buf, buf.length, serverAddr,port);
     //send
     socket.send(packet);
     //recv
     socket.receive(packet);

     String msg = new String(recvpacket.getData());
     txtView.setText(msg);//recv 메시지 출력
  }catch(Exception e){
    /*your exception code*/
  }
  ```
