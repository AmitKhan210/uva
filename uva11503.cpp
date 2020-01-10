# include <iostream>
# include <cstdio>
# include <string>
# include <map>

using namespace std;

map <string, string> par;
map <string, int> num;

string FinD(string s){
    if(par[s] == s){
        return s;
    }
    else{
        return par[s] = FinD(par[s]);
    }
}
int main(){

    int T, F;
    string s1, s2, ps1, ps2;
    map <string, string> :: iterator it;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &F);
        par.clear();
        num.clear();
        while(F--){
            cin >> s1 >> s2;
            it = par.find(s1);
            if(it == par.end()){
                par[s1] = s1;
                num[s1] = 1;
            }
            it = par.find(s2);
            if(it == par.end()){
                par[s2] = s2;
                num[s2] = 1;
            }
            ps1 = FinD(s1);
            ps2 = FinD(s2);
            par[ps2] = ps1;
            if(ps1 != ps2){
                num[ps1] += num[ps2];
            }
            printf("%d\n", num[ps1]);

        }
    }

}
