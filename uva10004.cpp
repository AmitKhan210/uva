# include <iostream>
# include <cstdio>
# include <queue>
# include <vector>
using namespace std;
# define MAX 200
int main(){
    int n, l;
    while(true){
        scanf("%d", &n);
        if(n == 0){
            return 0;
        }
        scanf("%d", &l);
        int color[n] = {0};
        vector <int> v[MAX];
        int x, y;
        for(int i = 0; i < l; i++){
            scanf("%d %d", &x, &y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        int bicolor = 1;
        queue <int> q;
        q.push(0);
        color[0] = 1;
        while(!q.empty()){
            int top = q.front();
            int len = v[top].size();
            for(int i = 0; i < len; i++){
                if(color[v[top][i]] == 0){
                    if(color[top] == 1){
                        color[v[top][i]] = 2;
                    }
                    else{
                        color[v[top][i]] = 1;
                    }
                    q.push(v[top][i]);
                }
                else if(color[v[top][i]] == color[top]){
                    bicolor = 0;
                }
            }
            q.pop();
        }
        if(bicolor == 1){
            printf("BICOLORABLE.\n");
        }
        else{
            printf("NOT BICOLORABLE.\n");
        }
    }

}
