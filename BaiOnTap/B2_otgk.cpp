#include<iostream>

using namespace std;

void menu();
void init(int*& a, int n);
void free(int*& a, int n);
void nhap(int*& a, int& n);
void swap(int &a, int &b);
int check_scp(int n);
int check_sht(int n);
int isAm(int n);
int isDuong(int n);
int isPrime(int n);
int cnt_scp(int* a, int n);
int* find_first_scp(int* a, int n);
int* find_last_sht(int* a, int n);
int* find_first_min(int* a, int n);
int* find_last_min(int* a, int n);
void xoa(int*& a, int& n, int pos);
void sort_Giamdan(int* a, int start, int end);
void sort_Tangdan(int* a, int start,int end);
int* gopMang(int* a, int n, int* b, int m);
void sort_ChiaDoi(int* a, int n);
int* merge_sort(int*a , int n, int*b, int m);
void xuat(int* a, int n);


int main(){
    int n,x;
    int *p = NULL;
    int choice;
    menu();
    do {
        cout << "Hay nhap lua chon cua ban: ";
        cin >> choice; 
        switch (choice)
        {
        case 0: {
            cout << "Cam on ban vi da su dung chuong trinh!!\n";
            break;
        }
        case 1: {
            cout << "\tNHAP MANG\n";
            nhap(p,n);
            break;
        }
        case 2: {
            cout << "\tXUAT MANG\n";
            xuat(p,n);
            break;
        }
        case 3: {
            cout << "\tDEM SO LUONG PHAN TU LA SO CHINH PHUONG\n";
            printf("Co %d so chinh phuong trong mang!!\n",cnt_scp(p,n));
            break;
        }
        case 4: {
            cout << "\tKIEM TRA SO AM TRONG MANG\n";
            int cnt = 0;
            for (int i = 0; i < n; i++){
                if (isAm(p[i])) cnt++; 
            }
            if (cnt) printf("Co %d so am trong mang!!\n", cnt);
            else cout << "Khong co so am trong mang!!\n";
            break;
        }
        case 5: {
            cout << "\tKIEM TRA SO DUONG TRONG MANG\n";
            int cnt = 0;
            for (int i = 0; i < n; i++){
                if (isDuong(p[i])) cnt++; 
            }
            if (cnt) printf("Co %d so duong trong mang!!\n", cnt);
            else cout << "Khong co so duong trong mang!!\n";
            break;
        }
        case 6: {
            cout << "\tKIEM TRA SO NGUYEN TO TRONG MANG\n";
            int cnt = 0;
            for (int i = 0; i < n; i++){
                if (isPrime(p[i])) cnt++; 
            }
            if (cnt) printf("Co %d so nguyen to trong mang!!\n", cnt);
            else cout << "Khong co so nguyen to trong mang!!\n";
            break;
        }
        case 7: {
            cout << "\tTIM SO CHINH PHUONG DAU TIEN TRONG MANG\n";
            if (find_first_scp(p,n) == NULL) 
                cout << "Trong mang khong co so chinh phuong!!\n";
            else printf("So chinh phuong dau tien trong mang: %d\n", *find_first_scp(p,n));
            break;
        }
        case 8: {
            cout << "\tTIM SO HOAN THIEN CUOI CUNG TRONG MANG\n";
            if (find_first_scp(p,n) == NULL) 
                cout << "Trong mang khong co so hoan thien!!\n";
            else printf("So hoan thien cuoi cung trong mang: %d\n", *find_last_sht(p,n));
            break;
        }
        case 9: {
            cout << "\tTIM SO NHO NHAT DAU TIEN TRONG MANG\n";
            printf("So nho nhat dau tien trong mang: %d\n", *find_first_min(p,n));
            break;
        }
        case 10: {
            cout << "\tTIM SO NHO NHAT CUOI CUNG TRONG MANG\n";
            printf("So nho nhat cuoi cung trong mang: %d\n", *find_last_min(p,n));
            break;
        }
        case 11: {
            cout << "\tXOA 1 PHAN TU TRONG MANG TAI VI TRI BAT KY\n";
            if (p == NULL)
                cout << "Khong con phan tu de xoa!!\n";
            else {
                int x; cin >> x;
                xoa(p,n,x);
                cout << "Da xoa thanh cong!!\n";
            }            
            break;
        }
        case 12: {
            cout << "\tSAP XEP MANG GIAM DAN\n";
            sort_Giamdan(p,0,n);
            cout << "Da sap xep thanh cong!\n";
            break;
        }
        case 13: {
            cout << "\tSAP XEP MANG TANG DAN\n";
            sort_Tangdan(p,0,n);
            cout << "Da sap xep thanh cong!\n";
            break;
        }
        case 14: {
            cout << "\tSAP XEP NUA DAU MANG TANG VA NUA SAU GIAM DAN\n";
            sort_ChiaDoi(p,n);
            break;
        }
        case 15: {
            cout << "\tGOP 2 MANG\n";
            int n1, n2;
            int* a1 = NULL;
            int* a2 = NULL;
            cout << "Mang thu 1\n";
            nhap(a1,n1);
            cout << "Mang thu 2\n";
            nhap(a2,n2);
            int *tong = gopMang(a1,n1,a2,n2);
            cout << "Mang sau khi gop:\n";
            xuat(tong,n1+n2);
            break;
        }
        case 16: {
            cout << "\tGOP 2 MANG DA TANG DAN LAI THANH 1 MANG VA CUNG TANG DAN\n";
            int m1, m2;
            int* b1 = NULL;
            int* b2 = NULL;
            cout << "Mang thu 1\n";
            nhap(b1,m1);
            cout << "Mang thu 2\n";
            nhap(b2,m2);
            int *tong = merge_sort(b1,m1,b2,m2);
            cout << "Mang sau khi gop:\n";
            xuat(tong,m1+m2);
            break;
        }
        default:
            cout << "Du lieu dau vao khong hop le!\n";
            break;
        }
        
    } while (choice != 0);

    free(p,n);
    return 0;
}

