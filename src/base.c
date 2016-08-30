#include<stdio.h>

void list0101(){
	int i;
	int a[5];
	for(i=0;i<5;i++){
		a[i] = i*i;
	}
	for(i=0;i<5;i++){
		printf("%d ",a[i]);
	}

}

struct DATA{
	char name[21];
	int price;
};

void B_PrintArray(struct DATA a[]){
	int i;
	printf("-- B_PrintArray\n");
	for(i=0;i<5;i++){
		printf("a[%d] ={%s,%d}\n",i, a[i].name,a[i].price);
	}
}

void list0104(){
	int i,j;
	struct DATA a[5]={
			{"apple", 100},
			{"orange", 80},
			{"melon", 200},
			{"banana", 120},
			{"grape", 150},
	};
	B_PrintArray(a);
	for(i=0;i<4;i++){
		for(j=j+1;j<5;j++){
			if(a[i].price > a[j].price){
				struct DATA t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	B_PrintArray(a);
}
