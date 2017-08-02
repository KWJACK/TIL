# Android 정리

## Service


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

## TMapPOIItem listView
  - ListView adapter에 연결하면 해당 데이터밖에 볼 수 없어서,
  - ListView로 보여줄 adapter(String)를 더미로 설정. 실제 adapter(POIItem)는 인덱스로접근
  - 이를 위해서 layout에 listview 두 개 선언, POIItem은 visible:gone으로 감춤

  ```
//변수 선언
  ArrayAdapter<String> mAdapter;
  ArrayAdapter<TMapPOIItem> mAdapterPOI;

//리스트뷰와 연결
  listView = (ListView) findViewById(R.id.listView);
  listViewNULLPOI = (ListView)findViewById(R.id.listViewNULLPOI);
  mAdapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1);
  mAdapterPOI = new ArrayAdapter<TMapPOIItem>(this, android.R.layout.simple_list_item_1);
  listView.setAdapter(mAdapter);
  listViewNULLPOI.setAdapter(mAdapterPOI);

//넣을 때는 String용 adapter와 POIItem용 adapter에 모두 삽입
  for (TMapPOIItem poi : arrayList) {    
       mAdapter.add(poi.getPOIName().toString()); //view 출력용(String)
       mAdapterPOI.add(poi);                      //실제 데이터 접근용
  }

  ...

//리스트 뷰 선택시 해당 view로 캐스팅해서 받지않고 index로 POIItem에 접근
  listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
      @Override
      public void onItemClick(AdapterView<?> adapterView, View view, int position, long l) {
        //position으로 접근        
          TMapPOIItem poi = mAdapterPOI.getItem(position);

      }
  });
```
