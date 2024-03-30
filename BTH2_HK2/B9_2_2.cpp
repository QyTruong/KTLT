#include<iostream>

using namespace std;

long bin_to_dec(long long n){
    if (n == 0)
        return 0;
    return bin_to_dec(n/10)*2 + n%10;
}

int main(){
    long long n; 
    printf("Hay nhap 1 so nhi phan bat ky: ");
    scanf("%lld", &n);
    printf("%lld chuyen sang he thap phan la: %ld", n, bin_to_dec(n));

    return 0;
}