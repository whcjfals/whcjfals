# IoT 스마트홈 
적외선 센서와 wifi 모듈(또는 블루투스)을 이용하여 IoT 리모컨을 만들기

## 설치 가이드
[링크](INSTALL.md)

## 기능 추가해야 될 것들
1. [ ] 에어컨
2. [ ] 전등 스위치 (서보모터)
3. [ ] 꺼져있는지 켜져있는지 조도센서로 확인하는 기능
  *집에 들어왔는데 밖에 온도가 27도 이상 -> 에어컨 on 나가면 off (적외선 송수신)*

모든 데이터는 mqtt서버를통해 전달하고 전달 받음

## 앱개발
안드로이드 앱에서 mqtt 클라이언트를 구현하려면
Eclipse Paho Android 라이브러리 사용

시간 없으면 그냥 mqttDash사용


## 현재까지 구현된 것
Tv원격 제어 기능


## 앞으로 남은 구현 프로세스
1. [ ] 에어컨, 전등 스위치 On/Off
2. [ ] 현재 상태 확인 기능 
3. [ ] if(외부온도 27도이상 && 집에 들어옴) 에어컨 On else if(나감) 에어컨 off 
4. [ ] mqttDash를 대체해서 안드로이드 앱을 개발 (시간 여유가 있다면)

## 기숙사 휴게실tv 키코드
전원
```
20DF10EF
CA0F1F87
5B0310EF
C181890F
```

셋톱전원
```
5B0310EF
5B03D52A
```

1번
```
5B038877
```

2번
```
5B0348B7
```

## 참조 링크
- https://diy-dev-design.tistory.com/65
- https://blog.naver.com/PostView.nhn?blogId=kimgooni&logNo=221730957657
- https://juahnpop.tistory.com/66

