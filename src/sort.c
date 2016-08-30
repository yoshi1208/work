#include<stdio.h>

void PrintArray(int array[],int size){
	int i;
	for(i=0;i<size;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
}

void BubbleSort(int array[],int size){
	int i,j;
	for(i=0;i<size-1;i++){
		for(j=size-2;j>=i;j--){
			if(array[j]>array[j+1]){
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}

//if 文が無いのが特徴
void insetionSort(int array[],int size){
	int i,j;
	for(i=1;i<size;i++){
		int temp=array[i];
		for(j=i-1;j>=0 && array[j]>temp;j--){
			array[j+1]=array[j];
		}
		array[j+1]=temp;
	}
}

void ShellSort(int array[],int size){
	int i,j;
	int step = 1;
	while(step <size){
		step =step * 3 +1;
	}
	step /=3;

	while(step >0){
		for(i=step;i<size;i++){
			int temp = array[i];
			for(j=i-step;j>=0 && array[j] >temp ;j=j-step ){
				array[j+step] = array[j];
			}
			array[j+step] =temp;
		}
		step /=3;
	}
}

void QuickSort(int array[],int left,int right){
	int left0 = left,right0 = right;
	int pivot;
	if(left>=right) return;

	//ピボット値を求める。
	pivot = (array[left] + array[(left + right)/2]+array[right]) / 3;

	//グルーピング
	while(1){
		int temp;

		//right left側の交換要素を求める。
		while(array[left] <pivot ) left++;
		while(array[right]> pivot) right--;


		if(left>=right) break;
		temp=array[left];
		array[left] =array[right];
		array[right]=temp;
		left++;
		right--;
	}
	QuickSort(array,left0,left-1);
	QuickSort(array,right+1,right0);
}



int list0601(){
	int dataA[] = {5,2,6,1,4,3};
	int dataB[] = {5,6,2,9,1,4};
	int dataC[] = {2,9,7,8,5,4};
	int dataD[] = {5,2,6,1,4,3};

	printf("Bubble   :");
	BubbleSort(dataA,6);
	PrintArray(dataA,6);

	printf("Insertion:");
	insetionSort(dataB,6);
	PrintArray(dataB,6);

	printf("Shell    :");
	ShellSort(dataC,6);
	PrintArray(dataC,6);


	printf("Quick    :");
	QuickSort(dataD,0,5);
	PrintArray(dataD,6);

}
