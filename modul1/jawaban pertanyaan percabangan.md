### 1. Kapan program masuk ke blok `if`?
Program akan masuk ke blok `if` ketika nilai variabel `timeDelay` sudah mencapai **100 atau kurang dari 100** (`<= 100`). Kondisi ini menandakan bahwa kecepatan kedipan LED sudah berada pada titik paling cepat dalam siklus.

---

### 2. Kapan program masuk ke blok `else`?
Program masuk ke blok `else` selama nilai `timeDelay` masih **lebih besar dari 100**. Pada kondisi ini, program akan terus mengurangi nilai delay secara bertahap sehingga LED berkedip semakin cepat pada setiap perulangan.

---

### 3. Apa fungsi dari perintah `delay(timeDelay)`?
Perintah `delay(timeDelay)` digunakan untuk **memberikan jeda waktu pada program** sesuai nilai yang ada di variabel `timeDelay` (dalam milidetik).

Penjelasannya:
- Saat LED **menyala (HIGH)** → delay mengatur lamanya LED tetap menyala
- Saat LED **mati (LOW)** → delay mengatur lamanya LED tetap mati

Sehingga, nilai `timeDelay` secara langsung mempengaruhi **kecepatan kedipan LED**.

---

### 4. Dokumentasi Program (Penjelasan Kode)

```markdown
# Dokumentasi Program LED: Percepatan Kedipan dengan Reset

Program ini mengatur LED pada pin 12 Arduino agar berkedip dari kondisi lambat, kemudian semakin cepat secara bertahap. Setelah mencapai batas tercepat, LED akan berhenti sejenak, lalu kembali ke kondisi awal (lambat) dan mengulang siklus.

## Penjelasan Kode Baris per Baris

- `const int ledPin = 12;`
  Mendeklarasikan pin digital 12 sebagai tempat LED terhubung.

- `int timeDelay = 1000;`
  Variabel untuk menyimpan waktu jeda (delay) dalam milidetik. Nilai awal 1000 ms (1 detik) menandakan kedipan awal lambat.

- `void setup() {`
  Fungsi yang dijalankan sekali saat Arduino pertama kali dinyalakan.

- `pinMode(ledPin, OUTPUT);`
  Mengatur pin 12 sebagai output agar dapat mengontrol LED.

- `}`
  Penutup fungsi setup.

- `void loop() {`
  Fungsi utama yang akan terus berulang selama Arduino aktif.

- `digitalWrite(ledPin, HIGH);`
  Menghidupkan LED.

- `delay(timeDelay);`
  Menahan LED dalam kondisi menyala selama `timeDelay`.

- `digitalWrite(ledPin, LOW);`
  Mematikan LED.

- `delay(timeDelay);`
  Menahan LED dalam kondisi mati selama `timeDelay`.

- `if (timeDelay <= 100) {`
  Mengecek apakah delay sudah mencapai batas tercepat (100 ms atau kurang).

- `delay(3000);`
  Memberikan jeda selama 3 detik sebelum memulai ulang siklus.

- `timeDelay = 1000;`
  Mengembalikan nilai delay ke kondisi awal (lambat).

- `} else {`
  Jika delay belum mencapai batas tercepat.

- `timeDelay -= 100;`
  Mengurangi nilai delay sebesar 100 ms agar kedipan LED menjadi lebih cepat pada siklus berikutnya.

- `}`
  Penutup kondisi if-else.

- `}`
  Penutup fungsi loop.

## Kesimpulan Alur Program

1. LED mulai berkedip dengan lambat (delay 1000 ms)
2. Setiap siklus, delay berkurang 100 ms → LED makin cepat
3. Saat mencapai 100 ms → LED berada pada kecepatan maksimum
4. Program berhenti sejenak selama 3 detik
5. Delay di-reset ke 1000 ms → siklus diulang dari awal