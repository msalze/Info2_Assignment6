#include<stdio.h>
#include<stdlib.h>



struct cell{
	int i;
	int j;
	int inhab; //1 if inhabited, 0 if not
	int col; //0 for not visited, 1 for visited but not all neighbors, 2 for visited and seen checked all neighbors
};

void init(struct cell m[5][5]){
	int i=0;
	int j=0;
	for (i=0;i<5;i++){
		for (j=0;j<5;j++){
			(m[i][j]).i=i;
			m[i][j].j=j;
			m[i][j].col=0;
			m[i][j].inhab =1;
		}
	}
}


struct cell m[5][5];

int countEcosystems(struct cell m[5][5]){// counts the number of independent systems
	int number=0;
	int i=0;
	int j=0;
	for (i=0; i<=4;i++){
		for (j=0; j<=4;j++){
			if (m[i][j].col == 0&&m[i][j].inhab==1){
				int temp = checkEcosystem(i,j);
				number = number+temp;
			}
		}
	}
	return number;
}

int checkEcosystem(i,j,struct cell m[5][5]){// tests if all neighbors of the ecosystem are not inhabited (if they exist) and returns 1 if it is an ecosystem
	if (m[i][j].inhab==0){
		return 1;
	}
	struct cell neighbor[8];
	int length =8;
	if (i-1<0&&j-1<0){
		struct cell neighbor[8]={m[i+1][j],m[i][j+1],m[i+1][j+1]};
		length = 3;
	}
	else if (i-1<0&&i+1>4){
		struct cell neighbor[8]={m[i][j-1],m[i+1][j-1],m[i+1][j]};
		length = 3;
	}
	else if (i+1>4&&i-1<0){
		struct cell neighbor[8]={m[i-1][j],m[i][j+1],m[i-1][j+1]};
		length = 3;
	}
	else if (i+1<0&&i+1<4){
		struct cell neighbor[8]={m[i-1][j],m[i-1][j-1],m[i][j-1]};
		length = 3;
	}
	
	else if (i-1<0){
		struct cell neighbor[8] = {m[i][j-1],m[i+1][j-1],m[i+1][j],m[i][j+1],m[i+1][j+1]};
		length = 6;
	}
	else if (j-1<0){
		struct cell neighbor[8]={m[i-1][j],m[i+1][j],m[i][j+1],m[i-1][j+1],m[i+1][j+1]};
		length = 6;
	}
	else if (i+1>4){
		struct cell neighbor[8]={m[i-1][j],m[i-1][j-1],m[i][j-1],m[i][j+1],m[i-1][j+1]};
		length = 6;
	}
	else if (j+1>4){
		struct cell neighbor[8]={m[i-1][j],m[i-1][j-1],m[i][j-1],m[i+1][j-1],m[i+1][j]};
		length = 6;
	}
	else{
		struct cell neighbor[8]={m[i-1][j],m[i-1][j-1],m[i][j-1],m[i+1][j-1],m[i+1][j],m[i][j+1],m[i-1][j+1],m[i+1][j+1]};
	}	
		int k=0;
		int isTrue=0;
		for (k=0;k<length;k++){
			if (neighbor[k].inhab == 0){
				return 1;
			}
			if ((neighbor[k]).col==0 && neighbor[k].inhab==1){
				neighbor[k].col=1;
				int i = neighbor[k].i;
				int j = neighbor[k].j;
				int isTrue = checkEcosystem(i,j, struct cell m);
				
			}
			
		}
	}

		
	
		
		
	


void main(){
	init(m);
	int result = countEcosystems(m);
}



















