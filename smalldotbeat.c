#include<stdio.h>
#include<time.h>

int main(void) {
    printf("@%lu\n", ((((unsigned long)time(NULL) + 3600) % 86400) * 10) / 864);
    return 0;
}
