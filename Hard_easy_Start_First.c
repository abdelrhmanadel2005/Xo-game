#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#define BLACK "\033[1;30m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"
#define RESET "\033[0m"

void colorfulWelcomeScreen();
void displayBoard();
int checkWin(char symbol);
int isBoardFull();
void clearBoard();
void TEM_9();
int checkWinMove(int row, int col, char currentPlayer);
void checkMoveValidity(char currentPlayer);

char board[3][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};

int main() {
    int again = 1;
    char player1 = 'X';
    char player2 = 'O';
    char currentPlayer = player1;
    int move;
    char desire[20];
    char computer = 'O';
    char playerr[20], playerrr[20];
    TEM_9();
    getch();
    system("cls");
    colorfulWelcomeScreen();
    getch();
    system("cls");

    while (1) {
        if (again == 1) {
            printf("\n1. To play against each other, enter [" GREEN "Start " RESET "]\n\n");
            printf("2. To play against the computer, enter [" MAGENTA "computer" RESET "]\n\n");
            printf("3. To exit the game, enter [" RED "End" RESET "]\n\n ");
        } else if (again == 2) {
            clearBoard();
            printf(YELLOW" We hope you enjoyed the game\n\n"RESET);
            printf("\n1. To play against each other, enter [" GREEN"Start"RESET"]\n");
            printf("2. To play against the computer, enter [" MAGENTA"computer"RESET"]\n");
            printf("3. To exit the game, enter [" RED "End" RESET "]\n\n");
        }

        while (1) {
            scanf("%s", desire);
            system("cls");
            for (int i = 0; desire[i]; i++) {
                if (desire[i] >= 'A' && desire[i] <= 'Z')
                    desire[i] += 32;
            }
            if (strcmp(desire, "start") == 0) {
                printf("\n  Player X Enter Your Name: ");
                scanf("%s", playerr);
                printf("\n  Player O Enter Your Name: ");
                scanf("%s", playerrr);
                currentPlayer = player1;

                do {
                    system("cls");
                    displayBoard();
                    printf("\n Player " YELLOW "%s" RESET ", enter your move (1 to 9): ",
                           (currentPlayer == player1) ? playerr : playerrr);
                    scanf("%d", &move);

                    if (move >= 1 && move <= 9) {
                        int row = (move - 1) / 3;
                        int col = (move - 1) % 3;

                        if (board[row][col] != 'X' && board[row][col] != 'O') {
                            board[row][col] = currentPlayer;

                            if (checkWin(currentPlayer)) {
                                system("cls");
                                char playerwin[20];
                                strcpy(playerwin, (currentPlayer == player1) ? playerr : playerrr);

                                displayBoard();

                                printf(GREEN"\n\t ---%s wins!---\n\n" RESET, playerwin);
                                printf("\a");
                                again = 2;
                                break;
                            }

                            if (isBoardFull()) {
                                system("cls");
                                displayBoard();
                                printf(CYAN"\n\t It's a draw!" RESET " \n\n");
                                again = 2;
                                break;
                            }

                            currentPlayer = (currentPlayer == player1) ? player2 : player1;
                        } else {
                            printf(RED"Invalid move! The square is already taken. Try again.\n" RESET);
                            _getch();
                        }
                    } else {
                        printf(RED"Invalid move! Please enter a number between 1 and 9.\n" RESET);
                        _getch();
                    }

                } while (1);
                break;
            } else if (strcmp(desire, "computer") == 0) {
                 printf("\n To Play Hard Enter [hard] \n\n");
                 printf(" To Play Easy Enter [easy] \n ");
                 char level[20];
                 scanf("%s",level);


                 if ( strcmp(level, "hard") == 0)

                    {

                printf("\n Player X Enter Your Name: ");
                scanf("%s", playerr);
                printf("\n ------------------------------ \n\n");

                printf( YELLOW " To Play First Enter [me]\n\n To Computer Play First Enter [Computer]\n\n "RESET);

                char first[20];
                scanf("%s",first);
                 if ( strcmp(first, "me") == 0)
                    currentPlayer = player1 ;
                 else if ( strcmp(first, "computer") == 0)
                    currentPlayer = computer ;


                do {

                    system("cls");
                    displayBoard();
                    if (currentPlayer == player1) {
                        printf("\n Player " YELLOW "%s" RESET ", enter your move (1 to 9): ", playerr);
                        scanf("%d", &move);

                        if (move >= 1 && move <= 9) {
                            int row = (move - 1) / 3;
                            int col = (move - 1) % 3;

                            if (board[row][col] != 'X' && board[row][col] != 'O') {
                                board[row][col] = player1;

                                if (checkWin(currentPlayer)) {
                                    system("cls");

                                    char playerwin[20];
                                    strcpy(playerwin, playerr);
                                    displayBoard();

                                    if (currentPlayer == player1) {
                                        printf(GREEN"\n\t ---%s wins!---\n\n" RESET, playerr);
                                    } else if (currentPlayer == computer) {
                                        printf(YELLOW "\n\t--- You lost ---\n Try again, Best Of luck !\n"RESET);
                                    }
                                    printf("\a");
                                    again = 2;
                                    break;
                                }

                                if (isBoardFull()) {
                                    system("cls");
                                    displayBoard();
                                    printf(CYAN"\n\t It's a draw!" RESET " \n\n");
                                    again = 2;
                                    break;}

                                currentPlayer = (currentPlayer == player1) ? computer : player1;
                            } else {
                                printf(RED"Invalid move! The square is already taken. Try again.\n" RESET);
                                _getch();
                            }
                        }
                        else {
                        printf(RED"Invalid move! Please enter a number between 1 and 9.\n" RESET);
                        _getch();
                    }
                    } else if (currentPlayer == computer) {

                        checkMoveValidity(currentPlayer);
                        if (checkWin(currentPlayer)) {
                                system("cls");
                                char playerwin[20];
                                strcpy(playerwin, (currentPlayer == player1) ? playerr : playerrr);

                                displayBoard();

                                printf(GREEN"\n\t --- You Lose! ---\n\n" RESET, playerwin);
                                printf("\a");
                                again = 2;
                                break;
                            }
                        currentPlayer = player1; // Switch back to the human player
                            if (isBoardFull()) {
                                system("cls");
                                displayBoard();
                                printf(CYAN"\n\t It's a draw!" RESET " \n\n");
                                again=2;
                                break;
                            }




                    } else {
                        printf(RED"Invalid move! Please enter a number between 1 and 9.\n" RESET);
                        _getch();
                    }
                } while (1);
                break;
                }
                else if(strcmp(level, "easy") == 0){
                        printf("\n  Player X Enter Your Name: ");
                scanf("%s", playerr);
                currentPlayer = player1;

                     do {

                    system("cls");
                    displayBoard();
                    if(currentPlayer==player1)
                    {
                    printf("\n Player " YELLOW "%s" RESET ", enter your move (1 to 9): ",playerr);
                    scanf("%d",&move);
                    if (move >= 1 && move <= 9) {

                        int row = (move - 1) / 3;
                        int col = (move - 1) % 3;

                        if (board[row][col] != 'X' && board[row][col] != 'O' )
                            {
                            board[row][col] = player1;
                           // getch();
                            if (checkWin(currentPlayer)) {
                                system("cls");

                                char playerwin[20];
                                strcpy ( playerwin , playerr);
                                displayBoard();
                                if(currentPlayer==player1){
                                printf(GREEN"\n\t ---%s wins!---\n\n" RESET, playerr );
                                }
                                else if(currentPlayer==computer){
                                   printf(YELLOW "\n\t--- You lost ---\n Try again, Best Of luck !\n"RESET);
                                }
                                printf("\a");
                                again=2;
                                break;
                            }


                            if (isBoardFull()) {
                                system("cls");
                                displayBoard();
                                printf(CYAN"\n\t It's a draw!" RESET " \n\n");
                                again=2;
                                break;
                            }

                            currentPlayer = (currentPlayer == player1) ? computer : player1;
                        }
                        else {
                            printf(RED "Invalid move! The square is already taken. Try again.\n" RESET);
                            _getch();
                        }
                    }
                     }
                    else if(currentPlayer==computer){
                            srand(time(0));
                            int f=rand()%3;
                            int s=rand()%3;

                            int Control=1;
                            while(Control==1){

                                    if (board[f][s] != 'X' && board[f][s] != 'O' ) {
                                       board[f][s] = computer;
                                       Control =2;
                                   // getch();
                                    }
                                    else{
                                    // sleep(1000);
                                   // srand(time(0));
                                     f=rand()%3;
                                     s=rand()%3;
                                     Control =1;

                                    }


                            }
                            if (checkWin(currentPlayer)) {
                                system("cls");

                                char playerwin[20];
                                strcpy ( playerwin , playerr);
                                displayBoard();
                                if ( currentPlayer == player1 ){
                                printf(GREEN"\n\t ---%s wins!---\n\n" RESET, playerr );
                                }
                                else if(currentPlayer==computer){
                                printf(YELLOW "\n\t--- You lost ---\n Try again, Best Of luck !\n"RESET);
                                }
                                printf("\a");
                                again=2;
                                break;
                            }
                          currentPlayer = (currentPlayer == player1) ? computer : player1;
                    }



                    else {
                        printf( RED "Invalid move! Please enter a number between 1 and 9.\n" RESET);
                        _getch();
                    }
                } while (1);
                break;
                }

            } else if (strcmp(desire, "end") == 0) {
                return 1;
            } else {
                printf("\n Please Enter [" GREEN "start" RESET "] Or [" RED "end"RESET"] Or [" MAGENTA "Computer" RESET "] \n ");
            }
        }
    }

    return 0;
}

