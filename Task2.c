#include<stdio.h>
#include<stdlib.h>

int m[50][50][50];

int trade(int n, int k, int price[]){
	int i = 0;
	int j = 0;
	int status = 0; //0 if not bought, 1 if has object
	for (i;i<n;i++){
		for (j=0;j<k){
			if (i==0 || j==0){
				m[i][j]=0;
			}
			if (j>2*i-1){
				m[i][j]=m[i][j-1];
			}
			else{
				int trade=0;
				int dont=m[i][j-1];
				if (status == 0){
					trade = 
				}
			}
			
		}
	}
	return m[n][k];
}


void main(){
	
}