void menu(){
    cout << "0.Thoat chuong trinh\n"
        << "1.NHAP MANG\n"
        << "2.XUAT MANG\n"
        << "3.DEM SO LUONG PHAN TU LA SO CHINH PHUONG\n"
        << "4.KIEM TRA SO AM TRONG MANG\n"
        << "5.KIEM TRA SO DUONG TRONG MANG\n"
        << "6.KIEM TRA SO NGUYEN TO TRONG MANG\n"
        << "7.TIM SO CHINH PHUONG DAU TIEN TRONG MANG\n"
        << "8.TIM SO HOAN THIEN CUOI CUNG TRONG MANG\n"
        << "9.TIM SO NHO NHAT DAU TIEN TRONG MANG\n"
        << "10.TIM SO NHO NHAT CUOI CUNG TRONG MANG\n"
        << "11.XOA 1 PHAN TU TRONG MANG TAI VI TRI BAT KY\n"
        << "12.SAP XEP MANG GIAM DAN\n"
        << "13.SAP XEP MANG TANG DAN\n"
        << "14.SAP XEP NUA DAU MANG TANG VA NUA SAU GIAM DAN\n"
        << "15.GOP 2 MANG\n"
        << "16.GOP 2 MANG DA TANG DAN LAI THANH 1 MANG VA CUNG TANG DAN\n";
}

void init(int*& a, int n){
    a = new int [n];
}

void free(int*& a, int n){
    delete []a;
    a = nullptr;
}

// Nhập giá trị cho 1 mảng 1 chiều lưu trữ các số nguyên.
void nhap(int*& a, int& n){
    do {
        cout << "Hay nhap so luong phan tu: ";
        cin >> n;
        if (n <= 0)
            cout << "Vui long nhap lai!\n";
    } while (n <= 0);

    init(a,n);
    if (a != NULL){
        printf("\tHay nhap %d cho danh sach mang sau day:\n", n);
        for (int i = 0; i < n; i++){
            printf("a[%d]: ", i+1);
            cin >> a[i];
        }
    }
}

