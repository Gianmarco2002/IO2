#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    printf("Id proceso hijo = %d \n", getpid());
    printf("Id proceso padre = %d \n", getppid());
    return 0;
}