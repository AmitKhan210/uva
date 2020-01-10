# include <iostream>
# include <math.h>

using namespace std;

class test{
    long p;
    long mper;
    int check;
public:
    void set(int P){
        p = P;
        mper = pow(2,p-1) * (pow(2,p) - 1);
    }
    void Test(){
        long sum = 0;

        if(mper % 2 != 0){
            check = 0;
        }
        else{
            for(long i = 1; i <= mper / 2; i++){
                if(mper % i == 0){
                    sum += i;
                }
            }

            if(sum == mper){
                check = 1;
            }
            else
                check = 0;
        }
    }

    void print(){
        if(check == 1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
};

int main()
{
    int n;

    cin>>n;

    test t[n];

    for(long i = 0; i < n; i++){
        long P;
        char com;
        cin>>P;
        t[i].set(P);
        t[i].Test();
        t[i].print();
        if(i == n-1)
            break;
        cin>>com;
    }

    return 0;

}
