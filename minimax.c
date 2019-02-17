int minimax(int table,int depth,bool player){
	int value;
	// if(!depth&&table/*terminal node*/)
	// 	return evaluate();
  if(player){
    value=-100;
    for(int i=0;i<node;i++)
      value=max(value,minimax(node,depth-1,false));
    return value;
  }
  else{
    value=100;
    for(int i=0;i<node;i++)
      value=min(value,minimax(node,depth-1,true));
    return value;
  }
}

// int solveKTUtil(int x, int y, int movei, int sol[N][N],
// 				int xMove[], int yMove[]);
//
// /* A utility function to check if i,j are valid indexes
// for N*N chessboard */
// bool isSafe(int x, int y, int sol[N][N])
// {
// 	return ( x >= 0 && x < N && y >= 0 &&
// 			y < N && sol[x][y] == -1);
// }
//
// /* A utility function to print solution matrix sol[N][N] */
// void printSolution(int sol[N][N])
// {
// 	for (int x = 0; x < N; x++)
// 	{
// 		for (int y = 0; y < N; y++)
// 			printf(" %2d ", sol[x][y]);
// 		printf("\n");
// 	}
// }
//
// /* This function solves the Knight Tour problem using
// Backtracking. This function mainly uses solveKTUtil()
// to solve the problem. It returns false if no complete
// tour is possible, otherwise return true and prints the
// tour.
// Please note that there may be more than one solutions,
// this function prints one of the feasible solutions. */
// bool solveKT()
// {
// 	int sol[N][N];
//
// 	/* Initialization of solution matrix */
// 	for (int x = 0; x < N; x++)
// 		for (int y = 0; y < N; y++)
// 			sol[x][y] = -1;
//
// 	/* xMove[] and yMove[] define next move of Knight.
// 	xMove[] is for next value of x coordinate
// 	yMove[] is for next value of y coordinate */
// 	int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
// 	int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
//
// 	// Since the Knight is initially at the first block
// 	sol[0][0] = 0;
//
// 	/* Start from 0,0 and explore all tours using
// 	solveKTUtil() */
// 	if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == false)
// 	{
// 		printf("Solution does not exist");
// 		return false;
// 	}
// 	else
// 		printSolution(sol);
//
// 	return true;
// }
//
// /* A recursive utility function to solve Knight Tour
// problem */
// int solveKTUtil(int x, int y, int movei, int sol[N][N],
// 				int xMove[N], int yMove[N],int depth)
// {
// int k, next_x, next_y;
// if (movei == N*N)
// 	return true;
//
// /* Try all next moves from the current coordinate x, y */
// for (k = 0; k < depth; k++)
// {
// 	next_x = x + xMove[k];
// 	next_y = y + yMove[k];
// 	if (isSafe(next_x, next_y, sol))
// 	{
// 		sol[next_x][next_y] = movei;
// 		if (solveKTUtil(next_x, next_y, movei+1, sol,
// 						xMove, yMove,depth-1) == true)
// 			return true;
// 		else
// 			sol[next_x][next_y] = -1;// backtracking
// 	}
// }
//
// return false;
// }


bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);

/* A utility function to check if x,y is valid index for N*N maze */
bool isSafe(int maze[N][N], int x, int y)
{
    // if (x,y outside maze) return false
    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;

    return false;
}

/* This function solves the Maze problem using Backtracking.  It mainly
   uses solveMazeUtil() to solve the problem. It returns false if no
   path is possible, otherwise return true and prints the path in the
   form of 1s. Please note that there may be more than one solutions,
   this function prints one of the feasible solutions.*/
bool evaluate(array table,int size,int depth)
{

    if(solveMazeUtil(maze, 0, 0, sol) == false)
    {
        printf("Solution doesn't exist");
        return false;
    }
    return true;
}

/* A recursive utility function to solve Maze problem */
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
    // if (x,y is goal) return true
    if(x == N-1 && y == N-1)
    {
        sol[x][y] = 1;
        return true;
    }

    // Check if maze[x][y] is valid
    if(isSafe(maze, x, y) == true)
    {
        // mark x,y as part of solution path
        sol[x][y] = 1;

        /* Move forward in x direction */
        if (solveMazeUtil(maze, x+1, y, sol) == true)
            return true;

        /* If moving in x direction doesn't give solution then
           Move down in y direction  */
        if (solveMazeUtil(maze, x, y+1, sol) == true)
            return true;

        /* If none of the above movements work then BACKTRACK:
            unmark x,y as part of solution path */
        sol[x][y] = 0;
        return false;
    }

    return false;
}
