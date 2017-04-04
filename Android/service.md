## Service
- 4대 컴포넌트 중 하나
- Service를 통해 백그라운드에서 실행할 동작을 제어
- 통신을 위해 Service 선택
  - (IntentService는 데이터를 액티비티에 보내는 게 복잡함)

#### 사용 순서
##### 참고 http://twinw.tistory.com/50 흰고래의 꿈
- 1. 사용할 service (\*.java) 생성.
`Service 탭이 따로 있음`
`MyService.java`
- 2. Manifest.xml에  Service 자동 등록
`<service android:name="MyService"`
`android:enabled="true"`
 `android:exported="true"></service>"`
 - 3. <kbd>Ctrl</kbd> + <kbd>O</kbd>를 통해 onCreate, onStartCommand, onDestory 추가
    ```
    @Override
    public void onCreate() {//최초 생성시 한 번 실행
        super.onCreate();
    }

    @Override
    public void onDestroy() {//서비스 종료시 실행할 작업
         super.onDestroy();
     }

     @Override
     public int onStartCommand(Intent intent, int flags, int startId) {
        //핸들을 정의해 쓰레드가 핸들을 이용하도록 한다
         return super.onStartCommand(intent, flags, startId);
     }
    ```
- 4. Activity에서 Service 호출
    ```
    btnPlay.setOnClickListener(new View.OnClickListener(){
        @Override
        public void onClick(View v){
            Toast.makeText(getApplicationContext(), "Service시작",Toast.LENGTH_SHORT).show();
            //인텐트를 생성하여 service로 넘겨준다
            Intent startIntent = new Intent(MainActivity.this, MyService.class);
            int count =1;
            startIntent.putExtra("count", 5);// intent에 값을 넣어 보내줄 수 도 있음
            startService(startIntent);
        }
    });
    ```
- 5. Thread 클래스
  ```
  public class ServiceThread extends Thread {
      Handler handler;
      boolean isRun = true;  
      public ServiceThread(Handler handler){
          this.handler = handler;
      }  
      public void stopForever(){  //Service에서 onDestroy를 통해 실행
          synchronized (this) {
              this.isRun = false;
          }
      }
      @Override
      public void run(){
          //반복적으로 수행할 작업 기재
          //example
          while(isRun){
              handler.sendEmptyMessage(0);//쓰레드에 있는 핸들러에게 메세지를 보냄
              try{
                  Thread.sleep(3000); // 3초씩 쉰다.
              }catch (Exception e) {}
          }
      }
  }
  ```
- 6. Service에서 StartCommand()
    ```
    public int onStartCommand(Intent intent, int flags, int startId) {
            //Activity에서 넘긴 값을 받음. 자료형에 따라 선언 가능       
            count = intent.getIntExtra("count", flags);
            myServiceHandler myHandler = new myServiceHandler();//핸들 등록
            Mythread = new ServiceThread(myHandler);//쓰레드에 핸들을 넘겨 쓰레드가 핸들을 실행하도록
            Mythread.start();
            return super.onStartCommand(intent, flags, startId);
        }
    ```
- 7.  handle 클래스 선언
  ```
    class myServiceHandler extends Handler{
      @Override
      public void handleMessage(android.os.Message msg) {//쓰레드에서 전달한 메시지를 실행
          Intent intent = new Intent(MyService.this, MainActivity.class);        
          //your code //
          /*example*/
          Toast.makeText(MyService.this, ""+count, Toast.LENGTH_SHORT).show();
          count++;
      }
  };
  ```
