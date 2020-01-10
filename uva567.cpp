# include <iostream>
# include <cstdio>
# include <vector>
# include <queue>
using namespace std;

int main(){
    int x, test = 1;
    while(scanf("%d", &x) != EOF){
        vector <int> v[21];
        int j;
        for(int i = 0; i < x; i++){
            scanf("%d", &j);
            v[1].push_back(j);
            v[j].push_back(1);
        }
        for(int i = 2; i < 20; i++){
            scanf("%d", &x);
            for(int k = 0; k < x; k++){
                scanf("%d", &j);
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
        int N, A, B;
        scanf("%d", &N);
        printf("Test Set #%d\n", test++);
        for(int i = 1; i <= N; i++){
            queue <int> q;
            scanf("%d %d", &A, &B);
            int level[21] = {0};
            int vis[21] = {0};
            level[A] = 0;
            vis[A] = 1;
            q.push(A);
            while(!q.empty()){
                int len = v[q.front()].size();
                for(int k = 0; k < len; k++){
                    if(vis[v[q.front()][k]] == 0){
                        vis[v[q.front()][k]] = 1;
                        level[v[q.front()][k]] = level[q.front()] + 1;
                        q.push(v[q.front()][k]);
                    }
                }
                q.pop();
            }
            if(A < 10){
                printf(" %d to ", A);
            }
            else{
                printf("%d to ", A);
            }
            if(B < 10){
                printf(" %d:", B);
            }
            else{
                printf("%d:", B);
            }
            if(level[B] < 10){
                printf(" %d\n", level[B]);
            }
            else{
                printf("%d\n", level[B]);
            }

        }
        printf("\n");
    }
}
