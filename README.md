# wallfollower
Dibuat untuk memenuhi tugas mata kuliah, namun juga open jika ada teman-teman lain yang membutuhkan. Implementasi Fuzzy Logic sederhana pada kendaran wall follower yang mengikuti dinding sebelah kanan. Proyek ini merupakan simulasi pada tinkercad.com.

Sensor Ping Parallax 2 pcs ditempatkan depan belakang.
Servo yang di couple pada kemudi.
Arduino Uno sebagai otak fuzzy logic-nya.
Motor DC untuk menggerakkan roda belakang.

Koneksi
1. Ping Parallax  Depan dikoneksikan dengan Pin D9.
2. Ping Parallax  Belakang dikoneksikan dengan Pin D10.
3. Servo dikoneksikan dengan Pin D6.

Rangkaian dapat dilihat pada:
[https://www.tinkercad.com/things/8SwJ9mOypC2-tubes-iot/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard](https://www.tinkercad.com/things/8SwJ9mOypC2-wall-follower-fuzzy-logic/editel)

Cara Kerja
1. Dinding berada di sebelah kanan robot.
2. Jika Robot dekat dinding, maka akan menjauh (belok kiri)
3. Jika Robot jauh dengan dinding, maka akan mendekat (belok kanan)
4. Sesimple itu!

RD
