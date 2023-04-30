#include"steepest.cpp"
#include<iostream>

using namespace std;
int main()
{
	srand(time(NULL));
	int board[N];

    for(int i = 0; i < 8; ++i)
        board[i]= rand()%8;

    cout <<"Initial Board"<< endl;
    printBoard(board);

    hillClimbing(board);

	return 0;
}