# include <iostream>
# include <cstdio>
# include <utility>
using namespace std;

# define pii pair <int, int>
# define mx 100005

int ar[mx];
int tree[4*mx];
int treeV[4*mx];
pii mr[4*mx];

void build(int node, int l, int r){
    if(l == r){
        tree[node] = 1;
        treeV[node] = ar[l];
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (l + r) / 2;
    build(left, l, mid);
    build(right, mid+1, r);
    if(treeV[left] == treeV[right]){
        treeV[node] = treeV[left];
        tree[node] = tree[left] + tree[right];
    }
    else if(tree[left] > tree[right]){
        tree[node] = tree[left];
        treeV[node] = tree[left];
        mr[node].first = tree[right];
        mr[node].second = treeV[right];

    }
    else{
        if(mr[left].first != 0){
            if(mr[left].second == treeV[right]){
                tree[node] = tree[right] + mr[left].first;
                treeV[node] = treeV[right];
            }
            else{
                tree[node] = tree[right];
                treeV[node] = treeV[right];
            }
            return;
        }
        tree[node] = tree[right];
        treeV[node] = treeV[right];
    }
}

int main(){
    int n, q;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &ar[i]);
    }
    build(1, 1, n);

    return 0;
}
