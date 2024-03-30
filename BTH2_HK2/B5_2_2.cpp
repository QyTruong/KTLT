#include<iostream>

using namespace std;

int cnt(long long n, int x = 1){
    if (n < 10)
        return x;
    return cnt(n/10, x + 1);
}

int main(){
    long long n;
    printf("Hay nhap 1 day so nguyen bat ky: ");
    scanf("%lld", &n);
    printf("Day so %d co %d chu so!!",n,cnt(n));
    return 0;
}