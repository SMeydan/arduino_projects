const int buton = 6; /* Butonun bağlı olduğu pin */
int sayac = 0; /* butona basılma sayısını tutacak değişken */
int butonDurumu = 0; /* Butonun durumu */  

void setup() {
 pinMode(buton, INPUT);
 Serial.begin(9600);
}

void loop() {
 butonDurumu = digitalRead(buton);
 if (butonDurumu == HIGH) {
   delay(10); /* dalgalanmalar için biraz bekleyelim */
   sayac ++; /* sayaç = sayaç + 1 yani sayaç değeri bir arttırıldı */
   Serial.print("Butona ");
   Serial.print(sayac);/* sayaç değerimizi ekrana yazdırıyoruz */
   Serial.println(". defa basildi.");
   while(butonDurumu == HIGH){ /* Butona basili olduğu surece bekle */
     butonDurumu = digitalRead(buton); /* Butonun durumunu kontrol et */
   }
   delay(10); /* dalgalanmalar için biraz bekleyelim */
 }
}
