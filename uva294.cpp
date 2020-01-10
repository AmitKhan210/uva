# include <iostream>
# include <cstdio>
# include <math.h>
using namespace std;
# define SIZE 1000000
bool flag[SIZE+5];
int prime[SIZE+5];

int seive(){
    int i, val, total = 0, j;
    for(i = 2; i <= SIZE; i++) flag[i] = 1;
    val = sqrt(SIZE);
    for(i = 2; i <= val; i++){
        if(flag[i]){
            for(j = i; j * i <= SIZE; j++){
                flag[j*i] = 0;
            }
        }
    }
    for(i = 2; i < SIZE; i++){
        if(flag[i]) prime[total++] = i;
    }
    return total;
}

int divisor(int N){
    int i, val, Count, sum;
    val = sqrt(N) + 1;
    sum = 1;
    for(i = 0; prime[i] < val; i++){
        Count = 0;
        if(N % prime[i] == 0){
            while(N % prime[i] == 0){
                N /= prime[i];
                Count++;
            }
            sum *= (Count + 1);
        }
    }
    if(N > 1){
        sum *= 2;
    }
    return sum;
}
int main(){
    int total = seive();

    int L, H, N, D, P, maximum, i, j;
    scanf("%d", &N);
    for(i = 1; i <= N; i++){
        maximum = 0;
        scanf("%d %d", &L, &H);
        for(j = H; j >= L; j--){
            P = divisor(j);
            if(maximum <= P){
                maximum = P;
                D = j;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, H, D, maximum);
    }


}
