#include<iostream>

using namespace std;

double somu(int x, int n){
    if (n == 1)
        return x;
    else if (n == -1)
        return 1.0/x;
    else if (n < -1)
        return somu(x,n+1) * 1.0/x;
    else 
        return somu(x,n-1) * x;
}

int main(){
    int n, x;
    printf("Hay nhap 2 so nguyen duong x va luy thua n: ");
    scanf("%d %d",&x,&n); 
    printf("%d ^ %d = %1.5f", x,n,somu(x,n));
    return 0;
}