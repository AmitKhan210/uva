# include <iostream>
# include <cstdio>
# include <vector>
# include <cstring>
# include <math.h>
# include <map>
using namespace std;
# define SIZE 1000005
map <int, int> flag;

void seive(){
    int i, j, val;
    for(i = 2; i < SIZE; i++){
        flag[i] = 1;
    }
    val = sqrt(SIZE);
    for(i = 2; i <= val; i++){
        if(flag[i]){
            for(j = i; j * i < SIZE; j++){
                flag[j*i] = 0;
            }
        }
    }
}

int main(){
    seive();
    char snum[9], rsnum[9];
    int num, rnum, i, j, d, rd, m;
    while(scanf("%s", snum) == 1){
        num = 0;
        rnum = 0;
        int len = strlen(snum);
        for(i = 0, j = len - 1; i < len; i++, j--){
            rsnum[i] = snum[j];
        }
        rsnum[i] = '\0';
        m = 1;
        for(i = len - 1; i >= 0; i--){
            d = snum[i] - 48;
            rd = rsnum[i] - 48;
            num += d * m;
            rnum += rd * m;
            m = m * 10;
        }
        if(flag[num] == 0){
            printf("%d is not prime.\n", num);
        }
        else if(flag[rnum] == 1 && len > 1 && num != rnum){
            printf("%d is emirp.\n", num);
        }
        else{
            printf("%d is prime.\n", num);
        }

    }
}
