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

#include <stdio.h>
int main(){
    int x = 1, y = 2;
    printf("O valor de x = %d e y = %d \n", x, y);
    // Assembly Inline Básico
    __asm__ (
    "movl $10, %eax;"
    "movl $20, %ebx;"
    );
    // Assembly Inline Estendido
    __asm__ (
    "movl %%eax, %0;"
    "movl %%ebx, %1;"
    : "=r" ( x ), "=r" ( y )
    );
    printf("O valor de x = %d e y = %d \n", x, y);
    return 0 ;
}

#include <stdio.h>
int main(){
    int x = 10, y = 20, z = 0;
    printf("O valor de x = %d, y = %d e z = %d \n", x, y, z);
    // Assembly Inline Estendido
    __asm__ (
    "mov %2, %%ebx;"
    "mov %1, %%eax;"
    "add %%ebx, %%eax;"
    "mov %%eax, %0;"
    : "=r" (z) /* Variáveis de Saída */
    : "r" ( x ), "r" ( y ) /* Variáveis de Entrada */
    );
    printf("O valor de x = %d, y = %d e z = %d \n", x, y, z);
    return 0 ;
}

#include <stdio.h>
int main(){
    int x = 10, y = 20, z = 0;
    printf("O valor de x = %d, y = %d e z = %d \n", x, y, z);
    // Assembly Inline Estendido
    __asm__ (
    "mov %%ecx, %%eax;"
    "add %%ebx, %%eax;"
    : "=a" (z) /* Variáveis de Saída */
    : "b" ( x ), "c" ( y ) /* Variáveis de Entrada */
    );
    printf("O valor de x = %d, y = %d e z = %d \n", x, y, z);
    return 0 ;
}

#include <stdio.h>
int main(){
    int x = 10, y = 20, z = 0;
    printf("O valor de x = %d, y = %d e z = %d \n", x, y, z);
    // Assembly Inline Estendido
    __asm__ (
    "add %%ebx, %%eax;"
    : "=a" (z) /* Variáveis de Saída */
    : "a" ( x ), "b" ( y ) /* Variáveis de Entrada */
    );
    printf("O valor de x = %d, y = %d e z = %d \n", x, y, z);
    return 0 ;
}

#include <stdio.h>
int main() {
    int arg1, arg2, add, sub, mul, quo, rem ;
    printf( "Enter two integer numbers : " );
    scanf( "%d%d", &arg1, &arg2 );
    /* Perform Addition, Subtraction, Multiplication & Division */
    __asm__ ( "addl %%ebx, %%eax;" : "=a" (add) : "a" (arg1) , "b" (arg2) );
    __asm__ ( "subl %%ebx, %%eax;" : "=a" (sub) : "a" (arg1) , "b" (arg2) );
    __asm__ ( "imull %%ebx, %%eax;" : "=a" (mul) : "a" (arg1) , "b" (arg2) );
    __asm__ ( "movl $0x0, %%edx;"
    "movl %2, %%eax;"
    "movl %3, %%ebx;"
    "idivl %%ebx;" : "=a" (quo), "=d" (rem) : "m" (arg1), "m" (arg2) );
    printf( "%d + %d = %d\n", arg1, arg2, add );
    printf( "%d - %d = %d\n", arg1, arg2, sub );
    printf( "%d * %d = %d\n", arg1, arg2, mul );
    printf( "%d / %d = %d\n", arg1, arg2, quo );
    printf( "%d %% %d = %d\n", arg1, arg2, rem );
    return 0 ;
}

#include <stdio.h>

int main() {

    float arg1, arg2, add, sub, mul, div ;

    printf( "Enter two numbers : " );
    scanf( "%f%f", &arg1, &arg2 );

    /* Perform floating point Addition, Subtraction, Multiplication & Division */
    __asm__ ( "fld %1;"
              "fld %2;"
              "fadd;"
              "fstp %0;" : "=m" (add) : "m" (arg1), "m" (arg2) ) ;

    __asm__ ( "fld %2;"
              "fld %1;"
              "fsub;"
              "fstp %0;" : "=m" (sub) : "m" (arg1), "m" (arg2) ) ;

    __asm__ ( "fld %1;"
              "fld %2;"
              "fmul;"
              "fstp %0;" : "=m" (mul) : "m" (arg1), "m" (arg2) ) ;

    __asm__ ( "fld %2;"
              "fld %1;"
              "fdiv;"
              "fstp %0;" : "=m" (div) : "m" (arg1), "m" (arg2) ) ;

    printf( "%f + %f = %f\n", arg1, arg2, add );
    printf( "%f - %f = %f\n", arg1, arg2, sub );
    printf( "%f * %f = %f\n", arg1, arg2, mul );
    printf( "%f / %f = %f\n", arg1, arg2, div );

    return 0 ;
}