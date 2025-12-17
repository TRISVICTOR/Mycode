#include<stdio.h>

void merge(int arr[],int left,int mid,int right){
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
			idx++;
			rightIdx++;
		}
		else{
			arr[idx]=leftArr[leftIdx];
			idx++;
			leftIdx++;
		}
	}
	
	while(leftIdx<leftSize){
		arr[idx]=leftArr[leftIdx];
		leftIdx++;
		idx++;
	}
	
	while(rightIdx<rightSize){
		arr[idx]=rightArr[rightIdx];
		idx++;
		rightIdx++;
	}
}

void mergeSort(int arr[],int left,int right){
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
	
	int arr[25];
	int Y1,Y2,Y3,Y4,Y5;
	
	for(int i=0;i<tc;i++){
		for(int j=0;j<25;j++){
			scanf("%d",&arr[j]);
		}
		
		printf("Case #%d: ",i+1);
		
		mergeSort(arr,0,24);
		
		Y1=arr[0]/2;
		Y2=arr[1]-Y1;
		Y3=arr[4]-Y1;
		Y5=arr[24]/2;
		Y4=arr[23]-Y5;
		
		printf("%d %d %d %d %d\n",Y1,Y2,Y3,Y4,Y5);
	}
	
	return 0;
}
