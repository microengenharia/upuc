#include <stdio.h>
int main(){
    int x = 0;
    printf("O valor de x = %d \n", x);
    // Assembly Inline Básico
    __asm__ (
        "movl $10, %eax;"
    );
    // Assembly Inline Estendido
    __asm__ (
        "movl %%eax, %0;"
    : "=r" ( x )
    );
    printf("O valor de x = %d \n", x);
    return 0 ;
}