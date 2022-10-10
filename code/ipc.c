#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main()
{      
    key_t key = ftok("shmfile",65);
   
    int shmid = shmget(key,1024,0666|IPC_CREAT);
 	
 	
 	printf("Creating a new memory segment.");
 	printf("\nShmid: %d\n",shmid);
 	
    char *str = (char*) shmat(shmid,(void*)0,0);
   
    printf("Write Data : ");
    scanf("%[^\n]%*c", str);
 
    printf("Data written in memory: %s\n",str);
     
    shmdt(str);
     
    char *s = (char*) shmat(shmid,(void*)0,0);
 
    printf("Data read from memory: %s\n",s);
    shmdt(s);
   	shmctl(shmid,IPC_RMID,NULL);
 
    return 0;
}
