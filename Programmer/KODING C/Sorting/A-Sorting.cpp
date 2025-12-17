#include<stdio.h>
#include <limits.h>

void merge(long long int arr[],long long int left,long long int mid,long long int right){
	long long int i = left;
	long long int j = mid + 1;
	long long int k = 0;
	
	long int temp[right - left + 1];
	while(i <= mid && j <= right){
		if(arr[i] < arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
		}
	}
	while(i <= mid){
		temp[k++] = arr[i++];
	}
	while(j <= right){
		temp[k++] = arr[j++];
	}
	int index = 0;
	for(int p = left; p <= right; p++){
		arr[p] = temp[index++];
	}
}

void mergeSort(long long int arr[],long long int left,long long int right){
	if(left < right){
		long long int mid = (right + left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	} 
}

int main(){
	
	int tc;
	scanf("%d",&tc);getchar();
	
	long long int arr[tc];
	
	for(int i=0;i<tc;i++){
		scanf("%lld",&arr[i]);getchar();
	}
	
	mergeSort(arr, 0, tc - 1);
	
//	int selisih;
//	int besar=0;
//	int banding;
//	bool tanda=false;
//	
//	for(int i=0;i<tc-1;i++){
//		selisih=arr[i]-arr[i+1];
//		if(selisih<0){
//			selisih*=-1;
//		}
//		if(selisih>besar){
//			besar=selisih;
//		}
//	}
//	
//	for(int i=0;i<tc-1;i++){
//		banding=arr[i]-arr[i+1];
//		if(banding<0){
//			banding*=-1;
//		}
//		if(banding==besar){
//			if(!tanda){
//				printf("%d %d",arr[i],arr[i+1]);
//				tanda=true;
//			}
//			else{
//				printf(" %d %d",arr[i],arr[i+1]);
//			}
//		}
//	}
	long long int diff[tc - 1];
	
	for(int i = 0; i < tc - 1; i++){
		diff[i] = arr[i+1] - arr[i];
	}
	
	long long int max = LLONG_MIN;
	
	for(int i = 0; i < tc - 1; i++){
		if(diff[i] > max){
			max = diff[i];
		}
	}
	
	int j = 1;
	
	for(int i = 0; i < tc-1; i++){
		if(arr[i + 1] - arr[i] == max){
			if(!(j)){
				printf(" ");
			}
			j = 0;
			printf("%lld %lld", arr[i], arr[i + 1]);
		}
	}

	printf("\n");
	
	return 0;
}
