#include<bits/stdc++.h>

using namespace std;

void putRand(vector<vector<int> > &board)
{
    int pos = rand()%16;
    int i=pos/4;
    int j=pos%4;

    while(board[i][j]!=0)
    {
        pos++;
        pos%=16;
        i=pos/4;
        j=pos%4;
    }

    board[i][j]=2;
    return;
}

int nextMove(vector<vector<int> > &board, char move)
{
    int i, j, k;
    int flag=0;
    int empty=0;
    switch (move)
    {
    case 'w':
        {
            for(j=0;j<4;j++)
            {
                i=0;
                k=-1;
                while(i<4)
                {
                    if(board[i][j]==0) 
                    {
                        empty=1;
                        i++;
                    }
                    else 
                    {
                        if(flag!=1) flag=-1;
                        board[k+1][j]=board[i][j];
                        board[i][j]=0;
                        if(board[k][j]==board[k+1][j])
                        {
                            board[k][j]*=2;
                            if(board[k][j]==2048) flag=1;
                            board[k+1][j]=0;
                        }
                        else k++;
                        i++;
                    }
                }
            }
        }
        break;
    
    case 'a':
        {
            for(i=0;i<4;i++)
            {
                j=0;
                k=-1;
                while(j<4)
                {
                    if(board[i][j]==0) 
                    {
                        empty=1;
                        j++;
                    }
                    else 
                    {
                        if(flag!=1) flag=-1;
                        board[i][k+1]=board[i][j];
                        board[i][j]=0;
                        if(board[i][k]==board[i][k+1])
                        {
                            board[i][k]*=2;
                            if(board[i][k]==2048) flag=1;
                            board[i][k+1]=0;
                        }
                        else k++;
                        j++;
                    }
                }
            }
        }
        break;
    
    case 's':
        {
            for(j=0;j<4;j++)
            {
                i=3;
                k=4;
                while(i<4)
                {
                    if(board[i][j]==0) 
                    {
                        empty=1;
                        i--;
                    }
                    else 
                    {
                        if(flag!=1) flag=-1;
                        board[k-1][j]=board[i][j];
                        board[i][j]=0;
                        if(board[k][j]==board[k-1][j])
                        {
                            board[k][j]*=2;
                            if(board[k][j]==2048) flag=1;
                            board[k-1][j]=0;
                        }
                        else k--;
                        i--;
                    }
                }
            }
        }
        break;
    
    case 'd':
        {
            for(i=0;i<4;i++)
            {
                j=3;
                k=4;
                while(j>=0)
                {
                    if(board[i][j]==0) 
                    {
                        empty=1;
                        j--;
                    }
                    else 
                    {
                        if(flag!=1) flag=-1;
                        board[i][k-1]=board[i][j];
                        board[i][j]=0;
                        if(board[i][k]==board[i][k-1])
                        {
                            board[i][k]*=2;
                            if(board[i][k]==2048) flag=1;
                            board[i][k-1]=0;
                        }
                        else k--;
                        j--;
                    }
                }
            }
        }
        break;
    
    default: printf("Invalid move\n");
        break;
    }

    if(flag==0) 
    {
        if(!empty) return -1;
        printf("No can do\n");
    }
    else
    {
        putRand(board);
        if(flag==1) return 1;
    }

    return 0;
}

void printBoard(vector<vector<int> > &board)
{
    int i, j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("\t%d", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    vector<vector<int> > board(4, vector<int>(4,0));
    int i, j;
    int flag=0;

    //Initializing
    // for(i=0;i<4;i++)
    // {
    //     for(j=0;j<4;j++)
    //     {
    //         board[i][j]=0;
    //     }
    // }

    putRand(board);
    putRand(board);

    printBoard(board);

    //Continuous running
    while(flag==0)
    {
        printf("next move: ");
        char move;
        cin >> move;
        flag = nextMove(board, move);
        putRand(board);
        printBoard(board);
    }

    //Ending
    cout<< "Game over\n";
    if(flag==1) cout<< "You win!\n";
    else cout<< "Better luck next time!\n";
    
    return 0;
}