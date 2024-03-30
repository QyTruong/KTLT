#include<iostream>

using namespace std;

long long dec_to_bin(long n){
    if (n == 0)
        return 0;
    return dec_to_bin(n/2)*10 + n%2;  
}

int main(){
    long n; 
    printf("Hay nhap 1 so nguyen bat ky: ");
    scanf("%ld", &n);
    printf("%ld chuyen sang he nhi phan la: %lld", n,dec_to_bin(n));
    return 0; 
}