# include <iostream>
# include <cstdio>
# include <map>
# include <string>
using namespace std;

int main(){

    int T;
    scanf("%d", &T);
    char H;
    while(T--){
        int count = 0;
        scanf(" %c", &H);
        map <char, char> par;
        char c = 'A';
        while(c <= H){
            par[c] = c;
            c++;
        }
        string str;
        getchar();
        while(getline(cin, str)){
            if(str.size() == 0){
                break;
            }
            char e1 = str[0];
            char e2 = str[1];
            if(par[e1] != e1){
                while(par[e1] != e1){
                    e1 = par[e1];
                }
            }
            if(par[e2] != e2){
                while(par[e2] != e2){
                    e2 = par[e2];
                }
            }
            par[e1] = e2;
        }
        c = 'A';
        while(c <= H){
            if(par[c] == c){
                count++;
            }
            c++;
        }
        printf("%d\n", count);
        if(T){
            printf("\n");
        }
    }
}
