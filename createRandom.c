#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printRandoms(int lower, int upper,int count)
{
    for (int i = 0; i < count; i++) {
        int num = (rand() % (upper - lower + 1)) + lower;
        printf("%d\n", num);
    }
}
 
int main()
{
    int lower = 0, upper = 200000, count = 16000;
    srand(time(0));
    printRandoms(lower, upper, count);
    return 0;
}
