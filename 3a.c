#define SIZE 10
#include<stdio.h>
struct Queue{
    int data [SIZE];
    int front ,rear ;
}Q;//for creating queue names Q
int isEmpty(){
    return Q.front==-1;
}
int isFull(){
    return Q.rear==SIZE-1;
}
void enqueue(int info){
    if(Q.rear=SIZE-1){
        printf("overflow");
        return ;
    }
    if(Q.front==-1){
        Q.front =0;
    }
    Q.rear=Q.rear+1;
    Q.data[Q.rear]=info;
}
int dequeue(){
    int item ;
    if(Q.front ==-1){
        printf("Empty");
        return-1;
    }
    item=Q.data[Q.front];
    if(Q.front ==Q.rear){
        Q.front=Q.rear=-1;
    }
        else{
    Q.front++;
    return item ;
        }
    }
   void traverse()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }
    for (int i = Q.front; i <= Q.rear; i++)
    {
        printf("%d ", Q.data[i]);
    }
    printf("\n");
}
int main()
{
    Q.front = Q.rear = -1;
    int ch, info;
    do
    {
        printf("\n1.........Enqueue"
               "\n2.........Dequeue"
               "\n3.........Traverse"
               "\n4.........IsEmpty"
               "\n5.........IsFull"
               "\n6.........Exit"
               "\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter info: ");
            scanf("%d", &info);
            enqueue(info);
            break;
        case 2:
            info = dequeue();
            if (info != -1)
                printf("Removed Element: %d", info);
            break;
        case 3:
            traverse();
            break;
        case 4:
            printf("The queue is %s\n", (isEmpty() == 1 ? "Empty" : "Not Empty"));
            break;
        case 6:
            printf("\nThis code is executed by Mr. XYZ with Roll No XXXXXX\n");
            break;
        case 7:
            printf("This code is executed by : Shreya Goel and Roll NO.2400320101071");
            break;
        default:
            printf("Invalid Choice! Try again\n");
        }
    } while (ch != 6);
}