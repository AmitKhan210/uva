# include <iostream>
# include <cstdio>
# include <string>
# include <vector>
# include <map>
using namespace std;

map <string, int> m;
map <int, int> par;
vector <int> v;

int FinD(int n){
    if(par[n] == n){
        return n;
    }
    else{
        par[n] = FinD(par[n]);
        return par[n];
    }
}


int main(){

    int C, R;
    while(scanf("%d %d", &C, &R)){
        if(C == 0 && R == 0){
            break;
        }

        m.clear();
        par.clear();
        v.clear();
        v.assign(C, 1);
        string name;
        for(int i = 0; i < C; i++){
            cin >> name;
            m[name] = i;
            par[i] = i;
        }
        if(R == 0){
            printf("1\n");
            continue;
        }
        string s1, s2;
        int mAx = 0;
        for(int i = 0; i < R; i++){
            cin >> s1;
            cin >> s2;
            int a = FinD(m[s1]);
            int b = FinD(m[s2]);
            par[b] = a;
            if(a != b){
                v[a] += v[b];
            }
            if(mAx < v[a]){
                mAx = v[a];
            }
        }

        printf("%d\n", mAx);
    }

}
