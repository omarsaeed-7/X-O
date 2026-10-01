#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void displayBoard();
bool makeMove(char player);
bool checkWin(char player);
bool checkDraw();

int main()
{
    char player = 'X';

    while (true)
    {
        displayBoard();

        cout << "Player " << player << ", enter your position: ";
        if (!makeMove(player))
        {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        if (checkWin(player))
        {
            displayBoard();
            cout << "Player " << player << " wins!\n";
            break;
        }

        if (checkDraw())
        {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }

        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    return 0;
}

void displayBoard()
{
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "\n";
}

bool makeMove(char player)
{
    int position;
    cin >> position;

    if (position < 1 || position > 9)
        return false;

    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O')
        return false;

    board[row][col] = player;
    return true;
}

bool checkWin(char player)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;

        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }

    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }

    return true;
}
