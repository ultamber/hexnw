int min(int a, int b){
	return a>b?b:a;
}

int max(int a ,int b){
	return a>b?a:b;
}

array maketable(int size){
	array table;
	table=calloc(size,sizeof(char *));
  for(int j=0;j<size;j++){
    table[j]=calloc(size,sizeof(char));
  }
	return table;
}

void printtable(array table,int size){
	//its messy and not really comprehensible but it does the job
	int i,j,tab=1;
	printf("    ");
	for(i=0;i<size;i++) printf("%c   ",i+65);
	printf("\n");
	printf("    ");
	for(i=0;i<size;i++) printf("_   ");
	printf("\n   / ");
	for(i=0;i<size-1;i++) printf("\\_/ " );
	printf("\\");
		for(i=0;i<size;i++){
			if(i>=9) tab-=1;
			printf("\n" );
			for(int a=0;a<tab-1;a++) printf(" ");
			tab++;
			printf("%d ",i+1 );
			for(j=0;j<size;j++)
				printf("| %c ",table[i][j]);
			printf("| %d \n",i+1 );
				if(i>=9) tab+=1;
			for(int a=0;a<tab;a++) printf(" ");
			if(i<=9) tab++;
			for(j=0;j<size;j++)
				printf(" \\_/");
		if(i<size-1)
			printf(" \\");
		}
		printf("\n" );
		for(int a=0;a<tab+2;a++) printf(" ");
		for(i=0;i<size;i++) printf("%c   ",i+65);
		printf("\n");
}

bool checkwin(array table,int size){
	for(i=0;i<size;i++){

	}
}

int evaluate(){

}

int check(char *command){
  printf("%s\n",command );
  if(strstr(command,"newgame")!=NULL)
    return 0;
  else if(strstr(command,"play")!=NULL)
    return 1;
  else if(strstr(command,"cont")!=NULL)
    return 2;
  else if(strstr(command,"undo")!=NULL)
    return 3;
  else if(strstr(command,"suggest")!=NULL)
    return 4;
  else if(strstr(command,"level")!=NULL)
    return 5;
  else if(strstr(command,"swap")!=NULL)
    return 6;
  else if(strstr(command,"save")!=NULL)
    return 7;
  else if(strstr(command,"load")!=NULL)
    return 8;
  else if(strstr(command,"showstate")!=NULL)
    return 9;
  else if(strstr(command,"quit")!=NULL)
    return 10;
  else
    return 11;
}

Listptr delete(Listptr list,array table){
  Listptr temp =list;
  Listptr t;
  if(list->next==NULL){
		table[list->row][list->col]=' ';
    printf("Can't undo more moves\n" );
  }
  else{
     while(temp->next != NULL){
        t=temp;
        temp=temp->next;
     }
		 table[temp->row][temp->col]=' ';
     free(t->next);
     t->next=NULL;
  }
  return list;
}

void insert_at_end(Listptr *list, int row,int col){
	while (*list != NULL)
		list = &((*list)->next);
	*list = malloc(sizeof(struct listnode));
	(*list)->row = row;
	(*list)->col = col;
	(*list)->next = NULL;
}
