#include<stdio.h>
#include<stdlib.h>


int main() {
	int np, nr, max[10][10], allocation[10][10], need[10][10], available[10];
	int np_temp, order[10];
	
	for(int i=0;i<10; i++) {
		order[i] = -1;
		//printf("%d ", order[0]);
	}
	
	printf("\nenter number of processes : ");
	scanf("%d", &np);
	np_temp = np;
	
	printf("\nenter number types of resources : ");
	scanf("%d", &nr);
	
	printf("\nenter maximum matrix : \n");
	for(int i=0; i<np; i++)
		for(int j=0; j<nr; j++)
			scanf("%d", &max[i][j]);
		
	
	printf("\nenter allocation matrix : \n");
	for(int i=0; i<np; i++)
		for(int j=0; j<nr; j++)
			scanf("%d", &allocation[i][j]);
			
	for(int i=0; i<np; i++)
		for(int j=0; j<nr; j++)
			need[i][j] = max[i][j] - allocation[i][j];
	/*
	printf("\ncurrent state : \n");
	printf("p m a n\n");
	for(int i=0; i<np; i++) {
		printf("%d ", i);
		for(int j=0; j<nr; j++)
			printf("%d ", need[i][j]);   
		printf("\n");
	}
	*/
	printf("\nenter available resources\n");
	for(int i=0; i<nr; i++)
		scanf("%d", &available[i]);
		
	int pro = 0;
	int recent = 0; 
	int safestate = 1;
	
	while(np_temp) {
	
		int sufficient = 1;
		for(int j=0; j<nr; j++) {
			if(need[pro][j] > available[j]) {
				sufficient = 0;
				break;
			}
		}
		
		printf("\n----------------checking done---------\n");
		
		int not_executed = 1;
		for(int i=0; i<np; i++) {
			if(order[i] == pro) {
				not_executed = 0;
				break;
			}
		}
		
		printf("\n----------------checking done---------\n");
		
		if(sufficient && not_executed) {
			order[np - np_temp] = pro;
			for(int j=0; j<nr; j++) {
				available[j] += allocation[pro][j];
				need[pro][j] = 0;
				allocation[pro][j] = 0;
			}
			np_temp--;
			recent = pro;
		}
		
		pro = (pro+1)%np;
		
		if(np_temp == 0)
			break;
		
		if(pro == recent) {
			safestate = 0;
			break;
		}
		
	}
	
	
	if(!safestate) 
		printf("\n!............This is not in safestate ............ !\n");
	else {
		printf("\n....This is safestate....\n");
		printf("order of execution : ");
		for(int i=0; i<np; i++)
			printf(" %d  ", order[i]);
	}
	printf("\n");
}
