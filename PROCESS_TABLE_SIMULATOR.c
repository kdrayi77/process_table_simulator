#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int id;
	char pName[20];
	int priority;
	float BT;
}Process;
int count=0;
Process table[50];
void Add(){
	printf("Enter process-%d details\n",count+1);
	printf("Enter Pid\n");
	scanf("%d",&table[count].id);
	printf("Enter process name\n");
	scanf("%s",table[count].pName);
	printf("Enter priority\n");
	scanf("%d",&table[count].priority);
	printf("Enter BT\n");
	scanf("%f",&table[count].BT);
	count++;
}
void Display(){
	int i;
	for(i=0;i<=count;i++)
	{
	printf("\nprocess-%d ",i+1);
	printf("Pid=%d\tPname=%s\tpriority=%d\tBT=%f\n",
	table[i].id,table[i].pName,table[i].priority,table[i].BT);
    }
}
void BubbleSortByPriority(){
	int i,j;
	for(i=0;i<count;i++)
	{
		for(j=0;j<count-i-1;j++)
		{
			if(table[j].priority>table[j+1].priority)
			{
				int temp=table[j].priority;
				table[j].priority=table[j+1].priority;
				table[j+1].priority=temp;
			}
		}
	}
	
	
}
void InsertionSortByPid(){
	
}
void shellSortByBT(){
	
}
void linearSearchByPid(){
	
}
void BinarySearchByPid(){
	
}
main(){
 
	while(1){
	printf("1.Add\n2.Display\n3.BubbleSortByPriority\n4.InsertionSortByPid\n5.shellSortByBT\n6.linearSearchByPid\n7.BinarysearchByPid\n8.exit\n");
	int choice;
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice){
    	case 1:Add();break;
    	case 2:Display();break;
    	case 3:BubbleSortByPriority();break;
    	case 4:InsertionSortByPid();break;
    	case 5:shellSortByBT();break;
    	case 6:linearSearchByPid();break;
    	case 7:printf("come here after sorting");
		       BinarySearchByPid();break;
	    case 8:exit(0);break;	
	}
}
    
	
}
