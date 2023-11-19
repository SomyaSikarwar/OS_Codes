#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>

int req ,tracks ,head ,head1;
int req_queue[20],finish[20];

void sstf(){
    
    int diff ,distance = 0,index = 0 ,pending ,min;
    pending = req ;
    head = head1;
    
    for(int i = 0 ; i< req ;i++){
        
        finish[i] = 0 ;
    }
    while(pending > 0){
        min = 999;
        for(int i = 0 ; i< req ; i++){
            diff = abs(head - req_queue[i]);
            if(finish[i] == 0 && diff< min){
                min = diff ;
                index = i ;
            }
        }
        finish[index] = 1 ;
        distance += abs(head - req_queue[index]);
        head = req_queue[index];
        pending--;
        printf("%d ,",head);
 
    }
    
    printf("Distance : %d" , distance);
}

void sort(){
    for(int i = 0 ; i< req ; i++){
        for(int j = 0 ; j< req ; j++){
            
            if(req_queue[i] < req_queue[j]){
                int temp = req_queue[i];
                req_queue[i] = req_queue[j];
                req_queue[j] = temp ;
            }
    }
    
}
}

void scan(){
    
    int index , dir , distance = 0;
    head = head1;
    printf("enter direction : ");
    scanf("%d",&dir);
    sort();
    int i = 0;
    while(head > req_queue[i]){
        index = i;
        i++;
    }
    
    printf("%d",index);
    printf("\n%d , ",head);
    
    
    if(dir == 1){
        sort();
        for(i = index+1 ; i < req ; i++){
            distance += abs(head - req_queue[i]);
            head = req_queue[i];
            printf("%d , " , head);
           
        }
        distance += abs(head - (tracks - 1));
        head = tracks -1 ;
        printf("%d , " , head );
        
        for(i = index ; i >=0 ; i--){
            distance += abs(head  - req_queue[i]);
            head = req_queue[i];
            printf("%d , " , head);
        }
    }
    
    else{
        sort();
        
        for(i = index ; i >=0 ; i--){
            distance += abs(head  - req_queue[i]);
            printf("%d ," , head);
            head = req_queue[i];
        }
        
        distance += abs(head - 0);
        head = 0 ;
        printf("%d" , 0 );
        
        for(i = index+1 ; i < req ; i++){
            distance += abs(head - req_queue[i]);
            head = req_queue[i];
            printf("%d ," , head);
           
        }
    }
    
    printf("Distance : %d : " , distance);
    
}


void c_look(){
    int index ,distance = 0,dir ;
    head = head1 ;
    
    printf("enter direction : ");
    scanf("%d",&dir);
    
    sort();
    
    int i = 0;
    while(head > req_queue[i]){
        index = i;
        i++;
    }
    
    printf("%d",index);
    printf("\n%d , ",head);
    
     if(dir == 1){
        sort();
        for(i = index+1 ; i < req ; i++){
            distance += abs(head - req_queue[i]);
            head = req_queue[i];
            printf("%d , " , head);
           
        }
        
         for(i = index ; i >= 0 ; i--){
            distance += abs(head - req_queue[i]);
            head = req_queue[i];
            printf("%d , " , head);
           
        }
     }
     
     else{
         
           sort();
         
          for(i = index ; i >= 0 ; i--){
            distance += abs(head - req_queue[i]);
            head = req_queue[i];
            printf("%d , " , head);
           
        }
      
        for(i = index+1 ; i < req ; i++){
            distance += abs(head - req_queue[i]);
            head = req_queue[i];
            printf("%d , " , head);
           
        }
         
     }
        
     
    printf("Distance : %d : " , distance);
    
}

int main(){
    printf("Number of disk requests : ");
    scanf("%d",&req);
    printf("Total number of tracks : ");
    scanf("%d",&tracks);
    printf("Current head position : ");
    scanf("%d",&head1);
    printf("Enter the Disk_Requests : ");
    for(int i = 0 ; i < req; i++){
        
        scanf("%d",&req_queue[i]);
        
    }
    
    for(int i = 0 ; i < req; i++){
        
        printf("%d ,",req_queue[i]);
        
    }
    
    printf("\n\n\n");
    
    printf("SSTF: \n\n");
    
    sstf();
     printf("\n\n\n");
    
    printf("SCAN :\n\n");
    scan();
    
     printf("\n\n\n");
    
    printf("C_LOOK :\n\n");
    c_look();
    
    
    
    
}
