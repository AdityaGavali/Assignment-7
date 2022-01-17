#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int n,front=-1,rear=-1;

void enqueue();
void dequeue();
void display();

int main()
{
    printf("Enter Size of queue: ");
    scanf("%d",&n);
    int arr[10],temp=0;

    while(1)
    {
        printf("\nOPTION MENU");
        printf("\n\t1.Enqueue\n\t2.Dequeue\n\t3.Display\n\t0.Exit\n");
        int c;
        
        scanf("%d",&c);
    
        switch (c)
        {
            case 1:
                enqueue(arr);
                break;
            case 2:
                dequeue(arr);
                break;
            case 3:
                display(arr);
                break;
            case 0:
            printf("Thank You !");
                temp=1;
                return 0;
            
            default:
                break;
        }
    

    }
}


void enqueue(int arr[])
{
    if((rear+1)%n==front)
    {
        printf("\nQueue : Full\n");
        return;
    }
    printf("Enter Data: ");
    int data;
    scanf("%d",&data);
    
    if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
    }
    else
        rear=(rear+1)%n;
    
    arr[rear]=data;

    
}


void dequeue(int arr[])
{
    if(front==-1 && rear==-1)
    {
        printf("\nQueue : Empty\n");
        return;
    }
    if(front==rear)
    {
        front=-1;
        rear=-1;
        return;
    }

    front=(front+1)%n;

}

void display(int arr[])
{
    int i;
    if(front==-1 && rear==-1)
    {
        printf("\nQueue : Empty\n");
        return;
    }
    
    if (rear >= front)
    {
        for (i=front;i<= rear;i++)
            printf("%d ",arr[i]);
    }
    else
    {
        for (i=front;i<n;i++)
            printf("%d ",arr[i]);
 
        for (i=0;i<=rear;i++)
            printf("%d ",arr[i]);
    }
    printf("\n\n");
}