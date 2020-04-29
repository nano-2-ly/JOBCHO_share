# JOBCHO_share

## QUICK START
### 1. 펌웨어 수정
~~~
./insole/insole.ino/
~~~
이 위치에 있는 파일을 열어줍니다.</br>

~~~
//int insole_type = 0; //left insole
int insole_type = 1; //right insole
~~~
파일의 1~2 라인에 있는 코드를 수정합니다.</br>

오른쪽 인솔인 경우</br>
~~~
//int insole_type = 0; //left insole
int insole_type = 1; //right insole
~~~
코드를 위와 같이 수정합니다.</br>

왼쪽 인솔인 경우 </br>
~~~
int insole_type = 0; //left insole
//int insole_type = 1; //right insole
~~~
코드를 위와 같이 수정합니다.</br>


### 2. 펌웨어 업로드</br>
장치와 컴퓨터를 연결하여 수정된 펌웨어를 업로드합니다.</br>


### 3. 블루투스 연결</br>
블루투스 터미널을 이용하여 블루투스 장치를 검색합니다.</br>

왼쪽 인솔의 경우 장치 이름은 아래와 같습니다.</br>
~~~
left insole
~~~

오른쪽 인솔의 경우 장치 이름은 아래와 같습니다.</br>
~~~
right insole
~~~



### 4. 데이터 수신</br>
펌웨어는 장치가 임의의 데이터를 수신한 뒤, 장치의 데이터를 송신하게 됩니다.</br>
따라서 블루투스 터미널을 통해 임의의 데이터를 장치에 송신하면 장치의 데이터를 수신받을 수 있습니다.</br>
