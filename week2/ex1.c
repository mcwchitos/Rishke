#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;
    printf("Size of integer is %d\n", (int)sizeof(a));
    printf("Value of integer is %d\n", a);
    printf("Size of float is %d\n", (int)sizeof(b));
    printf("Value of float is %f\n", b);
    printf("Size of double is %d\n", (int)sizeof(c));
    printf("Value double is %f\n", c);
    return 0;
}
