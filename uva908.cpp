# include <iostream>
# include <cstdio>
# include <vector>
# include <algorithm>
using namespace std;

struct edge{
    int u, v, w;
    bool operator < (const edge& p) const{
        return w < p.w;
    }
};

vector <int> par;
vector <edge> e;

int FinD(int i){
    if(par[i] == i){
        return i;
    }
    else{
        par[i] = FinD(par[i]);
        return par[i];
    }
}

int mst(int N){
    sort(e.begin(), e.end());
    par.clear();
    par.push_back(1);
    for(int i = 1; i <= N; i++){
        par.push_back(i);
    }
    int count = 0, s = 0;
    int len = e.size();
    for(int i = 0; i < len; i++){
        int U = FinD(e[i].u);
        int V = FinD(e[i].v);
        if(U != V){
            par[V] = U;
            count++;
            s += e[i].w;
        }
        if(count == N - 1){
            break;
        }
    }
    return s;
}

int main(){
    int N, K, M, t, nt, U, V, W, T = 0;
    while(scanf("%d", &N) != EOF){
        t = 0;
        e.clear();
        for(int i = 0; i < N - 1; i++){
            scanf("%d %d %d", &U, &V, &W);
            t += W;
        }
        scanf("%d", &K);
        edge E;
        for(int i = 0; i < K; i++){
            scanf("%d", &E.u);
            scanf("%d", &E.v);
            scanf("%d", &E.w);
            e.push_back(E);
        }
        scanf("%d", &M);
        for(int i = 0; i < M; i++){
            scanf("%d", &E.u);
            scanf("%d", &E.v);
            scanf("%d", &E.w);
            e.push_back(E);
        }
        nt = mst(N);
        if(T != 0) {
            printf("\n");
        }
        T++;
        printf("%d\n%d\n", t, nt);
    }
}
