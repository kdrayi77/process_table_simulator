#include<stdio.h>
#include<stdlib.h>
#define SIZE 50
typedef struct{
	int id;
	char pName[20];
	int priority;
	float BT;
}Process;
int count=0;
void Add(Process table[],int n){
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
void Display(Process table[],int n){
	int i;
	for(i=0;i<count;i++)
	{
	printf("\nprocess-%d ",i+1);
	printf("Pid=%d\tPname=%s\tpriority=%d\tBT=%f\n",
	table[i].id,table[i].pName,table[i].priority,table[i].BT);
    }
}
void BubbleSortByPriority(Process table[],int n){
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
void InsertionSortByPid(Process table[],int n){
	int i,j,key;
	for(i=1;i<count;i++)
	{
	    key=table[i].id;
	    j=i-1;
	    while(j>=0 && table[j].id>key)
	    {
	        table[j+1].id=table[j].id;
	        j--;
	    }
	    table[j+1].id=key;
	}
}
void shellSortByBT(Process table[],int n){
	int gap,i,j,key;
	for(gap=count/2;gap>0;gap=gap/2)
	{
	    for(i=gap;i<count;i++)
	    {
	        key=table[i].id;
	        j=i;
	        while(j>=gap && table[j-gap].id>key)
	        {
	            table[j].id=table[j-gap].id;
	            j=j-gap;
	        }
	        table[j].id=key;
	    }
	}
}
void linearSearchByPid(Process table[],int n){
    int key,i,flag=0;
    printf("Enter the id to search\n");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(key==table[i].id)
        {
            flag++;
            break;
        }
        
    }
    if(flag==1)
    {
        printf("The id is found at %dth position of",i);
        
    }
    else
   {
        printf("The id is not found\n");
   }
}
void BinarySearchByPid(Process table[],int n){
    int low=0,mid,high=count;
    int key;
    printf("Enter the id to search\n");
    scanf("%d",&key);
    while(low<=count){
        mid=(low+count)/2;
        if(table[mid].id==key){
            printf("The key is found at %d position of id",mid);
            break;
        }
        if(key<table[mid].id)
        {
            high=mid-1;
        }
        else if(key>table[mid].id)
        {
            low=mid+1;
        }
    }
}
 int main(){
 Process table[SIZE];
	while(1){
	printf("1.Add\n2.Display\n3.BubbleSortByPriority\n4.InsertionSortByPid\n5.shellSortByBT\n6.linearSearchByPid\n7.BinarysearchByPid\n8.exit\n");
	int choice;
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice){
    	case 1:Add(table,SIZE);break;
    	case 2:Display(table,SIZE);break;
    	case 3:BubbleSortByPriority(table,SIZE);break;
    	case 4:InsertionSortByPid(table,SIZE);break;
    	case 5:shellSortByBT(table,SIZE);break;
    	case 6:linearSearchByPid(table,SIZE);break;
    	case 7:printf("come here after sorting\n");
		       BinarySearchByPid(table,SIZE);break;
	    case 8:exit(0);break;	
	}
	}
}
