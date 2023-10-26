#include<stdio.h>
int need[10][10],allocation[10][10],max[10][10];
int avail[10];
int np , nr ;

void readmatrix(int matrix[10][10]){
    for(int i = 0 ; i < np ;i++){
        for(int j = 0 ; j < nr ; j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    
}

void display_matrix(int matrix[10][10]){
    for(int i = 0 ; i < np ; i++){
        printf("\n");
        for(int j = 0 ; j < nr ; j++){
            printf("%d",matrix[i][j]);
        }
    }
    
}

void calculate_need(){
     for(int i = 0 ; i < np ; i++){
        for(int j = 0 ; j < nr ; j++){
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

void banker(){
    int finish[10],safe_seq[10];
    int flag,k=0;
    for(int i=0;i<np;i++){
        finish[i]=0;//declaring initially all processes as zero
    }
    
    for(int i = 0 ; i < np ;i++){
        flag = 0;
        if(finish[i]==0){
            for(int j=0;j<nr;j++){
                if(need[i][j]>avail[j]){
                    flag = 1 ;
                    break;
                }
            }
            if(flag==0){
                finish[i]=1;
                safe_seq[k] = i;
                k++;
                for(int j=0 ;j <nr;j++ ){
                    avail[j]+=allocation[i][j];
                }
                //start checking fron first process again
                i = -1;
            }
            
        }
    }
        flag=0;//check if all the processes are completed
        for(int i=0;i<np;i++){
            if(finish[i]==0){
                printf("\n deadlock\n");
                flag=1;
                break;
            }
        }
        if(flag==0){
            printf("safe sequence : \n");
            for(int i = 0 ; i < np ; i++){
                printf("P%d", safe_seq[i]);
            }
        }
    
    
}

int main(){
    
    printf("Enter number of Processes: ");
    scanf("%d",&np );
    printf("Enter number of Resources: ");
    scanf("%d",&nr );
    printf("Enter the allocation matrix: ");
    readmatrix(allocation);
    printf("Enter the max required Resources  : ");
    readmatrix(max);
    printf("Enter the max available resources  : ");
    for(int i=0;i<nr ;i++){
        scanf("%d",&avail[i]);
    }
    
    //displaying the data
    
    printf("***********Entered Date is************\n");
    printf("initial allocation:\n");
    display_matrix(allocation);
    printf("\n Maximum Requirement: ");
    display_matrix(max);
    printf("\n Available Resources: \n");
    for(int i = 0;i<nr ;i++){
        printf("%d",avail[i]);
    }
    
    //calculating and displaying need matrix
    calculate_need();
    printf("Need Matrix \n");
    display_matrix(need);
    
    banker();
    return 0 ;
    
}
