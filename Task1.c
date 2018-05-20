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
	init();
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


int knapsackDynamic(int capacity, int mass[], int profit[], int n){
	init();
	int i = 0;
	int j = 0;
	for (i=0; i<n; i++){
		for (j=0; j<=capacity; j++){
			if (j == 0){
				m[i][j]=0;
			}
			else if (mass[i]<=j){
				int new_capacity = j - mass[i];
				int take = profit[i] + m[i-1][new_capacity];
				int leave=0;
				if (i>0){
					leave = m[i-1][j];
				}
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
	/*
	int mass[10] ={2,4,3,2};
	int profit[10] = {45,40,25,15};
	int n=4;
	int capacity = 5;
	
	int max_rec = knapsackRec(capacity, mass,profit,n);
	printf("max_rec=%d\n",max_rec);
	
	
	init();
	int max_memo=knapsackMemoized(capacity,mass,profit,n,m);
	printf("max_memo=%d\n",max_memo);
	
	init();
	print(4,5);
	int max_dyn=knapsackDynamic(capacity,mass,profit,n,m);
	printf("max_dyn=%d\n",max_dyn);
	print(4,5);
	*/
	
	time_t t;
	srand((unsigned) time(&t));
	//create the knapsacks
	int mass1[4] = {6,3,2,4};
	int profit1[4] = {50,60,40,20};
	int n1 = 4;
	int capacity1 = 10;
	
	int mass2[10] = {23,31,29,44,53,58,63,85,89,82};
	int profit2[10] = {92,57,49,68,60,43,67,84,87,72};
	int n2 = 10;
	int capacity2 = 165;
	
	int mass3[50];
	int i=0;
	for(i = 0;i<50;i++){
		mass3[i] = rand() % 100 + 1;
	}
	int profit3[50];
	for(i = 0;i<50;i++){
		profit3[i] = rand() % 100 + 1;
	}
	int n3 = 50;
	int capacity3 = 500;
	// A) Recursive
	printf("Recursive Way:\n");
	
	int profitRecursive1 = knapsackRec(capacity1, mass1, profit1, n1-1);
	printf("max profit 1: %d\n",profitRecursive1);
	
	int profitRecursive2 = knapsackRec(capacity2, mass2, profit2, n2-1);
	printf("max profit 2: %d\n",profitRecursive2);
	
	// B) Memoized	
	printf("Memoized Way:\n");
	
	init();
	int profitMemoized1 = knapsackMemoized(capacity1,mass1,profit1,n1,m);
	printf("max profit: %d\n",profitMemoized1);
	
	init();
	int profitMemoized2 = knapsackMemoized(capacity2,mass2,profit2,n2,m);
	printf("max profit: %d\n",profitMemoized2);
	
	init();
	int profitMemoized3 = knapsackMemoized(capacity3,mass3,profit3,n3,m);
	printf("max profit: %d\n",profitMemoized3);
// C) Dynamic	
	printf("Dynamic Way:\n");
	
	init();
	int profitDynamic1 = knapsackDynamic(capacity1,mass1,profit1,n1);
	printf("max profit: %d\n",profitDynamic1);
	
	init();
	int profitDynamic2 = knapsackDynamic(capacity2,mass2,profit2,n2);
	printf("max profit: %d\n",profitDynamic2);
	
	init();
	int profitDynamic3 = knapsackDynamic(capacity3,mass3,profit3,n3);
	printf("max profit: %d\n",profitDynamic3);
	
}
