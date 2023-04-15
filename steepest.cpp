#include<bits/stdc++.h>
#include<iostream>
using namespace std;

const int N = 8;

int countNonAttackingPairs(int (&board)[N]) // calculates the fitness of a board configuration. //It returns the number of non-attacking pairs of queens on the board
{
    int counter = 0;
    //The function iterates over all pairs of queens on the board using two nested loops
    for(int i = 0; i < N; ++i)
    {
        for(int j = i + 1; j < N; j++)
        {
            if (board[i] == board[j] || abs(i - j) == abs(board[i] - board[j])) //if the queens are attacking each other by either being on the same row or on the same diagonal.
                counter++;
        }
    }
    return (N * (N - 1)) / 2 - counter; 
    /*The function then subtracts cnt from the total number of possible pairs of queens, which is (N * (N - 1)) / 2.
    This gives the number of non-attacking pairs of queens,
    which is returned as the fitness of the board configuration*/
}

void printBoard(int (&board)[N])
{ 
  /*The function iterates over each row and column on the board using two nested loops.
  For each square, it checks if a queen is present by comparing the row index of the queen 
  in column j with the current row index i. If a queen is present, it prints Q. Otherwise, it prints -.*/
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if (board[j] == i)
                cout << "Q ";
            else
                cout << "- ";
        }
        cout << endl;
    }
}

void copyBoard(int (&board1)[N], int (&board2)[N])
{
    //memcpy function to copy the contents of board2 into board1
    memcpy(board1, board2, sizeof(board1));
}


bool hillClimbing(int (&board)[N])
{
    int bestBoard[N], bestValue, boardValue;
    copyBoard(bestBoard, board);

    int cnt = 0;
    while(1)
    {
        int currBoard[N], currValue;
        copyBoard(currBoard, board);
        boardValue = bestValue = countNonAttackingPairs(board);

        if(bestValue == 28)
        {
            cout << "Reached Global Maxima after " << cnt << " moves" << endl;
            printBoard(bestBoard);
            return true;
        }

        cnt++;
        bool foundBetter = false;
        for(int i = 0; i < 8; ++i)
        {
            int temp = currBoard[i];
            for(int j = 0; j < 8; ++j)
            {
                if(j == currBoard[i])
                    continue;
                currBoard[i] = j;
                currValue = countNonAttackingPairs(currBoard);
                if(currValue > bestValue)
                {
                    bestValue = currValue;
                    copyBoard(bestBoard, currBoard);
                    foundBetter = true;
                }
            }
            currBoard[i] = temp;
        }
        if(!foundBetter)
        {
            cout << "Stuck in Local Maxima after " << cnt << " moves" << endl;
            printBoard(bestBoard);
            return false;
        }
        copyBoard(board, bestBoard);
    }
}
