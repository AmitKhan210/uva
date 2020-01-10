# include <iostream>
# include <algorithm>

using namespace std;

int main()
{
    int N;
    int arr[36];

    while(cin>>N){
        int nel = N * (N - 1) / 2;
        int arr2[N];
        for(int i = 0; i < nel; i++){
            cin>>arr[i];
        }

        sort(arr, arr + nel);



    }
}