// Xuất mảng 1 chiều lưu trữ các số nguyên.
void xuat(int* a, int n){
    cout << "\tDanh sach cac phan tu trong mang:\n";
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

int check_scp(int n){
    for (int i = 0; i < n; i++){
        if (i*i == n)
            return true;
    }
    return false;
}

// Kiểm tra mảng có số hoàn thiện hay không?
int check_sht(int n){
    int tong = 0;
    for (int i = 0; i < n; i++){
        if (n % i == 0)
            tong += i;
    }
    return tong == n;
}

// Kiểm tra mảng có số âm không?
int isAm(int n){
    return n < 0 ? true : false;
}

//  Kiểm tra mảng có số dương không?
int isDuong(int n){
    return !isAm(n);
}

// Kiểm tra mảng có số nguyên tố không?
int isPrime(int n){
    if (n < 2)
        return false;
    for (int i = 2; i*i <= n; i++){
        if (n % i == 0)
            return false;
    }
    return true;
}


// Đếm số lượng phần tử là số chính phương trong mảng
int cnt_scp(int* a, int n){
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (check_scp(a[i])) cnt++;
    }
    return cnt;
}

// Trả về địa chỉ số chính phương đầu tiên trong mảng. Nếu không có trả về NULL
int* find_first_scp(int* a, int n){
    if (a != NULL){
        for (int i = 0; i < n; i++){
            if (check_scp(a[i]))
                return &a[i];
        }
    }
    return nullptr;
}

// Trả về địa chỉ số hoàn thiện cuối cùng trong mảng. Nếu không có trả về NULL
int* find_last_sht(int* a, int n){
    if (a != NULL){
        for (int i = n-1; i >= 0; i--){
            if (check_sht(a[i]))
                return &a[i];
        }
    }
    return nullptr;
}

// Trả về địa chỉ số nhỏ nhất xuất hiện đầu tiên trong mảng.
int* find_first_min(int* a, int n){
    if (a != NULL){
        for (int i = 0; i < n; i++){
            if (a[i] < a[i+1])
                return &a[i];
        }
        return &a[n-1];
    }
    return nullptr;
}

// Trả về địa chỉ số nhỏ nhất xuất hiện cuối cùng trong mảng.
int* find_last_min(int* a, int n){
    if (a != NULL){
        for (int i = n-1; i >= 0; i--){
            if (a[i] < a[i-1])
                return &a[i];
        }
        return &a[0];
    }
    return nullptr;
}


// Xóa 1 phần tử ra khỏi mảng.
void xoa(int*& a, int& n, int pos){
    for (int i = pos+1; i < n; i++){
        a[i-1] = a[i];
    }
    n--;
    int *tmp = new int [n];
    for (int i = 0; i < n; i++){
        tmp[i] = a[i];
    }
    free(a,n);
    a = new int [n];
    for (int i = 0; i < n; i++){
        a[i] = tmp[i];
    }
    free(tmp,n);
}

// Sắp xếp mảng giảm dần.
void sort_Giamdan(int* a, int start, int end){
    for (int i = start; i < end-1; i++){
        for (int j = i+1; j < end; j++){
            if (a[i] < a[j])
                swap(a[i],a[j]);
        }
    }
}

// Sắp xếp mảng tăng dần.
void sort_Tangdan(int* a, int start,int end){
    for (int i = start; i < end-1; i++){
        for (int j = i+1; j < end; j++){
            if (a[i] > a[j])
                swap(a[i],a[j]);
        }
    }
}

// Sắp xếp nửa đầu mảng tăng dần, nửa sau giảm dần.
void sort_ChiaDoi(int* a, int n){
    int mid = n/2;
    sort_Tangdan(a,0,mid);
    sort_Giamdan(a,mid,n);
}

// Gộp 2 mảng.
int* gopMang(int* a, int n, int* b, int m){
    if (a != NULL && b != NULL){
        int *c;
        init(c,n+m);
        if (c != NULL){
            int cnt = 0;
            for (int i = 0; i < n; i++){
                c[cnt++] = a[i];
            }
            for (int i = 0; i < n; i++){
                c[cnt++] = b[i];
            }
        }
        return c;
    }
    return nullptr;
}

// Gộp 2 mảng đã tăng dần lại thành 1 mảng và cũng tăng dần.
// Thấy hơi giống merge sort nên đặt tên zậy cho nó đơn giản =)))
int* merge_sort(int*a , int n, int*b, int m){
    sort_Tangdan(a,0,n);
    sort_Tangdan(b,0,m);
    int* merge;
    merge =  gopMang(a,n,b,m);
    sort_Tangdan(merge,0,n+m);
    return merge;
}
