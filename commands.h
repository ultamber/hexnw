typedef char ** array;
typedef struct listnode *Listptr;

struct listnode {
  int row;
  int col;
  //move move;
  Listptr next;
};

int minimax(int node,int depth,bool player);
int check(char *command);
Listptr delete(Listptr list);
void insert_at_end(Listptr *list, int row,int col);
int min(int a, int b);
int max(int a ,int b);
bool checkwin(array table,int size)
array maketable(int size);
void printtable(array table,int size);
Listptr delete(Listptr list,array table);
void insert_at_end(Listptr *list, int row,int col);
