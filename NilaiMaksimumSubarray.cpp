/*
Nama      : Ahmad Bustanul Aziz
NIM       : 24060118120022
Matkul    : Analisis dan Strategi Algoritma
Tanggal   : 29 September 2021
Deskripsi : Jumlah Elemen Maksimum Subarray dengan Pendekatan Devide and Conquer
*/

#include <iostream>
#include <limits.h>

using namespace std;

int maximal(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

int Maximum_Subarray(int A[], int low, int high) {
    //Kamus Lokal
    int mid, sum, left_max, right_max, max_left_right;

    //Apabila array hanya memiliki 1 elemen
    if (high == low) {
        return A[low];
    }

    //Menentukan nilai tengah
    mid = (low + high) / 2;

    //Menemukan maximum subarray untuk subarray kiri
    left_max = INT_MIN;
    sum = 0;
    for (int i = mid; i>=low; i--) {
        sum += A[i];
        if (sum > left_max) {
            left_max = sum;
        }
    }

    //Menemukan maximum subarray untuk subarray kanan
    right_max = INT_MIN;
    sum = 0;
    for (int i = mid+1; i<=high; i++) {
        sum += A[i];
        if (sum > right_max) {
            right_max = sum;
        }
    }

    max_left_right = maximal(Maximum_Subarray(A, low, mid), Maximum_Subarray(A, mid+1, high));

    //Max Crossing Sum
    //printf("left: %d; right: %d; max_left_right: %d; max_cross: %d \n", left_max, right_max, max_left_right, maximal(max_left_right, left_max+right_max));
    return maximal(max_left_right, left_max+right_max);
}

int main(void) {
    //Kamus Global
    int N, Array[100];

    cin >> N;

    for (int i=0;i<N;i++) {
        cin >> Array[i];
    }

    cout << Maximum_Subarray(Array, 0, N-1);
}
