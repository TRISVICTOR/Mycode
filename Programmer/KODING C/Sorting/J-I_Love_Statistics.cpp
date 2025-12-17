#include<stdio.h>

void merge(long long int arr[],long long int left,long long int mid,long long int right){
	long long int leftSize=mid-left+1;
	long long int rightSize=right-mid;
	long long int leftArr[leftSize];
	long long int rightArr[rightSize];
	
	for(int i=0;i<leftSize;i++){
		leftArr[i]=arr[left+i];
	}
	for(int i=0;i<rightSize;i++){
		rightArr[i]=arr[mid+1+i];
	}
	
	int leftIdx=0,rightIdx=0,Idx=left;
	while(leftIdx<leftSize && rightIdx<rightSize){
		if(leftArr[leftIdx]>rightArr[rightIdx]){
			arr[Idx]=rightArr[rightIdx];
			rightIdx++;
			Idx++;
		}
		else{
			arr[Idx]=leftArr[leftIdx];
			leftIdx++;
			Idx++;
		}
	}
	
	while(leftIdx<leftSize){
		arr[Idx]=leftArr[leftIdx];
		leftIdx++;
		Idx++;
	}
	while(rightIdx<rightSize){
		arr[Idx]=rightArr[rightIdx];
		rightIdx++;
		Idx++;
	}
}

void mergeSort(long long int arr[],int left,int right){
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
	scanf("%d",&tc);getchar();
	
	for(int i=0;i<tc;i++){
		int tc2;
		scanf("%d",&tc2);getchar();
		
		long long int arr[tc2];
		for(int j=0;j<tc2;j++){
			scanf("%lld",&arr[j]);getchar();
		}
		
		mergeSort(arr,0,tc2-1);
		
		long long int jumlah=0;
		for(int j=0;j<tc2;j++){
			jumlah+=arr[j];
		}
		
		double mean=(double)jumlah/tc2;
		double median;
		if(tc2%2==0){
			median=(arr[tc2/2-1]+arr[tc2/2])/2.0;
		}
		else{
			median=arr[tc2/2];
		}
		
		printf("Case #%d:\n",i+1);
		printf("Mean : %.2lf\n",mean);
		printf("Median : %.2lf\n",median);
	}
	
	return 0;
}
