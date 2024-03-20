#include<iostream>
#include<cstdlib>
#define SIZE 20
using namespace std;


void ktao(int a[][SIZE],int b[][SIZE], int n){
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            // Khởi tạo các giá trị ngẫu nhiên từ 1 -> 9
            a[i][j] = rand()%10; 
            b[i][j] = rand()%10;
        }
    }
}

void xuat(int a[][SIZE], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void tong_mt(int a[][SIZE],int b[][SIZE], int c[][SIZE], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            c[i][j] = a[i][j] + b[i][j]; 
        }
    }
}

void tich_mt(int a[][SIZE],int b[][SIZE], int c[][SIZE], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            c[i][j] = 0;
            for (int k = 0; k < n; k++){
                c[i][j] += a[k][i] * b[k][j]; 
            }
        }
    }
}


int main(){
    int n;
    cin >> n; 
    int a[n][SIZE], b[n][SIZE], tong[n][SIZE], tich[n][SIZE];
    ktao(a, b, n);
    tong_mt(a,b,tong,n);
    tich_mt(a,b,tich,n);
    cout << "Ma tran thu 1: \n";
    xuat(a, n);
    cout << "Ma tran thu 2: \n";
    xuat(b, n);
    cout << "Tong 2 ma tran vuong " << "cap " << n << ": \n";
    xuat(tong,n);
    cout << "Tich 2 ma tran vuong " << "cap " << n << ": \n";
    xuat(tich,n);
    return 0;
}