#include<stdio.h>
#include<stdlib.h>

int m[50][50];

void init(){
	int i=0;
	int j=0;
	for (i;i<50;i++){
		j=0;
		for (j; j<501; j++){
			m[i][j]=-1;		
		}
	}
}

void print(int n, int capacity){
	int i=0;
	int j=0;
	for (i;i<n;i++){
		j=0;
		for (j; j<capacity; j++){
			printf("%d  ",m[i][j]);		
		}
		printf("\n");
	}
}

int knapsackRec(int capacity, int mass[], int profit[], int n){
	if (capacity <= 0 ||n<0){return 0;}
	if (mass[n]<=capacity){
		int new_capacity = capacity-mass[n];
		int take = profit[n]+knapsackRec(new_capacity, mass, profit, n-1);
		int leave = knapsackRec(capacity, mass, profit, n-1);
		if (take<leave){return leave;}
		else{return take;}
	}
	else{
		return knapsackRec(capacity, mass, profit, n-1);
	}
}

int knapsackMemoized(int capacity, int mass[], int profit[], int n, int m[n][capacity]){
	if (m[n][capacity]>=0){
		return (m[n][capacity]);
	}
	if (capacity <= 0 || n<0){
		m[n][capacity]=0;
		return 0;}
	if (mass[n]<=capacity){
		int new_capacity = capacity-mass[n];
		int take = profit[n]+knapsackMemoized(new_capacity, mass, profit, n-1,m);
		int leave = knapsackMemoized(capacity, mass, profit, n-1, m);
		if (take<leave){
			m[n][capacity]=leave;
			return leave;
		}
		else{
			m[n][capacity]=take;
			return take;
		}
	}
	else{
		return knapsackMemoized(capacity, mass, profit, n-1,m);
	}
}


int knapsackDynamic(int capacity, int mass[], int profit[], int n, int m[n][capacity]){
	int i = 0;
	int j = 0;
	for (i=0; i<=n; i++){
		j=0;
		for (j=0; j<=capacity; j++){
			
			if (j == 0){
				m[i][j]=0;
			}
			else if (mass[i]<=j){
				int new_capacity = j - mass[i];
				int take = profit[i] + m[i-1][new_capacity];
				int leave = m[i-1][j];
				if (take<leave){
					m[i][j]=leave;
				}
				else{
					m[i][j]=take;
				}
			}
			if (mass[i]>j){
				m[i][j]=m[i-1][j];
			}
			
		
		}
	}
	return m[n][capacity];
}

void main(){
	int mass[10] ={2,4,3,2};
	int profit[10] = {45,40,25,15};
	int n=4;
	int capacity = 5;
	/*
	int max_rec = knapsackRec(capacity, mass,profit,n);
	printf("max_rec=%d\n",max_rec);
	
	
	init();
	int max_memo=knapsackMemoized(capacity,mass,profit,n,m);
	printf("max_memo=%d\n",max_memo);
	*/
	init();
	print(4,5);
	int max_dyn=knapsackDynamic(capacity,mass,profit,n,m);
	printf("max_dyn=%d\n",max_dyn);
	print(4,5);
}
