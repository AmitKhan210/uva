# include <iostream>
# include <cstdio>
# include <vector>
# include <algorithm>
# include <math.h>
using namespace std;
# define MAX 1005
struct Node{
    int x, y;
};
struct Edge{
    int u, v;
    double w;
    bool operator < (const Edge& p) const {
        return w < p.w;
    }
};
vector <Node> N;
vector <Edge> E;
int par[1005];
int c = 1;

int FinD(int x){
    if(par[x] == x) { return x; }
    else{
        return par[x] = FinD(par[x]);
    }
}
void mst(int n, int r){
    sort(E.begin(), E.end());
    int len = E.size();
    int U, V, norail = 0, count = 0;
    double road = 0, rail = 0;
    for(int i = 0; i < len; i++){
        U = FinD(E[i].u);
        V = FinD(E[i].v);
        if(U != V){
            par[U] = V;
            count++;
            if(E[i].w > r){
                rail += E[i].w;
                norail++;
            }
            else{
                road += E[i].w;
            }
        }
        if(count == n-1){
            break;
        }
    }
    printf("Case #%d: %d %.lf %.lf\n", c, norail+1, road, rail);
    c++;
}
int main(){
    int T, i, j, k, n, r;
    double dis;
    Node no;
    Edge eg;
    scanf("%d", &T);
    for(i = 1; i <= T; i++){
        N.clear();
        E.clear();
        scanf("%d %d", &n, &r);
        for(j = 0; j < n; j++){
            par[j] = j;
            scanf("%d %d", &no.x, &no.y);
            N.push_back(no);
            for(k = 0; k < j; k++){
                eg.u = j;
                eg.v = k;
                eg.w = sqrt((N[j].x - N[k].x)*(N[j].x - N[k].x)+(N[j].y - N[k].y)*(N[j].y - N[k].y));
                E.push_back(eg);
            }
        }
        mst(n, r);
    }
}
