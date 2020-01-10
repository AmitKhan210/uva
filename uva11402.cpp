# include <bits/stdc++.h>
using namespace std;

# define mx 1024005

struct Node{
    int bu, ba;
    string last;
};

int arr[mx];
Node tree[4*mx];
int a, b, ans;
string query;

void build(int node, int l, int r){
    if(l == r){
        if(arr[l] == 0){
            tree[node].ba = 1;
            tree[node].bu = 0;
        }
        else{
            tree[node].ba = 0;
            tree[node].bu = 1;
        }
        tree[node].last = "no";
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (l + r) / 2;
    build(left, l, mid);
    build(right, mid + 1, r);
    tree[node].ba = tree[left].ba + tree[right].ba;
    tree[node].bu = tree[left].bu + tree[right].bu;
    tree[node].last = "no";
}

void update(int node, int l, int r){
    if(r < a || b < l){
        return;
    }
    if(a <= l && r <= b){
        if(query == "F"){
            tree[node].bu += tree[node].ba;
            tree[node].ba = 0;
            tree[node].last = "F";
        }
        else if(query == "E"){
            tree[node].ba += tree[node].bu;
            tree[node].bu = 0;
            tree[node].last = "E";
        }
        else{
            if(tree[node].ba != 0 && tree[node].bu != 0){
                int temp = tree[node].bu;
                tree[node].bu = tree[node].ba;
                tree[node].ba = temp;
                if(tree[node].last == "no"){
                    tree[node].last = "I";
                }
                else{
                    tree[node].last = "no";
                }
            }
            else{
                int temp = tree[node].bu;
                tree[node].bu = tree[node].ba;
                tree[node].ba = temp;
                tree[node].last = "I";
            }
        }
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (l + r) / 2;
    if(tree[node].last != "no"){
        if(tree[node].last == "F"){
            tree[left].bu += tree[left].ba;
            tree[left].ba = 0;
            tree[left].last = "F";
            tree[right].bu += tree[right].ba;
            tree[right].ba = 0;
            tree[right].last = "F";
        }
        else if(tree[node].last == "E"){
            tree[left].ba += tree[left].bu;
            tree[left].bu = 0;
            tree[left].last = "E";
            tree[right].ba += tree[right].bu;
            tree[right].bu = 0;
            tree[right].last = "E";
        }
        else{
            if(tree[node].ba != 0 && tree[node].bu != 0){
                int temp = tree[left].bu;
                tree[left].bu = tree[left].ba;
                tree[left].ba = temp;
                tree[left].last = "I";
                temp = tree[right].bu;
                tree[right].bu = tree[right].ba;
                tree[right].ba = temp;
                tree[right].last = "I";
            }
            else if(tree[node].ba == 0){
                tree[left].bu += tree[left].ba;
                tree[left].ba = 0;
                tree[left].last = "I";
                tree[right].bu += tree[right].ba;
                tree[right].ba = 0;
                tree[right].last = "I";
            }
            else{
                tree[left].ba += tree[left].bu;
                tree[left].bu = 0;
                tree[left].last = "I";
                tree[right].ba += tree[right].bu;
                tree[right].bu = 0;
                tree[right].last = "I";
            }
        }
        tree[node].last = "no";
    }
    update(left, l, mid);
    update(right, mid + 1, r);
    tree[node].ba = tree[left].ba + tree[right].ba;
    tree[node].bu = tree[left].bu + tree[right].bu;
}

void que(int node, int l, int r){
    if(r < a || b < l){
        return;
    }
    if(a <= l && r <= b){
        ans += tree[node].bu;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (l + r) / 2;
    if(tree[node].last != "no"){
        if(tree[node].last == "F"){
            tree[left].bu += tree[left].ba;
            tree[left].ba = 0;
            tree[left].last = "F";
            tree[right].bu += tree[right].ba;
            tree[right].ba = 0;
            tree[right].last = "F";
        }
        else if(tree[node].last == "E"){
            tree[left].ba += tree[left].bu;
            tree[left].bu = 0;
            tree[left].last = "E";
            tree[right].ba += tree[right].bu;
            tree[right].bu = 0;
            tree[right].last = "E";
        }
        else{
            if(tree[node].ba != 0 && tree[node].bu != 0){
                int temp = tree[left].bu;
                tree[left].bu = tree[left].ba;
                tree[left].ba = temp;
                tree[left].last = "I";
                temp = tree[right].bu;
                tree[right].bu = tree[right].ba;
                tree[right].ba = temp;
                tree[right].last = "I";
            }
            else if(tree[node].ba == 0){
                tree[left].bu += tree[left].ba;
                tree[left].ba = 0;
                tree[left].last = "I";
                tree[right].bu += tree[right].ba;
                tree[right].ba = 0;
                tree[right].last = "I";
            }
            else{
                tree[left].ba += tree[left].bu;
                tree[left].bu = 0;
                tree[left].last = "I";
                tree[right].ba += tree[right].bu;
                tree[right].bu = 0;
                tree[right].last = "I";
            }
        }
        tree[node].last = "no";
    }
    que(left, l, mid);
    que(right, mid + 1, r);
}

int main(){

    int tc, n, m, t, len, q, que_no;
    string pirates;
    scanf("%d", &tc);
    for(int i = 1; i <= tc; i++){
        n = 0;
        que_no = 1;
        scanf("%d", &m);
        for(int j = 0; j < m; j++){
            scanf("%d", &t);
            cin >> pirates;
            len = pirates.length();
            while(t--){
                for(int k = 0; k < len; k++){
                    n++;
                    arr[n] = pirates[k] - 48;
                }
            }

        }
        build(1, 1, n);
        printf("Case %d:\n", i);
        scanf("%d", &q);
        while(q--){
            cin >> query;
            scanf("%d %d", &a, &b);
            a++;
            b++;
            if(query == "S"){
                ans = 0;
                que(1, 1, n);
                printf("Q%d: %d\n", que_no++, ans);
            }
            else{
                update(1, 1, n);
            }
        }
    }


}
