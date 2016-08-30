#include <stdio.h>
#include <stdlib.h>

typedef int A_QUEUE_ITEM;
typedef int P_QUEUE_ITEM;

#define A_QUEUE_SIZE 30
#define NULL 0

A_QUEUE_ITEM a_queue[A_QUEUE_SIZE];

int a_queue_end = 0;

struct P_QUEUE{
	P_QUEUE_ITEM data;
	struct P_QUEUE *next;
};

struct P_QUEUE *p_top = NULL;
struct P_QUEUE *p_bottom = NULL;

void A_InitQueue(){
	a_queue_end = 0;
}

int A_IsEmpty(void){
	return(a_queue_end==0);
}

void A_Enqueue(A_QUEUE_ITEM data){
	if(a_queue_end <A_QUEUE_SIZE){
		a_queue[a_queue_end]=data;
		a_queue_end++;
	}
}

A_QUEUE_ITEM A_Dequeue(void){
	if(a_queue_end > 0){
		int i;
		A_QUEUE_ITEM data;
		data = a_queue[0];
		for(i=0;i<a_queue_end -1;i++){
			a_queue[i] = a_queue[i + 1];
		}
		a_queue_end--;
		return data;
	}else{
		return 0;
	}
}

int list0403(){
	A_InitQueue();
	A_Enqueue(1);
	A_Enqueue(2);
	A_Enqueue(3);
	while(!A_IsEmpty()){
		int data;
		data = A_Dequeue();
		printf("%d ",data);
	}
	printf("\n");
	return 0;
}

void P_InitQueue(){
	while(p_top !=NULL){
		struct P_QUEUE *delete_item;
		delete_item = p_top;
		p_top =p_top->next;
		free(delete_item);
	}
	p_bottom = NULL;
}

int P_IsEmpty(void){
	return (p_top==NULL);
}

void P_Enqueue(P_QUEUE_ITEM data){
	struct P_QUEUE *new_item;
	new_item=(struct P_QUEUE *)malloc(sizeof(struct P_QUEUE));
	new_item->data =data;
	new_item->next =NULL;
	if(p_top==NULL){
		p_top =p_bottom =new_item;
	}else{
		p_bottom->next =new_item;
		p_bottom = p_bottom->next;
	}
}

P_QUEUE_ITEM P_Dequeue(void){
	P_QUEUE_ITEM data;
	struct QUEUE *delete_item;
	data = p_top->data;
	delete_item = p_top;
	p_top = p_top->next;
	if(p_top==NULL){
		p_bottom = NULL;
	}

	free(delete_item);
	return data;
}

void list0404(){
	P_InitQueue();
	P_Enqueue(1);
	P_Enqueue(2);
	P_Enqueue(3);
	while(!P_IsEmpty()){
		int data;
		data =P_Dequeue();
		printf("%d",data);
	}
	printf("\n");
}
