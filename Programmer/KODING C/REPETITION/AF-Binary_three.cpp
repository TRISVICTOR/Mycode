#include <stdio.h>

int countOnBits(int n){
    int count = 0;
    while(n){
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main(){
	
    int tc;    
    scanf("%d", &tc); getchar();
	int n, a[100];
    for(int i = 0; i < tc; i++){
        scanf("%d", &n); getchar();
        for(int j = 0; j < n; j++){
            scanf("%d", &a[j]); getchar();
        }

        int on = 0, off = 0;

        for(int k = 0; k < n; k++) {
            for (int l = k + 1; l < n; l++) {
                int xorResult = a[k] ^ a[l];
                if (countOnBits(xorResult) >= 3) {
                    on++;
                } else {
                    off++;
                }
            }
        }
        printf("Case #%d: %d %d\n", i + 1, on, off);
    }

    return 0;
}
