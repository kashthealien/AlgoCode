



                #include <stdio.h>
                int main()
                {
                    long int t;
                    scanf("%ld", &t);
                    while(t--)
                    {
                        // input
                        long int a;
                        unsigned long long int e;
                        // get input
                        scanf("%ld %llu", &a, &e);

                        unsigned long long int i = 1;
                        int cost = 0, j = 0, count = 0;

                        while ( j ++ <= 64 ) {
                            if ( e & i ) {
                                cost ++;
                                while ( e & i ) { count ++; i <<= 1; }
                                if ( count > 1) { e |= i; count = 0; }
                            } else {
                                if ( count > 1 ) cost ++;
                                count = 0;
                                i <<=1;
                            }
                        }
                        printf("%d\n", cost);
                    }
                    return 0;
                }
