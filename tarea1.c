#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    printf("pedaso de caca");
    while(1);
    /*
    pid_t pid1,pid2; // hijos
    int status1,status2;

    if((pid1=fork())==0){
        // proceso hijo
        printf("Soy el primer hijo (%d, hijo de %d) \n", getpid(),getppid());
    }else{ // proceso padre
        if((pid2=fork()) == 0){
            //proceso hijo2
            printf("Soy el segundo hijo (%d, hijo de %d) \n", getpid(),getppid());

        }else{
            //esperamos al primer hijo
            waitpid(pid1,&status1,0);    
            //esperamos al 2do hijo
            waitpid(pid2,&status2,0);
            printf("Soy el padre (%d, hijo de %d) \n", getpid(),getppid());
        }
    }
    */
    return 0;
}