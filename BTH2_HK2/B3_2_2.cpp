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

long fibo(int n){
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibo(n-1) + fibo(n-2);
}

int main(){
    int n;
    inp(n);
    printf("So fibonacci cua %d la: %d",n,fibo(n));
    return 0;
}