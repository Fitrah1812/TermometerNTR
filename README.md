# TermometerNTR

Saya membuat termometer sebuah termometer sederhana yaitu berfungsi untuk mendeteksi suhu tubu. Kenapa saya membuat ini ? karena saya sangat resah dengan penggunaan termometer manual yang hanya kita bisa lihat presisi hanya 5 baris 
![Termometer](https://user-images.githubusercontent.com/56785130/112773504-7fc7e900-9060-11eb-9d35-8b3a335157da.png)

Ini membuat kesulitan untuk menentukan dengan digit-digit yang kecil seperti misalnya suhu 36.7 celsius. Alat ini bisa membantu mendeteksi untuk 2 digit dibelakang koma sehingga lebih akurat karena menggunakan 2 decimal dibelakang koma. Alat ini berguna untuk mengecek suhu tubuh dengan penggunaan alat sederhana dan lebih akurat dari yang manual. Berfungsi untuk mendeteksi suhu orang-orang yang terdampat COVID-19 ataupun untuk mendeteksi kondisi demam seseorang. Hal ini sangat bermanfaat untuk kehidupan yang keberlanjutan dikarenakan cek suhu tubuh untuk mendeteksi apakah tubuh sedang dalam keadaan prima atau tidak.
![termometer](https://github.com/Fitrah1812/TermometerNTR/blob/main/Dokumentasi/Penugasan_Camin_NCC.png)
Penjelasan Source code

1. Tahap Insiasi
``` c
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
float value;
int baselineTemp = 0;
int celsius = 0;
int fahrenheit = 0;
```
Penjelesan source code diatas -> Inisiasi ini berfungsi untuk penggunaan variabel nantinya yang akan digunakan diprogram. disini menggunakan library LiquidCrystal.h karena disini saya menggunakan LCD 16x2 untuk menampilkan suhu yang terdeteksi. Setelah itu saya letakkan pin-pin di LiquidCrystal lcd(12,11,5,4,3,2). Float Value untuk menyimpan value yang didapat dari pmeberian suhu nantinya. int baselineTemp adalah batas suhu yang ditetapkan yaitu 40 derajat yang saya letakkan meninjau dari suhu badan penderita covid-19 yang bisa mencapai batas atas tersebut atau melebihinya. Setelah itu ada variavel celsius dan fahrenheit untuk dikeluarkan nilainya di serial monitor.

2. Tahap pembuatan setup(untuk menghubungi arduino dan sistem kerja)
``` c
void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}
```
Penjelasan source code diatas -> Berikut merupakan pemasangan pinMode 

3. Tahap perulangan proses
``` c
void loop()
{
  baselineTemp = 40;
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  fahrenheit = ((celsius * 9) / 5 + 32);
  Serial.print(celsius);
  Serial.print(" C, ");
  Serial.print(fahrenheit);
  Serial.println(" F");
  value = analogRead(tmp)*0.004882814;
  value = (value - 0.5) * 100.0;
  if (celsius < baselineTemp && celsius > 27) {
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
  }
  else if (celsius >= baselineTemp) {
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
  }
  lcd.setCursor(0,1);
  lcd.print("Tmp:");
  lcd.print(value);
  delay(1000);
  lcd.clear();
}
```
Penjelasan source code diatas -> Ini merupakan hasil loopingnya

