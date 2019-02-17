#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "commands.h"
#include "minimax.h"

int main(int argc, char const *argv[]) {
	FILE *f;
  static char commands[11][20]={"newgame","play","cont","undo","suggest","level","swap","save","load","showstate","quit"};
  int count=0,difficulty=0,row,i,j,x=0,size=11,col;
  char a,command[20],c,nextMove='w';
	array table;
	double situations;
	bool end=false,swap=false,black=false;
	Listptr playerlist,ailist;
	playerlist=NULL;
	ailist=NULL;
  while(++x!=argc){
    if(!strcmp(argv[x],"-n")){
      size=atoi(argv[++x]);
      if(size>26&&size<4)
        size=11;
    }
    else if(!strcmp(argv[x],"-d")) difficulty=atoi(argv[++x]);
    else if(!strcmp(argv[x],"-b")) {
			black=true;
			nextMove='w';
		}
    else if(!strcmp(argv[x],"-s")) swap=true;
  }

	table=maketable(size);
	situations=size*size;
	//IF DIFFICULTY ISN'T GIVEN
  if(!difficulty)
    difficulty=1;
  printf("Level of difficulty is %d\n",difficulty );
  printf("Size of table is %d \n",size );
  printf("Swap rule is %s\n",swap?"on":"off" );
  while(!end){
    count=0;
    printf("Please give a command\n");
    while((c=getchar())!='\n'&&count<20){
      command[count]=c;
      count++;
    }
    if(count>=20){
      printf("Typed too many characters , try again \n");
      memset(command,' ',20);
      continue;
    }
    x=check(command);
    printf("%d\n",x );
    //printf("%s\n",command );
    switch (x) {
      case 0: //newgame
        printf("New game starting : do you want to save your current game? \n Press y or n\n");
        scanf("%c",&a);
        //if(a=='y')
          //save FILE
        for(i=0;i<size;i++)
          for(j=0;j<size;j++)
            table[i][j]=' ';
        break;

      case 1: //play
				printf("%s\n",command );
        printf("move : %c- %c \n",command[5],command[6] );
        row=command[5]-65;
        col=command[6]-49;
        printf("%d - %d \n",row,col );
				//να βαλω if για τη swap
        if(black)
          table[row][col]='b';
        else
          table[row][col]='w';
       	//moveplayed=black?'w':'b';
				insert_at_end(&playerlist,row,col);
        break;

      // case 2:     //cont
      //   if(moveplayed){
      //     //minimax(0,difficulty,black);
      //   //  moveplayed=false;
      //   }
      //   else
      //     printf("Make a move before continuing\n");
      //   break;

      case 3:   //undo
        if(black/*&&nextMove=='w'*/){
					playerlist=delete(playerlist,table);
					//moveplayed=false;
				}
        else{
           ailist=delete(ailist,table);
          // nextMove='w';
        }
        break;


      case 4:   //suggest
        //minimax(play,table,min);
        printf("i do suggest to fuck off\n" );
        break;

     case 5:    //level
          scanf("%s",&a);
          if(!strcmp(&a,"\n"))
            printf("Difficulty level is:%d\n",difficulty );
          else
            scanf("%d\n",&difficulty );
        break;

      case 6:     //swap
          if (black)
            black=false;
          else
            black=true;
          break;

					case 7:     //save
				if((f=fopen("file.hex", "w+"))==NULL)
					printf("Cannot open file.\n");
				fwrite(&nextMove,1,sizeof(nextMove),f);
				fwrite(&size,1,sizeof(int),f);
				if(fwrite(table,sizeof(char),size*size,f)!=size*size)
					printf("File write error\n");
				// for(i=0;i<size;i++)
				// 	for(j=0;j<size;j++){
				// 		if(table[i][j])
				// 			fwrite(&table[i][j],1.sizeof(char),f);
				// 		else
				// 			fprintf(f,"n");
				// 	}
        fclose(f);
        break;

      case 8:     //load
				f=fopen("file.hex","r");
				if(f==NULL){
					printf("There is no file to be loaded\n");
					return -1;
				}

				while(1){
					nextMove=fgetc(f);
					size=fgetc(f);
					table=maketable(size);
					for (i = 0; i < size; i++) {
						for( j=0; j < size; j++)
							table[i][j]=fgetc(f);
					}
					if(feof(f))
         		break ;
				}
      	fclose(f);
        break;

      case 9:   //showstate
				printtable(table,size);
        break;

      case 10: //quit
          end=true;
          break;

      case 11: //wrong command
        printf("Wrong command , please try again\n");
    }
      memset(command,' ',20);
  }
  // for( i = 0; i < size; i++)
  //   free(table[i]);
  // free(table);
  return 0;
}
