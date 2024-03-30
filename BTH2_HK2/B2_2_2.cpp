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

long gt(int n){
    if (n == 1)
        return 1;
    return gt(n-1) * n;
}

int main(){
    int n; 
    inp(n);
    printf("Giai thua cua %d la: %d\n",n,gt(n));
    return 0;
}