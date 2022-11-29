#include <sys/types.h>
#include <stdio.h>
#include <stdio.h>
#include <stdio.h>

int main(void){
    pid_t pid[50];
    int status[50];
    
    for(int i=0;i<3;i++){   // 0 - 1 - 2 
        if((pid[i]=fork())==0){
            printf("soy el proceso %d hijo de %d \n", getpid(),getppid());
            if(i==1){
                for (int j=0 ; j<2;j++){
                    if((pid[i]=fork())== 0){
                        printf("soy el proceso %d hijo de %d \n", getpid(),getppid());

                        break;
                    }
                }
            }
            break;
        } 
    }

    while (1);

    
    return 0;
}
