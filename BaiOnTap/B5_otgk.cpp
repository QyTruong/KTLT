#include<iostream>
#include<math.h>
using namespace std;


int used[100];
string ten[7] = {"Truong","Tung","Hung","Quan","Viet", "Toan"};
string maytinh[6] = {"MT1","MT2","MT3","MT4","MT5", "MT6"};

void nhap(int a[], int& n);
long giaithua(int n);
double tong_S1(int n, int x);
double tong_S2(int n, double tong);
long fibo(int n);
int dem_Le(int a[], int n, int cnt);
int dem_Chan(int a[], int n, int cnt);
int dem_Am(int a[], int n, int cnt);
int dem_Duong(int a[], int n, int cnt);
void sort_Tangdan(int a[], int n);
void xuat_cho_ngoi(int a[], int n);
void xuat_hoanvi(int a[], int n);
void sinh_hoanvi(int i, int a[], int n, int k, void func(int a[], int k));
void xuat(int a[], int n);

int main(){
    int so_hang,x; 
    cout << "Hay nhap so hang ban can tim: ";
    cin >> so_hang;
    cout << "Hay nhap x: "; cin >> x;
    cout << "Tong S1: 1 + 2!/x^2 + 3!/x^3 + 4!/x^4 + ... + n!/x^n: " << tong_S1(so_hang,x)<< endl;
    cout << "Tong S2: sqrt(n+sqrt(n-1+sqrt(n-2+sqrt(n-3+...+sqrt(1))))): " << tong_S2(so_hang,0) << endl;
    printf("So hang thu %d cua day Fibonacci: %d\n",so_hang,fibo(so_hang));
    int a[100], soluong;
    nhap(a,soluong);
    cout << "So luong cac so le: " << dem_Le(a,soluong,0) << endl;
    cout << "So luong cac so chan: " << dem_Chan(a,soluong,0) << endl;
    cout << "So luong cac so am: " << dem_Am(a,soluong,0) << endl;
    cout << "So luong cac so duong: " << dem_Duong(a,soluong,0) << endl;
    int A[100], n, k;
    cout << "Nhap n: "; cin >> n;
    cout << "Nhap k: "; cin >> k;
    cout << "\tXuat cac hoan vi:\n";
    // sinh_hoanvi(1,A,n, n, xuat_hoanvi);
    // cout << "\tXuat cac cho ngoi\n";
    sinh_hoanvi(1,A,n, k, xuat_cho_ngoi);
    return 0;
}

void nhap(int a[], int& n){
    do {
        cout << "Nhap so luong phan tu: ";
        cin >> n;
        if (n <= 0)
            cout << "Vui long nhap lai!!\n";
    } while (n <= 0);

    printf("\tHay nhap %d phan tu cho mang:\n", n);
    for (int i = 0; i < n; i++){
        printf("a[%d]: ", i+1);
        cin >> a[i];
    }
}

void xuat(int a[], int n){
    printf("\tDanh sach %d phan tu trong mang: \n", n);
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

long giaithua(int n){
    if (n == 0)
        return 1;
    return giaithua(n-1)*n;
}

// Hàm tính S(x,n) = 1 + 2!/x^2 + 3!/x^3 + 4!/x^4 + ... + n!/x^n
// Đây là dạng đệ quy tuyển tính !!
double tong_S1(int n, int x){
    if (n == 1)
        return 1;
    if (x == 0) 
        return 0;
    return tong_S1(n-1,x) + giaithua(n)/pow(x,n);
}

// Hàm tính S(n) = sqrt(n+sqrt(n-1+sqrt(n-2+sqrt(n-3+...+sqrt(1)))))
double tong_S2(int n, double tong = 0){
    if (n == 1)
        return tong;
    return tong_S2(n-1, tong + sqrt(n+sqrt(n+1-n)));
}

// Hàm đệ quy tính số hạng thứ n của dãy Fibonacci
long fibo(int n){
    if (n == 0 || n == 1)
        return 1;
    return fibo(n-1) + fibo(n-2);
}

// Đếm số lượng các số là số lẻ trong mảng.
int dem_Le(int a[], int n, int cnt=0){
    if (n == 0)
        return cnt;
    else {
        if (a[n-1] % 2 != 0)
            return dem_Le(a,n-1, cnt+1);
        else
            return dem_Le(a,n-1, cnt);
    }
}   

// Đếm số lượng các số là số chẵn trong mảng.
int dem_Chan(int a[], int n, int cnt=0){
    if (n == 0)
        return cnt;
    else {
        if (a[n-1] % 2 == 0)
            return dem_Chan(a,n-1, cnt+1);
        else
            return dem_Chan(a,n-1, cnt);
    }
}

// Đếm số lượng các số là số âm trong mảng.
int dem_Am(int a[], int n, int cnt=0){
    if (n == 0)
        return cnt;
    else {
        if (a[n-1] < 0)
            return dem_Am(a,n-1, cnt+1);
        else
            return dem_Am(a,n-1, cnt);
    }
}

// // Đếm số lượng các số là số dương trong mảng.
int dem_Duong(int a[], int n, int cnt=0){
    if (n == 0)
        return cnt;
    else {
        if (a[n-1] > 0)
            return dem_Duong(a,n-1, cnt+1);
        else
            return dem_Duong(a,n-1, cnt);
    }
}

void swap(int &a, int &b){
    int c = a;
    a = b;
    b = c;
}

// hH đệ quy sắp xếp mảng tăng dần.
void sort_Tangdan(int a[], int n){
    if (n == 1) 
        return;
    sort_Tangdan(a,n-1);
    if (a[n-2] > a[n-1]){
        swap(a[n-2],a[n-1]);
        sort_Tangdan(a,n-1);
    }
}

// Xuất tất cả hoán vị
void xuat_hoanvi(int a[], int n){
    for (int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

// Xuất các chỗ ngồi n chập k
void xuat_cho_ngoi(int a[], int n){
    for (int i = 1; i <= n; i++){
        cout << maytinh[i-1] << " - ";
        cout << ten[a[i]-1] << "\t";
    }
    cout << endl;
}


// Hàm dùng để giải quyết 2 câu cuối cùng của bài
void sinh_hoanvi(int i, int a[], int n, int k, void func(int a[], int k)){
    for (int j = 1; j <= n; j++){
        if (used[j] == 0){
            a[i] = j;
            used[j] = 1;
            if (i == k)
                func(a,k);
            else
                sinh_hoanvi(i+1,a,n,k,func);
            used[j] = 0;
        }
    } 
}













