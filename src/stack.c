#include <stdio.h>
typedef int STACK_ITEM;
typedef int PntSTACK_ITEM;

#define STACK_SIZE 30

STACK_ITEM stack[STACK_SIZE];

struct PntSTACK {
	PntSTACK_ITEM data;
	struct PntSTACK *next;
};

#define NULL 0

struct PntSTACK *spp = NULL;

int sp = 0;

void AryStck_Init() {
	sp = 0;
}

int AryStck_IsEmpty() {
	if (sp == 0) {
		return 1;
	} else {
		return 0;
	}
}

void AryStck_Push(STACK_ITEM data) {
	if (sp < STACK_SIZE) {
		stack[sp] = data;
		sp++;
	}
}

STACK_ITEM AryStck_Pop() {
	if (sp > 0) {
		sp--;
		return stack[sp];
	} else {
		return 0;
	}
}

void list0401() {
	AryStck_Init();
	AryStck_Push(1);
	AryStck_Push(2);
	AryStck_Push(3);
	while (!AryStck_IsEmpty()) {
		int data;
		data = AryStck_Pop();
		printf("%d", data);
	}
	AryStck_Pop();
	printf("\n");

}

void PntStck_Init() {
	while (sp != NULL) {
		struct PntSTACK *delete_item;
		delete_item = spp;
		spp = spp->next;
		free(delete_item);
	}
}

int PntStck_IsEmpty() {
	return (spp == NULL);
}

void PntStck_Push(PntSTACK_ITEM data) {
	struct PntSTACK *new_item;
	new_item = (struct PntSTACK *) malloc(sizeof(struct PntSTACK));
	new_item->data = data;
	new_item->next = spp;
	spp = new_item;
}

STACK_ITEM PntStck_Pop() {
	PntSTACK_ITEM data;
	if (spp != NULL) {
		struct PntSTACK *delete_item;
		data = spp->data;
		delete_item = spp;
		spp = spp->next;
		free(delete_item);
	} else {
		data = 0;
	}
	return data;
}

void list0402() {
	PntStck_Init();
	PntStck_Push(1);
	PntStck_Push(2);
	PntStck_Push(3);
	while (!PntStck_IsEmpty()) {
		int data;
		data = PntStck_Pop();
		printf("%d", data);
	}
	printf("\n");

}
