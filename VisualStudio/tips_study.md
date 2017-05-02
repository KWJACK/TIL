# 팁스 스터디 정리 4/1|

## SubClassing
Sub + class : class-> window class의 약자
sub 부(cf. super : 주)


----------------
## OwnerDraw 실습
- Owner-Draw : 한 아이템의 색상 등을 커스터마이징 하고 싶을 때 사용.
(그림 그릴 때 마지막으로 `사용자에게 기회를 주는 것.`)
- 시스템 리소스는 최소화하면서 사용자에게 원하는 기능을 줄 수 있다.
- 구현은 함수포인터에 자신의 함수 로직을 짜서 적용할 수 있음. 없으면 NULL
#### 속성값 설정
- `OwnerDraw` : 사용자 정의 속서 값 부여, fixed(일괄적용) CF. variable(개별적용)
- `HasString` : true -> 리스트 박스가 문자열을 갖고 있도록 한다.
- `Multicolumn` : 리스트 박스에서 한 줄에 하나씩이 아닌 여러개를 보여줌
  - (horizantal : true)

![1](/assets/1.JPG)
`cf) Focus` : 입력가능한 상태로 맞춤

- 프로젝트 마법사에서 `WM_DRAW_ITEM`, `WM_MEASERITEM` 메시지 추가
 `WM_DRAW_ITEM` : 해당 메시지는 ownerDraw 속성을 체크한 아이템의 색 속성을 처리.
 `WM_MEASERITEM`: 컨트롤의 사이즈 크기를 사용자가 조절하도록 지원


### OnDrawItem(WM_DRAW_ITEM)
- 아이템에 사용자 속성 설정 처리해줄 수 있는 함수
- `클래스 위자드`->`WM_DRAW_ITEM`

`(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)`
- nIDCtl = 아이템 id값(모든 아이템들이 해당 함수를 통해 처리되므로 id를 통해 구분)
- LP = long pointer, DRAWITEMSTRUCT

DRAWITEMSTRUCT의 중요한 것은 hDC, rcItem

![2](/assets/2.JPG)

- 활용 코드
```
CDC *p_DC = CDC::FromHandle(lpDS->hDC);//핸들을 쓸 수 있는 임시객체를 얻어옴.
CRect r(lpDS->rcItem);                 //r 값에 해당 아이디 rect를 얻어옴.
p_DC->FillSolidRect(r, RGB(255, 0, 255));//분홍색으로 색칠
```      

### OnMeasureItem(WM_MEASERITEM)
- 아이템의 크기를 조절 할 수 있는 함수

![5](/assets/5.JPG)

----------------------
### TipWnd 생성 실습(child)
1. `MFC 클래스 추가`-> `CWnd 상속 선택`

 ![3](/assets/3_iaawum6h9.JPG)

   - DECLARE_DYNAMIC : 런타임클래스 자동 추가
     - 런타임클래스 : 디버깅 중간에 다형성으로 상속받은 클래스를 확인하기 위해 이름을 부여하는 것.
     - IMPLEMENT_DYNAMIC 에 함수 정의가 있기 때문에, cpp에서 쌍으로 지워야함

2. 메인 함수에서 사용하기 위해 `picture box`를 새로 추가. picture box 위에 포팅
    - visible속성을 `false`로

3.  main.dlg의 initdialog()에 아래 코드 삽입

![4](/assets/4.JPG)

해당 코드를 통해 picture box의 위치값을 받아 생성한 **child Wnd의 좌표계산 없이 해당 위치 설정**

-----------
#### MFC HANDLE 배경지식 정리
- CDC : DC 클래스 , HDC 변수를  m_hDC 멤버변수 형태로 갖고 있음
-  대표적인 wrapper 클래스
	wrapper 함수는 DC attach와 detach 제공.

   `attach` : 핸들을 얻음 >> 객체에 접근 & 실행 가능
   `dettach` :  DC 핸들 반환 >> 알아서 파괴(class상의 암시적 destrucotr 호출로)
- attac/dettach 빠른 제공 API : `FromHandle(HDC hdc)`
  - 핸들을 쓸 수 있는 임시객체를 얻어옴.
  - `임시객체`는 멀티쓰레드 환경에서 정리되기 때문에 사용에 유의


#### virtual 함수 정리
- 다형성에서 쓰이는 키워드
- virtual 키워드가 적혀있으면 `virtual table`상에 적힘.
- 컴파일러가 virtual table을 확인하여 상속관계를 역추적하여 어떤 함수를 호출할지 결정
-  생성자에 virtual이 붙지 않는 것은 생성당시에 명시적으로 호출하기 때문
    - ##### 생성자에 virtual이 붙지 않는 이유
      B가 A를 상속 받은 상황, test()가 virtual
      ```
       A *p = new B(); //<-명시적으로 생성자를 호출
       p->test();     //A 객체 포인터라도 virtual table을 보고 B의 test()호출
      ```


####
WndProc ->(호출) WM_COMMAND-> (실행) OnCommand

D2D는 서버에서 실행하는 기법이 아님.


## 창을 라운드하게
```
CRgn wnd_rgn; //region 디스플레이 + 영역 판단. 하지만 64k이상 영역 처리 힘듬
POINT pos[360];
	//sin은 라디안을 쓰므로 변환 필요
	double radian;
	for (int i = 0; i < 360; i++) {
		radian = i*3.141592 / 180;
		pos[i].x = sin(radian)*100+100;	//xy좌표에 sin, cos 대응은 시계방향이냐 반시계냐의 문제
		pos[i].y = cos(radian)*100+100;	//*100은 원 scale, +100 중심좌표
	}

	wnd_rgn.CreatePolygonRgn(pos, 360, ALTERNATE);//점 단위로 다각형을 그림.
	SetWindowRgn((HRGN)wnd_rgn, TRUE);
	wnd_rgn.DeleteObject();

  ```
  ![1](http://i.imgur.com/1MGyInH.jpg)

## 투명화 예제
http://www.tipssoft.com/bulletin/board.php?bo_table=update&wr_id=48


## 테두리에 라운드 옵션
```
CRect r;
	GetWindowRect(r);
	wnd_rgn.CreateRoundRectRgn(r.left, r.top, r.right, r.bottom, 30, 30);//반지름이 5인 원을 만들겠다.
```
