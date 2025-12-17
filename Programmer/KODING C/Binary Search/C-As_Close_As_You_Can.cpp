#include <stdio.h>

int binarySearch(long long int val, int left, int right,long long int arr[]){
	if(val<arr[left]){
		return -1;
	}
	if(val>arr[right]){
		return right+1;
	}
	while (left <= right)
    {
        int mid = left + (right-left) / 2;

        if (val == arr[mid]){
            return mid+1;
        }
        else if (val > arr[mid]){
            if(val<arr[mid+1]){
            	return mid+1;
			}
			left=mid+1;
        }
        else if (val < arr[mid]){
            right = mid - 1;
        }
    }
}

int main() {
    
    int n;
    scanf("%d",&n);
    
    long long int arr[n];
    for(int i=0;i<n;i++){
    	scanf("%lld",&arr[i]);
	}
	
	long long int sum[n];
	for(int i=0;i<n;i++){
		if(i==0){
			sum[i]=arr[i];
		}
		else{
			sum[i]=sum[i-1]+arr[i];
		}
	}
	
	int tc;
	scanf("%d",&tc);
	
	for(int i=0;i<tc;i++){
		long long int m;
		scanf("%lld",&m);
		
		int index=binarySearch(m,0,n-1,sum);
		printf("Case #%d: %d\n",i+1,index);
	}

    return 0;
}
