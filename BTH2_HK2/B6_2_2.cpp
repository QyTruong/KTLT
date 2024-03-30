#include<iostream>

using namespace std;

long long reverse(long n, int x = 0){
    if (n == 0)
        return x;
    return reverse(n/10, x*10 + n%10);
}

int main(){
    long long n; 
    printf("Hay nhap 1 day so nguyen bat ky: ");
    scanf("%lld", &n);
    printf("So dao nguoc cua %d la: %d",n,reverse(n));
    return 0;
}