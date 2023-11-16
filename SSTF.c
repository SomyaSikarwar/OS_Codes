#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<math.h>

int no_disk_requests, tracks , head ,distance;
int index =0;
int dreq[50] , finish[30];

void sstf(){
    int diff , min ,pending = no_disk_requests,head1=head;
    
    for(int i =0 ; i< no_disk_requests;i++){
        finish[i] = 0 ;
    }
    
    while(pending > 0){
        min = 9999;
        for(int i = 0 ; i< no_disk_requests ;i++){
            diff = abs(head - dreq[i]);
            
            if(finish[i] == 0 && diff < min){
                min = diff ;
                index = i ;
            }
        }
        
        finish[index] = 1;
        distance+=abs(head-dreq[index]);
        head=dreq[index];
        pending--;
        printf("%d ,",head);
    }
    
    printf("\n\n Total Distance Traversed=%d",distance);
    
}

int main(){
    
    printf("Number of disk requests : ");
    scanf("%d",&no_disk_requests);
    
    printf("Total number of tracks : ");
    scanf("%d",&tracks);
    
    printf("Enter the Disk_Requests : ");
    for(int i = 0 ; i < no_disk_requests ; i++){
        
        scanf("%d",&dreq[i]);
        
    }
    
    printf("Current head position : ");
    scanf("%d",&head);
    
    sstf();  
    
}
