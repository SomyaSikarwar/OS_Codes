#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdio.h>

int main(){
    key_t key = ftok("file_name" , 65);
    
    int shmid = shmget(key , 1024 ,0666|IPC_CREAT);
    char *str = (char*) shmat(shmid , (void*)0,0);
    printf(str);
    shmdt(str);
    shmct(shmid,IPC_RMID,NULL);
    return 0;
}