# include <bits/stdc++.h>
using namespace std;

# define mx 100005

struct node{
    int v, b, e;
};

int arr[mx];
node tree[mx * 4];
int i, j;

void build(int node, int l, int r){
    if(l == r){
        tree[node].v = arr[l];
        tree[node].b = l;
        tree[node].e = l;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (l + r) / 2;
    build(left, l, mid);
    build(right, mid + 1, r);
    if(tree[left].v == tree[right].v){
        tree[node].v = tree[left].v;
        tree[node].b = tree[left].b;
        tree[node].e = tree[right].e;
    }
    else{
        int left_size = tree[left].e - tree[left].b + 1;
        int right_size = tree[right].e - tree[right].b + 1;
        if(left_size <= right_size){
            tree[node].v = tree[right].v;
            tree[node].b = tree[right].b;
            tree[node].e = tree[right].e;
        }
        else{
            tree[node].v = tree[left].v;
            tree[node].b = tree[left].b;
            tree[node].e = tree[left].e;
        }
        if(arr[tree[left].e + 1] == arr[tree[right].b - 1]){
            if(tree[right].b - tree[left].e - 1 > tree[node].e - tree[node].b + 1){
                tree[node].v = arr[tree[left].e + 1];
                tree[node].b = tree[left].e + 1;
                tree[node].e = tree[right].b - 1;
            }
        }
    }
}

int main(){

    int n, q;
    while(scanf("%d", &n) && n){
        scanf("%d", &q);
        for(int x = 1; x <= n; x++){
            scanf("%d", &arr[x]);
        }
        build(1, 1, n);
        cout << tree[1].v << endl;
        cout << tree[1].b << endl;
        cout << tree[1].e << endl;
    }

}
