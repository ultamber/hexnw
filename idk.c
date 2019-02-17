int proccessQuery(Map * map, Trie * trie){
    char * line = NULL, * command;
    size_t len = 0;
    int v = 1;
    Fcommand fcommand;

    printf("Command:");
    getline(&line, &len, stdin);

    command = (char *) malloc(len * sizeof(char));
    sscanf(line, "%s", command);

    if(isValidCommand(command, &fcommand))
        v = (*fcommand)(map, trie, line);
    else
        printf("Invalid command\n");

    free(line);
    free(command);
    return v;
}

int isValidCommand(char * command, Fcommand * fcommand){
    int numOfCommands = 4;
    Command known[numOfCommands];
    known[0] = (Command) {"/search", &search};
    known[1] = (Command) {"/df", &df};
    known[2] = (Command) {"/tf", &tf};
    known[3] = (Command) {"/exit", &exitF};

    for(int i = 0; i < numOfCommands; i++)
        if(!strcmp(command, known[i].command)){
            *fcommand = known[i].fcommand;
            return 1;
        }
    return 0;
}

typedef int (*Fcommand)(Map *, Trie *, char *);

typedef struct Command{
    char command[20];
    Fcommand fcommand;
}Command;