void colorfulWelcomeScreen() {
    printf(WHITE"\n");
    printf(YELLOW " \t< Welcome to Tic Tac Toe (X&O) game by Team 9! >\n\n"RESET);
    printf(YELLOW "\t < We hope you have an enjoyable time playing.>\n\n" RESET);
    printf(WHITE"\t  -------------------------------------------\n\n"RESET);
    printf(RED" Warning: You should not choose a number you have previously selected.\n"RESET);
    printf("\n");
    printf(YELLOW "  Click Enter Again "RESET);
}

void displayBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 'X') {
                printf(BLUE " X" RESET);
            } else if (board[i][j] == 'O') {
                printf(RED " O" RESET);
            } else {
                printf(" %c", board[i][j]);
            }

            if (j < 2) {
                printf(" |");
            }
        }
        printf("\n");

        if (i < 2) {
            printf("---|---|---\n");
        }
    }
}

int checkWin(char symbol) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol))
            return 1; // Win
    }

    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol))
        return 1; // Win

    return 0; // No win
}

int isBoardFull() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0; // Board is not full
            }
        }
    }

    return 1; // Board is full
}

void clearBoard() {
    int f = 49;
    while (f <= 57) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = f;
                f++;
            }
        }
    }
}

void TEM_9() {
    printf(" \n\n\t"RED" Made By :"RESET" \n\t\t    < "BLUE"Abdelrahman Magdy "RESET"> \n\n ");
    printf("\t < "BLUE " Galal Hussein"RESET"   > ---  <  " BLUE" Abdelrhman Adel" RESET" >\n\n");
    printf("\t <  " BLUE" Malak Yasser"RESET"   > ---  <  " BLUE" Simon Abdelmalak" RESET" >\n\n");
    printf("\t  -------------------------------------------\n\n" RESET);
    printf(YELLOW "  Click Enter ");
}

int checkWinMove(int row, int col, char currentPlayer)
{
    if ((board[row][0] == currentPlayer && board[row][1] == currentPlayer && board[row][2] == currentPlayer) ||
        (board[0][col] == currentPlayer && board[1][col] == currentPlayer && board[2][col] == currentPlayer) ||
        (row == col && board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (row + col == 2 && board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer))
        return 1; // Win
    return 0; // No win
}

void checkMoveValidity(char currentPlayer) {
    // Check for a winning move for the computer
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                char original = board[i][j];
                board[i][j] = currentPlayer;

                if (checkWinMove(i, j, currentPlayer)) {
                    return; // The move results in a win for the computer
                }

                board[i][j] = original; // Reset the move
             }
           }
         }

    // If no winning move for the computer, block the opponent's winning move
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                char original = board[i][j];
                board[i][j] = 'X';  // Assume opponent's move

                if (checkWinMove(i, j, 'X')) {
                    board[i][j] = currentPlayer;  // Block opponent's winning move
                    return;
                }

                board[i][j] = original; // Reset the move
            }
        }
    }

    // If no winning or blocking move, play randomly
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] == 'X' || board[row][col] == 'O');

    board[row][col] = currentPlayer;

}
