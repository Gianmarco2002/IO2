#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(void){
    printf("el id del proceso es : %d \n", getpid());
    return 0;
}