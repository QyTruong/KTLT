#include<iostream>

using namespace std;

void inp(int a[], int& n){
    do {
        printf("Nhap so luong phan tu: "); 
        scanf("%d", &n);
        if (n <= 0)
            printf("Nhap lai!!\n");
    } while (n <= 0);

    for (int i = 0; i < n; i++){
        printf("Gia tri a[%d]: ", i+1);
        scanf("%d", &a[i]);
    }
}

long tong_arr(int a[], int n){
    if (n == 0)
        return a[0];
    return tong_arr(a, n-1) + a[n]; 
}

int main(){
    int a[100], n;
      
    inp(a,n);
    printf("Tong cac gia tri trong mang: %d", tong_arr(a,n));

    return 0;
}