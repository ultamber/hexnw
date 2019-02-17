#include <stdio.h>
void printtable(char **table,int size){
	int i,j,size,tab=1;
	scanf("%d",&size );
	printf("    ");
	for(i=0;i<size;i++) printf("_   ");
	printf("\n   / ");
	for(i=0;i<size-1;i++) printf("\\_/ " );
	printf("\\");
		for(i=0;i<size;i++){
			printf("\n" );
			for(int a=0;a<tab-1;a++) printf(" ");
			tab++;
			printf("%d ",i );
			for(j=0;j<size;j++)
				printf("| %c ",table[i][j]);
			printf("| %d \n",i );
			for(int a=0;a<tab;a++) printf(" ");
				tab++;
			for(j=0;j<size;j++)
				printf(" \\_/");
		if(i<size-1)
			printf(" \\");
		}
		printf("\n" );
	return 0;
}
