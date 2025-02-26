#include <stdio.h>
#include <limits.h>

int main(void) {
    printf("%d\n", INT_MAX);
    printf("%d\n", INT_MAX & 0xff);
    printf("%d\n", INT_MAX | 1);
    printf("%d\n", INT_MIN);
    printf("%d\n", 200>>1);
    printf("%d\n", 200<<1);
}