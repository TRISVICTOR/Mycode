//#include<stdio.h>
//
//void merge(int arr[],int left,int mid,int right){
//	int leftSize=mid-left+1;
//	int rightSize=right-mid;
//	int leftArr[leftSize],rightArr[rightSize];
//	
//	for(int i=0;i<leftSize;i++){
//		leftArr[i]=arr[left+i];
//	}
//	for(int i=0;i<rightSize;i++){
//		rightArr[i]=arr[mid+1+i];
//	}
//	
//	int leftIdx=0,rightIdx=0,Idx=left;
//	while(leftIdx<leftSize && rightIdx<rightSize){
//		if(leftArr[leftIdx]<rightArr[rightIdx]){
//			arr[Idx]=rightArr[rightIdx];
//			Idx++;
//			rightIdx++;
//		}
//		else{
//			arr[Idx]=leftArr[leftIdx];
//			Idx++;
//			leftIdx++;
//		}
//	}
//	
//	while(leftIdx<leftSize){
//		arr[Idx]=leftArr[leftIdx];
//		Idx++;
//		leftIdx++;
//	}
//	while(rightIdx<rightSize){
//		arr[Idx]=rightArr[rightIdx];
//		Idx++;
//		rightIdx++;
//	}
//}
//
//void mergeSort(int arr[],int left,int right){
//	if(left>=right){
//		return;
//	}
//	
//	int mid=(right+left)/2;
//	
//	mergeSort(arr,left,mid);
//	mergeSort(arr,mid+1,right);
//	merge(arr,left,mid,right);
//}
//
//int main(){
//	
//	int tc;
//	scanf("%d",&tc);
//	
//	for(int i=0;i<tc;i++){
//		int a;
//		scanf("%d",&a);
//		
//		int arr[a];
//		for(int j=0;j<a;j++){
//			scanf("%d",&arr[j]);
//		}
//		
//		mergeSort(arr,0,a-1);
//		
//		for(int j=0;j<a;j++){
//			printf("%d ",arr[j]);
//		}
//		printf("\n");
//	}
//	
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int linear_search(int arr[], int n, int target){
//	for(int i = 0; i<n; i++){
//		if(arr[i] == target){
//			return i;
//		}
//	}
//	return -1;
//}
//
//int main(){
//	int arr[] = {5,3,2,1,4};
//	
//	int n = sizeof(arr)/sizeof(arr[0]);
//	
//	for(int i=0;i<n;i++){
//		printf("%d ",arr[i]);
//	}
//	printf("\n");
//	
//	int target;
//	scanf("%d",&target);
//	
//	int idx = linear_search(arr, n, target);
//	
//	printf("Found at index %d\n", idx + 1);
//	
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int binary_search(int arr[], int n, int target){
//	int left = 0;
//	int right = n-1;
//	
//	while(left <= right){
//		int mid = (left + right)/2;
//		if(arr[mid] == target){
//			return mid;
//		}
//		else if (arr[mid] > target){
//			right = mid - 1;
//			
//		}
//		else{
//			left = mid + 1;
//		}
//	}
//	
//	return -1;
//}
//int main(){
//	
//	int arr[] = {1,2,3,4,5};
//	
//	int n = sizeof(arr)/sizeof(arr[0]);
//	
//	int idx = binary_search(arr, n, 2);
//	
//	printf("Found at index %d\n", idx + 1);
//	
//	return 0;
//	
//}
