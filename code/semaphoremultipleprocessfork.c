#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>


int main(){

int pid = fork();


//shmget returns an identifier in shmid
int shmid1 = shmget((key_t)100,1024,0666|IPC_CREAT);
int shmid2 = shmget((key_t)200,1,0666|IPC_CREAT);
char flag = (char *) shmat(shmid2,(void)0,0);
flag[0]='p';

if (pid!=0){
//producer process
printf("\n1.PRODUCER\n2.CONSUMER\n3.EXIT\n");
int choice;
scanf("%d",&choice);


int buffersize = (int *) shmat(shmid1,(void)0,0);
switch(choice){
case 1:
flag[0]='p';
(*(buffersize))++;
printf("Produced the item\n");
break;

case 2:
flag[0] = 'c';
int bs = *buffersize;
if (bs==0){
printf("Empty\n");
flag[0]='p';

} else {
printf("Consumed item!!\n");
flag[0]='p';

}


}


//shmat to attach to shared memory
char str = (char *) shmat(shmid1,(void)0,0);
int p = getpid();


flag[0] = 'w';
printf("Write data : ");

fgets(str,1000,stdin);
printf("process %d writing data to memory : %s\n",p,str);
shmdt(str);
flag[0]='r';



} else {

while (flag[0]=='p');
int p = getpid();

char str = (char) shmat(shmid1,(void*)0,0);

printf("process %d reading from memory: %s\n",p,str);
// destroy the shared memory
       shmctl(shmid1,IPC_RMID,NULL);
   
       return 0;
}






}
