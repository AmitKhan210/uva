# include <iostream>
# include <cstdio>
# include <math.h>
using namespace std;

int ifprime(long a){
    int check = 0;

    for(long i = 2; i <= sqrt(a); i++){
        if(a % i == 0){
            check = 1;
            break;
        }
    }

    return check;
}

int main()
{
    long a, b, p;

    while(cin>>a>>b){
        p = 0;
        for(long z = a; z <= b; z++){
            int check = ifprime(z*z + z + 41);
            if(check == 0){
                p++;
            }
        }

        double ans = (static_cast<double>(p) / (b - a + 1)) * 100;

        printf("%.2lf\n", ans);

    }

    return 0;

}
