#include<stdio.h>
int front,rear,n,msg=0;
void createq(int q[]){
	printf("Enter the size of queue : ");
	scanf("%d",&n);
	n--;
	msg=1;
	front = 0;
	rear = 0;
	q[0]=0;
}
void enqueue(int q[],int i){
	if((rear%n)==((front%n)-1)){
		msg=2;
	}else{
		q[(rear%n)+1]=i;
		rear=rear%n+1;
		if(front==0){
			front++;
		}
	}
}
void dequeue(int q[]){
	if(front==rear){
		front=0;
		rear=0;
	}else if(front!=0){
		front=front%n+1;
	}
}
void Front(int q[]){
	msg=4;
}
void isempty(int q[]){
	if(front==0){
		msg=5;
	}else{
		msg=6;
	}
}
void full(int q[]){
	if((rear%n)==((front%n)-1)){
		msg=2;
	}else{
		msg=7;
	}
}
void disp(int q[]){
        switch(msg){
                case 0:break;
                case 1: printf(" - Queue is created ,size=%d",n+1);
                        break;
                case 2: printf(" - Queue is full!");
                        break;
		case 3: printf(" - Not a valid option!");
			break;
		case 4: printf(" - front = %d, value = %d",front,q[front]);
			break;
		case 5: printf(" - Queue is empty");
			break;
		case 6: printf(" - Queue is not empty");
			break;
		case 7: printf(" - Queue is not full");
			break;
        }
} 
void print(int q[]){
	if(front==0){
		printf("Queue is empty!");
	}else{
		for(int i=front;i!=rear;(i=i%n+1)){
			printf("%d  ",q[i]);
		}
		printf("%d ",q[rear]);
	}
	disp(q);
	msg=0;
}
void main(){
	int q[100],i;
	int op;
	do{
		printf("\033[2J\033[1;1H***C I R C U L A R	Q U E U E***\n");
		printf("1: Createq(q)\n");
		printf("2: enqueue(q,i)\n");
		printf("3: dequeue(q)\n");
		printf("4: front(q)\n");
		printf("5: isempty(q)\n");
		printf("6: full(q)\n");
		printf("0: EXIT\n");
		print(q);
		printf("\nChoose one option (0-6) : ");
		scanf("%d",&op);
		switch(op){
			case 1: createq(q);
				break;
			case 2: printf("Enter value to insert : ");
				scanf("%d",&i);
				enqueue(q,i);
				break;
			case 3: dequeue(q);
				break;
			case 4: Front(q);
				break;
			case 5: isempty(q);
				break;
			case 6: full(q);
				break;
			case 0: printf("Exiting....\n");
				break;
			default:msg=3;
		}
	}while(op!=0);
}
