#include<stdio.h>
#include<stdlib.h>

int* m[50][501];

void init(){
	int i=0;
	int j=0;
	for (i;i<50;i++){
		for (j; j<501; j++){
			m[i][j]=-1;			
		}
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

int knapsackMemoized(int capacity, int mass[], int profit[], int n){
	
	if (m[n][capacity]!=-1){
		return *(m[n][capacity]);
	}
	printf("yey\n");
	if (capacity <= 0 ||n<0){
		m[n][capacity]=0;
		return 0;}
	if (mass[n]<=capacity){
		int new_capacity = capacity-mass[n];
		int take = profit[n]+knapsackRec(new_capacity, mass, profit, n-1);
		int leave = knapsackRec(capacity, mass, profit, n-1);
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
		return knapsackRec(capacity, mass, profit, n-1);
	}
}


int knapsackDynamic(int capacity, int mass[], int profit[], int n){
	
	
}

void main(){
	int mass[10] ={2,4,3,2};
	int profit[10] = {45,40,25,15};
	int n=4;
	int capacity = 5;
	/*
	int max_rec = knapsackRec(capacity, mass,profit,n);
	printf("max_rec=%d\n",max_rec);*/
	
	init();
	int max_memo=knapsackMemoized(capacity,mass,profit,n);
	printf("max_memo=%d",max_memo);
}
