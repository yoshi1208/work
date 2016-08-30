//初期化  リストを空にする。
//先頭 リストの先頭位置を決める。。
//次の要素   リストの次の要素を返す。
//要素数　リストの要素数を求める。
//要素値　リストの要素を返す。
//追加　リストの末尾に要素を追加する。
//挿入　リストの指定する位置に要素を挿入。
//削除　リストから要素を削除する。

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 30

typedef int LIST_A_ITEM;
typedef int LIST_A_POS;
#define LIST_A_TAIL -1

LIST_A_ITEM list[MAXSIZE];
LIST_A_POS tail;

struct LIST_P{
	int data;
	struct LIST_P *next;
};

#define NULL 0
struct LIST_P *top = NULL;

typedef int LIST_P_ITEM;
typedef struct LIST_P * LIST_P_POS;
#define LIST_P_TAIL NULL;


void Lt_AInit(){
	tail = 0;
}

LIST_A_POS Lt_ATop(void){
}

LIST_A_POS Lt_ANext(LIST_A_POS pos){
	if(pos<tail -1){
		return pos+1;
	}else{
		return LIST_A_TAIL;
	}
}

int Lt_ACount(void){
	return tail;
}

LIST_A_ITEM Lt_AItem(LIST_A_POS pos){
	if((pos>=0)&& (pos<tail)){
		return list[pos];
	}else{
		return 0;
	}
}

void Lt_AAdd(LIST_A_ITEM value){
	if(tail < MAXSIZE){
		list[tail] = value;
		tail++;
	}
}

void Lt_AInsert(LIST_A_POS pos,LIST_A_ITEM value){
	if((pos>=0) && (pos<tail) &&(tail<MAXSIZE)){
		int i;
		for(i=tail;i>pos;i--){
			list[i] = list[i-1];
		}
		list[pos]=value;
		tail++;
	}
}

void Lt_ADelete(LIST_A_POS pos){
	if((pos>=0)&& (pos<tail)){
		int i;
		for(i=pos;i<tail-1;i++){
			list[i] = list[i+1];
		}
		tail--;
	}
}

void list0201(){
	LIST_A_POS p;
	Lt_AInit();
	Lt_AAdd(1);
	Lt_AAdd(2);
	Lt_AAdd(3);

	printf("Count = %d\n",Lt_ACount());
	for(p=0 ; p!=LIST_A_TAIL ; p=Lt_ANext(p)){
		printf("%d ",Lt_AItem(p));
	}
	printf("\n");
}

