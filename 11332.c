# include <stdio.h>

int main(void)
{
    int n, sum, j = 1;


    while(1){
        sum = 0;
        j = 1;
        scanf("%d", &n);
        if(n == 0)
            return 0;
        while(j){
            sum += n % 10;
            n /= 10;
            if(n != 0){
                continue;
            }
            n = sum;
            sum = 0;

            switch(n)
            {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                    printf("%d\n", n);
                    j = 0;
                    break;
            }


        }



    }

}
