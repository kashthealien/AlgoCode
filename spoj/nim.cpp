#include <stdio.h>

int main()
{
    int num, num1 = 2, num2 = 3;
    printf("2\n3\n");
    while ( num != 1597 )
    {
        num = num1 + num2;
        printf("%d\n", num);
        num1 = num2;
        num2 = num;
    }

    return 0;
}
