#include<stdlib.h>
#include<semaphore.h>
#include<unistd.h>
#include<pthread.h>
#include<stdio.h>

int in=0;  //in is for producer
int out=0;  //out is for consumer
int buff[5];  //5 is the size of buffer 
sem_t s,e,f;  //Data Type of Semaphore (s-BinarySemaphore, e-Empty, f-Filled)
int data=99;  //Data to be entered in buffer


//Producer Function
void *producer(void *arg)
{
sem_wait(&e);  //Allows the producer to enter the critical section
sem_wait(&s);  //Allows only one process to access buffer                                

int data;
data=rand()/5;  //rand() generates a random number
buff[in]=data;  //Random number has been entered in buffer
printf("Producer has entered data: %d\n",in);
in=(in+1)%5;

sem_post(&s);
sem_post(&f);
}

//Consumer Function
void *consumer(void *arg)
{
int val;
do
{
sem_wait(&f); //Allows the consumer to enter the critical section
sem_wait(&s); //Allows only one process at a time

data=buff[out];
printf("Process is consumed by: %d\n" ,out);
out=(out+1)%5;

sem_post(&s);
sem_post(&e);
sem_getvalue(&e,&val);
}while(val!=5);
}

//Main Function
int main(int argc,char *argv[])
{
pthread_t ptid[5]; //Producer Thread Id
pthread_t cid;   //Consumer Thread Id
sem_init(&s,0,1);
sem_init(&e,0,5);
sem_init(&f,0,0);
pthread_create(&cid,NULL,consumer,NULL);
for(int i=0;i<5;i++)
{
pthread_create(&ptid[i],NULL,producer,NULL);
}
pthread_join(ptid,NULL);
pthread_join(cid,NULL);

return 0;
}
