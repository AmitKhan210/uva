# include <bits/stdc++.h>
using namespace std;

# define mx 200005

int a[mx];
int tree[4 * mx];
int x, y, newvalue, ans;

void build(int node, int l, int r){
    if(l == r){
        tree[node] = a[l];
        return;
    }
    int left_node = node * 2;
    int right_node = node * 2 + 1;
    int mid = (l + r) / 2;
    build(left_node, l, mid);
    build(right_node, mid + 1, r);
    tree[node] = tree[left_node] + tree[right_node];
}

void update(int node, int l, int r){
    if(x < l || r < x){
        return;
    }
    if(x == l && x == r){
        tree[node] = newvalue;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (l + r) / 2;
    update(left, l, mid);
    update(right, mid + 1, r);
    tree[node] = tree[left] + tree[right];
}

void que(int node, int l, int r){
    if(r < x || y < l){
        return;
    }
    if(x <= l && r <= y){
        ans += tree[node];
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (l + r) / 2;
    que(left, l, mid);
    que(right, mid + 1, r);
}

int main(){

    int n, tc = 1;
    string command;
    while(scanf("%d", &n) && n){
        if(tc > 1){
            printf("\n");
        }
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        build(1, 1, n);
        printf("Case %d:\n", tc++);
        while(true){
            cin >> command;
            if(command == "S"){
                scanf("%d %d", &x, &newvalue);
                update(1, 1, n);
            }
            else if(command == "M"){
                scanf("%d %d", &x, &y);
                ans = 0;
                que(1, 1, n);
                printf("%d\n", ans);
            }
            else{
                break;
            }
        }
    }

}
