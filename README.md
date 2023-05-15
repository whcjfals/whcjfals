# IoT 스마트홈 
적외선 센서와 wifi 모듈(또는 블루투스)을 이용하여 IoT 리모컨을 만들기

> 마크다운 쓰는 방법
> https://codesik.github.io/How-To-Use-MarkDown/
{.is-info}


## 필요 부품
- [x] 적외선 LED [icbanq](https://www.icbanq.com/P007628142)
- [x] 적외선 수신 모듈 [icbanq](https://www.icbanq.com/P009910109)
- [x] 오렌지보드 wifi [설명](https://www.kocoafab.cc/product/orangewifiplus) [구매](https://smartstore.naver.com/kocoafab/products/5878725897)
- [x] 트랜지스터 TR BC547 1개
- [x] 기타 저항, 빵판 등
- [x] 서보 모터 

## 필요한 지식
- [ ] wifi 통신
- [ ] 앱 개발
- [ ] 리모컨의 키코드 알아내기

## 작동 구조 도식화
```kroki
d2

direction: right

OrangeBoard: {
	wifi module -> compute -> IR module
 }

스마트폰 -> OrangeBoard.wifi module: 2.4ghz 통신
OrangeBoard.IR module -> TV: 적외선 통신
OrangeBoard.IR module -> 에어컨: 적외선 통신
OrangeBoard.IR module -> "기타등등...": 적외선 통신
OrangeBoard.compute -> motor: 직접 연결
motor -> switch
```

## 참조 링크
- https://blog.naver.com/PostView.nhn?blogId=kimgooni&logNo=221730957657



