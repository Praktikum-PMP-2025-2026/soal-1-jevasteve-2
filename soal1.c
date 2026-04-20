/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
*   Modul               : 2
*   Hari dan Tanggal    : Senin, 20 April 2026
*   Nama (NIM)          : Jeva Steve Sinaga (13224002)
*   Nama File           : soal1.c
*   Deskripsi           :   1. Nilai hilang ditandai -1
                            2. Untuk tiap -1:
                                • cari tetangga valid terdekat di kiri dan kanan
                                • jika dua-duanya ada, ganti dengan floor((kiri+kanan)/2)
                                • jika hanya kiri ada, pakai kiri
                                • jika hanya kanan ada, pakai kanan
                                • jika tidak ada keduanya, ganti 0
                            3. Setelah semua elemen dipulihkan, hitung jumlah maksimum dari semua subarray kontigu nonkosong.
 */

 #include <stdio.h>
 #include <math.h>

 int main (){
    int n;
    int x = 0;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0 ; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for (int i =0; i < n ; i++){
        if (arr[i] == -1) {
            int kiri = -1, kanan = -1;
            for (int j = i - 1; j >= 0 ; j--){
                if (arr[j] != -1) {
                    kiri = arr[j];
                    break;
                }
            }
            for (int j = i ; j < n; j++){
                if (arr[j] != -1) {
                    kanan = arr[j];
                    break;
                }
            }
            if (kiri != -1 && kanan != -1) {
                arr[i] = (int)floor((kiri + kanan) / 2.0);
            }
            else if (kiri != -1) {
                arr[i] = kiri;
            }
            else if (kanan != -1) {
                arr[i] = kanan;
            }
            else {
                arr[i] = 0;
            }
        }
    }
    printf("RECOVERED");
    for (int i = 0 ; i < n ; i++) {
        printf(" %d", arr[i]);
        x += arr[i];
    }
    printf("\nMAX_SUM %d", x);
    return 0;
 }
