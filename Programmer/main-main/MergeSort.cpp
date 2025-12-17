#include<stdio.h>
//5 7 2 3 9
void merge(int arr[],int left, int mid, int right){
	int leftSize=mid-left+1;
	int rightSize=right-mid;
	int leftArr[leftSize],rightArr[rightSize];
	
	for(int i=0;i<leftSize;i++){
		leftArr[i]=arr[left+i];
	}
	
	for(int i=0;i<rightSize;i++){
		rightArr[i]=arr[mid+1+i];
	}
	
	int leftIdx=0,rightIdx=0,idx=left;
	while(leftIdx<leftSize && rightIdx<rightSize){
		if(leftArr[leftIdx]>rightArr[rightIdx]){
			arr[idx]=rightArr[rightIdx];
			rightIdx++;
			idx++;
		}
		else{
			arr[idx]=leftArr[leftIdx];
			leftIdx++;
			idx++;
		}
	}
	
	while(leftIdx<leftSize){
		arr[idx]=leftArr[leftIdx];
		idx++;
		leftIdx++;
	}
	while(rightIdx<rightSize){
		arr[idx]=rightArr[rightIdx];
		idx++;
		rightIdx++;
	}
}
//6 32 9 1 3
void mergeSort(int arr[],int left, int right){
	if(left>=right){
		return;
	}
	
	int mid=(left+right)/2;
	
	mergeSort(arr,left,mid);
	mergeSort(arr,mid+1,right);
	merge(arr,left,mid,right);
}

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	int arr[tc];
	
	for(int i=0;i<tc;i++){
		scanf("%d",&arr[i]);
	}
	
	mergeSort(arr,0,tc-1);
	
	for(int i=0;i<tc;i++){
		printf("%d ",arr[i]);
	}
	
	printf("\n");
	
	return 0;
}
