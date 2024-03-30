#include<iostream>

using namespace std;

void inp(int &n){
    do {
        printf("Hay nhap 1 so nguyen duong n: ");
        scanf("%d", &n);
        if (n <= 0)
            printf("Nhap lai!!");
    } while (n <= 0);
}

long tong1(int n){
    if (n == 1)
        return 1;
    return tong1(n-1) + n;
}

long tong2(int n){
    if (n == 1)
        return 1;
    return tong2(n-1) + n*n;
}

double tong3(int n){
    if (n == 1)
        return 1;
    return tong3(n-1) + 1.0/(2*n-1);
}

long gt(int n){
    if (n == 1)
        return 1;
    return gt(n-1) * n;
}

long tong4(int n){
    if (n == 1)
        return 1;
    return tong4(n-1) + gt(n);
}

int main(){
    int n; 
    inp(n);
    printf("Tong S1 = 1 + 2 + 3 + ... + %d = %d\n",n, tong1(n));
    printf("Tong S2 = 1^2 + 2^2 + 3^2 + ... + %d^%d = %d\n",n, n,tong2(n));
    printf("Tong S3 = 1 + 1/3 + 1/5 + ... + 1/%d = %f\n",2*n-1, tong3(n));
    printf("Tong S4 = 1! + 2! + 3! + ... + %d! = %d\n",n, tong4(n));
    return 0;
}