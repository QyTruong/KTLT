#include<iostream>
#include<cmath>
#define MAX_SIZE 50
using namespace std;
int used[50] = {0};
int cnt = 0;

void nhap_r_c(int& r, int& c);
void nhap(int **a, int r, int c);
long tong(int **a, int row, int col);
bool isPrime(int n);
void xuat_snt(int **a, int row, int col);
int* so_le_first(int **a, int row, int col);
int* luu_cot(int **a, int row, int col, int so_cot);
int* luu_dong(int **a, int row, int col, int so_dong);
int* luu_cot_sochan(int **a, int row, int col, int so_cot);
int* luu_cot_giam1(int **a, int row, int col, int so_cot);
void xuat_arr_1D(int *a, int n);
void xuat(int **a, int r, int c);

int main(){
    int r, c;
    nhap_r_c(r,c);
    int **a = new int *[r];
    for (int i = 0; i < r; i++){
        a[i] = new int [c];
    }
    nhap(a,r,c);
    xuat(a,r,c);
    xuat_snt(a,r,c);
    cout << endl;
    if (so_le_first(a,r,c) != NULL){
        cout << "So le dau tien la: " << *so_le_first(a,r,c) << endl;
    }
    else cout << "Khong co so le trong mang!!\n";
    int vt_cot, vt_dong;
    cout << "Hay nhap vi tri cot ma ban muon: "; cin >> vt_cot;
    cout << "Hay nhap vi tri dong ma ban muon: "; cin >> vt_dong;
    int *c1 = luu_cot(a,r,c,vt_cot);
    int *d = luu_dong(a,r,c,vt_dong);
    int *c2 = luu_cot_sochan(a,r,c,vt_cot);
    int *c3 = luu_cot_giam1(a,r,c,vt_cot);
    cout << "Cac phan tu cua cot ban vua chon: ";
    xuat_arr_1D(c1,c);
    cout << "Cac phan tu cua dong ban vua chon: ";
    xuat_arr_1D(d,r);
    cout << "Cac phan tu so chan cua cot ban vua chon: ";
    xuat_arr_1D(c2,c);
    cout << "Cac phan tu giam di 1 cua cot ban vua chon: ";
    xuat_arr_1D(c3,c);

    for (int i = 0; i < r; i++){
        delete []a[i];
    }
    //delete []c1;
    delete []a;
    a = nullptr;
    return 0;
}

// Nhập giá trị cho mảng số nguyên r dòng c cột
void nhap_r_c(int& row, int& col){
    do {
        cout << "Hay nhap dong: "; cin >> row;
        cout << "Hay nhap cot: "; cin >> col;
        if (row <= 0 || row > MAX_SIZE || col <= 0 || col > MAX_SIZE)
            cout << "Vui long nhap lai!\n";
    } while (row <= 0 || row > MAX_SIZE || col <= 0 || col > MAX_SIZE);
}

void nhap(int **a, int row, int col){
    printf("Hay nhap cac phan tu cho %d dong va %d cot:\n",row,col);
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("a[%d][%d]: ",i+1,j+1);
            cin >> a[i][j];
        }
    }
}

// Xuất giá trị cho mảng số nguyên r dòng c cột. 
void xuat(int **a, int row, int col){
    printf("\tDanh sach cac phan tu trong mang:\n");
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void xuat_arr_1D(int *a, int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

// Tính tổng các giá trị trong mảng số nguyên r dòng c cột bằng tên con trỏ và ký pháp độ dời.
long tong(int **a, int row, int col){
    long sum = 0;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            sum += *(*(a+i)+j);
        }
    }
    return sum;
}

bool isPrime(int n){
    if (n < 2)
        return false;
    for (int i = 2; i*i <= n; i++){
        if (n % i == 0)
            return false;
    }
    return true;
}

// Xuất các giá trị số nguyên tố trong mảng số nguyên r dòng c cột bằng tên con trỏ và ký pháp độ dời.
void xuat_snt(int **a, int row, int col){
    cout << "\tDanh sach cac so nguyen to mang: ";
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (isPrime(*(*(a+i)+j)))
                cout << *(*(a+i)+j) << " ";
        }
    }
}

// Trả về địa chỉ phần tử lẻ đầu tiên trong mảng r dòng c cột. Nếu không có trả về NULL.
int* so_le_first(int **a, int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (a[i][j] % 2 != 0)
                return &a[i][j];
        }
    }
    return nullptr;
}

// Nhập vào số cột, trả về con trỏ mảng lưu tất cả các phần tử trên cột đã nhập.
int* luu_cot(int **a, int row, int col, int so_cot){
    int* c = new int [row];
    for (int i = 0; i < row; i++){
        c[i] = a[i][so_cot];
    }
    return c;
}

// Nhập vào số dòng, trả về con trỏ mảng lưu tất cả các phần tử trên dòng đã nhập.
int* luu_dong(int **a, int row, int col, int so_dong){
    int* d = new int [col];
    for (int i = 0; i < col; i++){
        d[i] = a[so_dong][i];
    }
    return d;
}

// Nhập vào số cột, trả về con trỏ mảng lưu tất cả các phần tử là số chẵn trên cột đã nhập, nếu không có phần tử nào là số chẵn thì trả về NULL.
int* luu_cot_sochan(int **a, int row, int col, int so_cot){
    int* c = new int [row];
    for (int i = 0; i < row; i++){
        if (a[i][so_cot] % 2 == 0){
            c[i] = a[i][so_cot];
            cnt++;
        }
    }
    return c;
    if (!cnt) return nullptr;
}

//  Nhập vào số cột, trả về con trỏ mảng lưu tất cả các phần tử trên cột đã nhập với yêu cầu giá trị của mỗi phần tử giảm đi 1.
int* luu_cot_giam1(int **a, int row, int col, int so_cot){
    int* c = new int [row];
    for (int i = 0; i < row; i++){
        c[i] = a[i][so_cot]-1;
    }
    return c;
}