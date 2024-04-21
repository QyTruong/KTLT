#include<iostream>

using namespace std;

void k_tao(int a[], int n){
    for (int i = 0; i < n; i++){
        a[i] = 0;
    }
}

void nhap(int arr[], int& n){
    do {
        cout << "Hay nhap so bac cua phuong trinh: ";
        cin >> n;
        if (n <= 0)
            cout << "Vui long nhap lai!\n";
    } while (n <= 0);

    for (int i = 0; i <= n; i++){
        printf("He so thu cua x^%d: ", i);
        cin >> arr[i];
    }
}

void tong_dt(int dt1[], int lt1, int dt2[], int lt2, int dt_kq[], int &lt_kq){
    lt_kq = (lt1 >= lt2) ? lt1 : lt2;
    for (int i = 0; i <= lt_kq; i++){
        dt_kq[i] = dt1[i] + dt2[i];
    } 
}

void tich_dt(int dt1[], int lt1, int dt2[], int lt2, int dt_kq[], int &lt_kq){
    lt_kq = lt1 + lt2;
    int cnt = 0;
    for (int i = 0; i < lt1; i++){
        for (int j = 0; j < lt2; j++){
            dt_kq[cnt] += dt1[i] * dt2[j];
        }
        cnt++;
    }
}

void xuat(int a[], int n){
    cout << "S = ";
    for (int i = n; i >= 0; i--){
        printf("%dx^%d",a[i],i);
        if (i > 0){
            cout << " + ";
        }
    }
}

int main(){
    int n,m,k,q;
    int arr1[100];
    int arr2[100];
    int kq[100];
    int kq1[100];
    k_tao(arr1,100);
    k_tao(arr2,100);
    cout << "\tDa thuc thu 1:\n";
    nhap(arr1,n);
    cout << "\tDa thuc thu 2:\n";
    nhap(arr2,m);
    tong_dt(arr1,n,arr2,m,kq,k);
    cout << "\tTong 2 da thuc:\n";
    xuat(kq,k);
    cout << endl;
    tich_dt(arr1,n,arr2,m,kq1,q);
    cout << "\tTich 2 da thuc:\n";
    xuat(kq1,q);
    
    return 0;
}