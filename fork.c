#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(){
    
    int pid;
    pid = fork();

    if(pid == 0){
        printf("exec incia . . . \n");
        execl("/bin/ls","ls",(char *)0);
    }else{
        wait(0);
        printf("Padre: ls se ha completado en el hijo \n");
    }

    return 0;
}
