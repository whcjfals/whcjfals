# 설치 가이드
## 라이브러리 설치
- PubSubClient: 최신버전
- IRremoteESP8266: 2.7.13버전
## 시리얼 포트 드라이버 설치
[설치 링크](http://www.wch-ic.com/downloads/CH341SER_EXE.html)
## IDE 설정
1. `파일 - 환경설정 - <추가적인 보드 매니저 URLs>` 에 다음 주소 붙여넣기:
```
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```
2. `보드 매니저 -> "ESP8266" 검색 -> 2.3버전 설치`
3. 보드선택 `WEMOS D1 R2 & MINI" -> "WEMOS D1 R2 & MINI`
4. 설정 변경 `upload speed: 115200`
