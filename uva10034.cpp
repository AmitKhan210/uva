# include <iostream>
# include <cstdio>
# include <vector>
# include <algorithm>
# include <math.h>
using namespace std;
# define MAX 105
struct Node{
    double x, y;
};
struct Edge{
    int u, v;
    double w;
    bool operator < (const Edge& p) const {
        return w < p.w;
    }
};
int par[MAX];
vector <Node> N;
vector <Edge> E;

int FinD(int x){
    if(par[x] == x) return x;
    else{
        return par[x] = FinD(par[x]);
    }
}

double mst(int n){
    sort(E.begin(), E.end());
    int U, V, count = 0, len;
    double cost = 0;
    len = E.size();
    for(int i = 0; i < len; i++){
        U = FinD(E[i].u);
        V = FinD(E[i].v);
        if(U != V){
            par[U] = V;
            count++;
            cost += E[i].w;
        }
        if(count == n-1) break;
    }
    return cost;
}
double Distance(Node a, Node b){
    double cost;
    cost = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
    cost = sqrt(cost);
    return cost;
}
int main(){
    int tc, n, i, j, k = 0;
    double cost;
    Node No;
    Edge Eg;
    scanf("%d", &tc);
    while(tc--){
        N.clear();
        E.clear();
        scanf("%d", &n);
        for(i = 0; i < n; i++){
            par[i] = i;
            scanf("%lf", &No.x);
            scanf("%lf", &No.y);
            N.push_back(No);
            for(j = 0; j < i; j++){
                Eg.u = i;
                Eg.v = j;
                Eg.w = Distance(N[i], N[j]);
                E.push_back(Eg);
            }
        }
        cost = mst(n);
        printf("%0.2lf\n", cost);
        if(tc != 0){
            printf("\n");
        }

    }
    return 0;
}
