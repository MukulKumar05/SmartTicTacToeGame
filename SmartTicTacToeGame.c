#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
void gameWithSmartComputer();
void gameWithEvilComputer();
void gameWithPerson();
void printMatrix(int [3][3]);
void markingEmptySlotsWithSymbols(int [3][3], int *, int);
int isBoardFull(int [3][3]);
void assignSymboltoBoardPosition(int [3][3], int, int **, int, int);
void markingEmptySlotsByComputer(int [3][3], int *);
void markingEmptySlotsByEvilComputer(int [3][3], int *);
void regame();

void assignSymboltoBoardPosition(int matrix[3][3], int symbolValue, int **moveCount, int row, int col)
{
    if(matrix[row][col] != 0 && matrix [row][col] != 'X')
    {
        matrix[row][col] = symbolValue;
        (**moveCount) += 1;
    }
}

void markingEmptySlotsWithSymbols(int matrix[3][3], int *moveCount, int symbolValue)
{
    int cellNumber;
    cellNumber = getch();

    switch (cellNumber)
    {
    case '1':
        assignSymboltoBoardPosition(matrix, symbolValue, &moveCount, 0, 0);
        break;
    case '2':
        assignSymboltoBoardPosition(matrix, symbolValue, &moveCount, 0, 1);
        break;
    case '3':
        assignSymboltoBoardPosition(matrix, symbolValue, &moveCount, 0, 2);
        break;
    case '4':
        assignSymboltoBoardPosition(matrix, symbolValue, &moveCount, 1, 0);
        break;
    case '5':
        assignSymboltoBoardPosition(matrix, symbolValue, &moveCount, 1, 1);
        break;
    case '6':
        assignSymboltoBoardPosition(matrix, symbolValue, &moveCount, 1, 2);
        break;
    case '7':
        assignSymboltoBoardPosition(matrix, symbolValue, &moveCount, 2, 0);
        break;
    case '8':
        assignSymboltoBoardPosition(matrix, symbolValue, &moveCount, 2, 1);
        break;
    case '9':
        assignSymboltoBoardPosition(matrix, symbolValue, &moveCount, 2, 2);
        break;
    case 'e':
        exit(0);
    }

}

void markingEmptySlotsByComputer(int matrix[3][3], int *moveCount)
{
    int i, j, xCount, zeroCount, blankj, blanki, assignStatus = 0;

    // when computer encounters about to win situation row wise
    if(assignStatus == 0)
    {
        for(i = 0; i < 3; i++)
        {
            zeroCount = 0;
            for(j = 0; j < 3; j++)
            {
                if(matrix[i][j] == 0)
                    zeroCount++;
                else
                {
                    blankj = j;
                }
            }
            
            if(zeroCount == 2 && matrix[i][blankj] != 'X')
            {
                assignSymboltoBoardPosition(matrix, 0, &moveCount, i, blankj);
                assignStatus = 1;
                break;
            }
        }
    }

    // when computer encounters about to win situation column wise
    if(assignStatus == 0)
    {
        for(i = 0; i < 3; i++)
        {
            zeroCount = 0;
            for(j = 0; j < 3; j++)
            {
                if(matrix[j][i] == 0)
                    zeroCount++;
                else
                {
                    blankj = j;
                }
            }
            
            if(zeroCount == 2 && matrix[blankj][i] != 'X')
            {
                assignSymboltoBoardPosition(matrix, 0, &moveCount, blankj, i);
                assignStatus = 1;
                break;
            }
        }
    }

    // when computer encounters about to win situation left diagonal wise
    if(assignStatus == 0)
    {
        zeroCount = 0;
        for (i = 0; i < 3; i++)
        {
            if(matrix[i][i] == 0)
                zeroCount++;
            else
                blankj = i;
        }
        if(zeroCount == 2 && matrix[blankj][blankj] != 'X')
        {
            assignSymboltoBoardPosition(matrix, 0, &moveCount, blankj, blankj);
            assignStatus = 1;
        }
    }

    
    // when computer encounters about to win situation right diagonal wise
    if(assignStatus == 0)
    {
        zeroCount = 0;
        for (i = 0; i < 3; i++)
        {
            for(j = 0; j < 3; j++)
            {
                if(i + j == 2)
                {
                    if(matrix[i][j] == 0)
                        zeroCount++;
                    else
                    {
                        blanki = i;
                        blankj = j;
                    }
                }
            }
        }
        if(zeroCount == 2 && matrix[blanki][blankj] != 'X')
        {
            assignSymboltoBoardPosition(matrix, 0, &moveCount, blanki, blankj);
            assignStatus = 1;
        }
    }
    

    // when computer encounters about to lose situation row wise
    if(assignStatus == 0)
    {
        for(i = 0; i < 3; i++)
        {
            xCount = 0;
            for(j = 0; j < 3; j++)
            {
                if(matrix[i][j] == 'X')
                    xCount++;
                else
                {
                    blankj = j;
                }
            }
            if(xCount == 2 && matrix[i][blankj] != 0)
            {
                assignSymboltoBoardPosition(matrix, 0, &moveCount, i, blankj);
                assignStatus = 1;
                break;
            }
        }
    }

    // when computer encounters about to lose situation column wise
    if(assignStatus == 0)
    {
        for(i = 0; i < 3; i++)
        {
            xCount = 0;
            for(j = 0; j < 3; j++)
            {
                if(matrix[j][i] == 'X')
                    xCount++;
                else
                {
                    blankj = j;
                }
            }
            
            if(xCount == 2 && matrix[blankj][i] != 0)
            {
                assignSymboltoBoardPosition(matrix, 0, &moveCount, blankj, i);
                assignStatus = 1;
                break;
            }
        }
    }

    // when computer encounters about to lose situation left diagonal wise
    if(assignStatus == 0)
    {
        xCount = 0;
        for(i = 0; i < 3; i++)
        {
            if(matrix[i][i] == 'X')
                xCount++;
            else
                blankj = i;
        }
        if(xCount == 2 && matrix[blankj][blankj] != 0)
        {
            assignSymboltoBoardPosition(matrix, 0, &moveCount, blankj, blankj);
            assignStatus = 1;
        }
    }

    // when computer encounters about to lose situation right diagonal wise
    if(assignStatus == 0)
    {
        xCount = 0;
        for(i = 0; i < 3; i++)
        {
            for(j = 0; j < 3; j++)
            {
                if(i + j == 2)
                {
                    if(matrix[i][j] == 'X')
                        xCount++;
                    else
                    {
                        blanki = i;
                        blankj = j;
                    }
                }
            }
        }
        if(xCount == 2 && matrix[blanki][blankj] != 0)
        {
            assignSymboltoBoardPosition(matrix, 0, &moveCount, blanki, blankj);
            assignStatus = 1;
        }
    }

    // normal or general situation
    if(assignStatus == 0)
    {
        int arr[9][2] = {{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}, {0, 1}, {1, 0}, {1, 2}, {2, 1}};
        
        for(i = 0; i < 9; i++)
        {
            if(matrix[arr[i][0]][arr[i][1]] != 0 && matrix[arr[i][0]][arr[i][1]] != 'X')
            {
                assignSymboltoBoardPosition(matrix, 0, &moveCount, arr[i][0], arr[i][1]);
                break;
            }
        }
        assignStatus = 1;
    }
}

void markingEmptySlotsByEvilComputer(int matrix[3][3], int *moveCount)
{
    int i, j, xCount, zeroCount, blankj, blanki, assignStatus = 0;

    // when computer encounters about to win situation row wise
    if(assignStatus == 0)
    {
        for(i = 0; i < 3; i++)
        {
            zeroCount = 0;
            for(j = 0; j < 3; j++)
            {
                if(matrix[i][j] == 0)
                    zeroCount++;
                else
                {
                    blankj = j;
                }
            }
            
            if(zeroCount == 2 && matrix[i][blankj] != 'X')
            {
                assignSymboltoBoardPosition(matrix, 0, &moveCount, i, blankj);
                assignStatus = 1;
                break;
            }
        }
    }

    // when computer encounters about to win situation column wise
    if(assignStatus == 0)
    {
        for(i = 0; i < 3; i++)
        {
            zeroCount = 0;
            for(j = 0; j < 3; j++)
            {
                if(matrix[j][i] == 0)
                    zeroCount++;
                else
                {
                    blankj = j;
                }
            }
            
            if(zeroCount == 2 && matrix[blankj][i] != 'X')
            {
                assignSymboltoBoardPosition(matrix, 0, &moveCount, blankj, i);
                assignStatus = 1;
                break;
            }
        }
    }

    // when computer encounters about to win situation left diagonal wise
    if(assignStatus == 0)
    {
        zeroCount = 0;
        for (i = 0; i < 3; i++)
        {
            if(matrix[i][i] == 0)
                zeroCount++;
            else
                blankj = i;
        }
        if(zeroCount == 2 && matrix[blankj][blankj] != 'X')
        {
            assignSymboltoBoardPosition(matrix, 0, &moveCount, blankj, blankj);
            assignStatus = 1;
        }
    }

    
    // when computer encounters about to win situation right diagonal wise
    if(assignStatus == 0)
    {
        zeroCount = 0;
        for (i = 0; i < 3; i++)
        {
            for(j = 0; j < 3; j++)
            {
                if(i + j == 2)
                {
                    if(matrix[i][j] == 0)
                        zeroCount++;
                    else
                    {
                        blanki = i;
                        blankj = j;
                    }
                }
            }
        }
        if(zeroCount == 2 && matrix[blanki][blankj] != 'X')
        {
            assignSymboltoBoardPosition(matrix, 0, &moveCount, blanki, blankj);
            assignStatus = 1;
        }
    }
    
    // when computer encounters about to lose situation row wise, column wise, or diagonal wise
    if(assignStatus == 0)
    {
        // when computer encounters about to lose situation row wise
        for(i = 0; i < 3; i++)
        {
            xCount = 0;
            for(j = 0; j < 3; j++)
            {
                if(matrix[i][j] == 'X')
                    xCount++;
                else
                {
                    blankj = j;
                }
            }
            if(xCount == 2 && matrix[i][blankj] != 0)
            {
                matrix[i][blankj] = 0;
                assignStatus = 1;
                break;
            }
        }

        // when computer encounters about to lose situation column wise
        for(i = 0; i < 3; i++)
        {
            xCount = 0;
            for(j = 0; j < 3; j++)
            {
                if(matrix[j][i] == 'X')
                    xCount++;
                else
                {
                    blankj = j;
                }
            }
            
            if(xCount == 2 && matrix[blankj][i] != 0)
            {
                matrix[blankj][i] = 0;
                assignStatus = 1;
                break;
            }
        }

        // when computer encounters about to lose situation left diagonal wise
        xCount = 0;
        for(i = 0; i < 3; i++)
        {
            if(matrix[i][i] == 'X')
                xCount++;
            else
                blankj = i;
        }
        if(xCount == 2 && matrix[blankj][blankj] != 0)
        {
            matrix[blankj][blankj] = 0;
            assignStatus = 1;
        }

        // when computer encounters about to lose situation right diagonal wise
        xCount = 0;
        for(i = 0; i < 3; i++)
        {
            for(j = 0; j < 3; j++)
            {
                if(i + j == 2)
                {
                    if(matrix[i][j] == 'X')
                        xCount++;
                    else
                    {
                        blanki = i;
                        blankj = j;
                    }
                }
            }
        }
        if(xCount == 2 && matrix[blanki][blankj] != 0)
        {
            matrix[blanki][blankj] = 0;
            assignStatus = 1;
        }

        if(assignStatus == 1)
            (*moveCount) += 1;
    }

    // normal or general situation
    if(assignStatus == 0)
    {
        int arr[9][2] = {{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}, {0, 1}, {1, 0}, {1, 2}, {2, 1}};
        
        for(i = 0; i < 9; i++)
        {
            if(matrix[arr[i][0]][arr[i][1]] != 0 && matrix[arr[i][0]][arr[i][1]] != 'X')
            {
                assignSymboltoBoardPosition(matrix, 0, &moveCount, arr[i][0], arr[i][1]);
                break;
            }
        }
        assignStatus = 1;
    }
}

int isBoardFull(int matrix[3][3])
{
    int i, j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(matrix[i][j] != 0 && matrix[i][j] != 'X')
                return 0;
        }
    }
    return 1;
}

void printMatrix(int matrix[3][3])
{
    int i, j;
    printf("-------------------------\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(matrix[i][j] == 88)
                printf("| %c\t", matrix[i][j]);
            else
                printf("| %d\t", matrix[i][j]);
        }
        printf("|\n");
    }
    printf("-------------------------\n");
}

int player1Won(int matrix[3][3])
{
    int i, j, playerSymbol = 'X';
    
    // checking row-wise Winning
    for(i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if(matrix[i][j] != playerSymbol)
                break;
        }
        if(j == 3)
            return 1;
    }

    // checking column-wise Winning
    for(i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if(matrix[j][i] != playerSymbol)
                break;
        }
        if(j == 3)
            return 1;
    }

    // checking for left diagonal win
    for(i = 0; i < 3; i++)
    {
        if(matrix[i][i] != playerSymbol)
            break;
    }
    if(i == 3)
        return 1;
    
    
    // checking for right diagonal win
    if(matrix[0][2] == playerSymbol && matrix[1][1] == playerSymbol && matrix[2][0] == playerSymbol)
        return 1;
    
    // otherwise
    return 0;
}

int player2Won(int matrix[3][3])
{
    int i, j, playerSymbol = 0;
    
    // checking row-wise Winning
    for(i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if(matrix[i][j] != playerSymbol)
                break;
        }
        if(j == 3)
            return 1;
    }

    // checking column-wise Winning
    for(i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if(matrix[j][i] != playerSymbol)
                break;
        }
        if(j == 3)
            return 1;
    }

    // checking for left diagonal win
    for(i = 0; i < 3; i++)
    {
        if(matrix[i][i] != playerSymbol)
            break;
    }
    if(i == 3)
        return 1;
    
    
    // checking for right diagonal win
    if(matrix[0][2] == playerSymbol && matrix[1][1] == playerSymbol && matrix[2][0] == playerSymbol)
        return 1;
    
    // otherwise
    return 0;
}

void gameWithSmartComputer()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, moveCount = 1;
    char player1Name[40], player2Name[15] = "Smart Computer";
    system("cls");
    printf("Enter your name: ");
    fflush(stdin);
    fgets(player1Name, 40, stdin);
    player1Name[strlen(player1Name) - 1] = '\0';

    while(!isBoardFull(matrix))
    {
        system("cls");
        printf("##################### Tic Tac Toe ###########################\n\n");

        printf("\n%s Symbol: X\n", player1Name);
        printf("%s Symbol: 0\n\n", player2Name);

        printMatrix(matrix);

        printf("\n\nTo mark X at a particular position on board, press the same number key which is present at that particular position.\n\n");
        printf("\nPress e to exit the game anytime\n\n");

        if(moveCount % 2)
        {
            markingEmptySlotsWithSymbols(matrix, &moveCount, 'X');
        }
        else
        {
            markingEmptySlotsByComputer(matrix, &moveCount);
        }

        if(moveCount % 2)
        {
            if(player2Won(matrix))
            {
                system("cls");
                printf("##################### Tic Tac Toe ###########################\n\n");

                printf("\n%s Symbol: X\n", player1Name);
                printf("%s Symbol: 0\n\n", player2Name);

                printMatrix(matrix);
                printf("\n\n#############################################################");
                printf("\n\n\nYou lose!!!\n\nBetter luck next time.\n\n\n");
                printf("#############################################################\n\n");
                break;
            }

        }
        else
        {
            if(player1Won(matrix))
            {
                system("cls");
                printf("##################### Tic Tac Toe ###########################\n\n");

                printf("\n%s Symbol: X\n", player1Name);
                printf("%s Symbol: 0\n\n", player2Name);

                printMatrix(matrix);
                printf("\n\n#############################################################");
                printf("\n\n\nCongratulations %s\n\n You Won!!!\n\n\n", player1Name);
                printf("#############################################################\n\n");
                break;
            }
        }
    }
    if(isBoardFull(matrix))
    {
        system("cls");
        printf("##################### Tic Tac Toe ###########################\n\n");

        printf("\n%s Symbol: X\n", player1Name);
        printf("%s Symbol: 0\n\n", player2Name);

        printMatrix(matrix);
        printf("\n\n#############################################################");
        printf("\n\n\nGame Draw!\n\n\n");
        printf("#############################################################\n\n");
    }
}

void gameWithEvilComputer()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, moveCount = 1;
    char player1Name[40], player2Name[15] = "Evil Computer";
    system("cls");
    printf("Enter your name: ");
    fflush(stdin);
    fgets(player1Name, 40, stdin);
    player1Name[strlen(player1Name) - 1] = '\0';

    while(!isBoardFull(matrix))
    {
        system("cls");
        printf("##################### Tic Tac Toe ###########################\n\n");

        printf("\n%s Symbol: X\n", player1Name);
        printf("%s Symbol: 0\n\n", player2Name);

        printMatrix(matrix);

        printf("\n\nTo mark X at a particular position on board, press the same number key which is present at that particular position.\n\n");
        printf("\nPress e to exit the game anytime\n\n");

        if(moveCount % 2)
        {
            markingEmptySlotsWithSymbols(matrix, &moveCount, 'X');
        }
        else
        {
            markingEmptySlotsByEvilComputer(matrix, &moveCount);
        }

        if(moveCount % 2)
        {
            if(player2Won(matrix))
            {
                system("cls");
                printf("##################### Tic Tac Toe ###########################\n\n");

                printf("\n%s Symbol: X\n", player1Name);
                printf("%s Symbol: 0\n\n", player2Name);

                printMatrix(matrix);
                printf("\n\n#############################################################");
                printf("\n\n\nYou lose!!!\n\nBetter luck next time.\n\n\n");
                printf("#############################################################\n\n");

                break;
            }

        }
        else
        {
            if(player1Won(matrix))
            {
                system("cls");
                printf("##################### Tic Tac Toe ###########################\n\n");

                printf("\n%s Symbol: X\n", player1Name);
                printf("%s Symbol: 0\n\n", player2Name);

                printMatrix(matrix);
                printf("\n\n#############################################################");
                printf("\n\n\nCongratulations %s\n\n You Won!!!\n\n\n", player1Name);
                printf("#############################################################\n\n");
                break;
            }
        }
    }
    if(isBoardFull(matrix))
    {
        system("cls");
        printf("##################### Tic Tac Toe ###########################\n\n");

        printf("\n%s Symbol: X\n", player1Name);
        printf("%s Symbol: 0\n\n", player2Name);

        printMatrix(matrix);
        printf("\n\n#############################################################");
        printf("\n\n\nGame Draw!\n\n\n");
        printf("#############################################################\n\n");
    }
}

void gameWithPerson()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, moveCount = 1;
    char player1Name[40], player2Name[40];
    system("cls");
    printf("Enter name of player 1: ");
    fflush(stdin);
    fgets(player1Name, 40, stdin);
    player1Name[strlen(player1Name) - 1] = '\0';

    printf("Enter name of player 2: ");
    fflush(stdin);
    fgets(player2Name, 40, stdin);
    player2Name[strlen(player2Name) - 1] = '\0';

    while(!isBoardFull(matrix))
    {
        system("cls");
        printf("##################### Tic Tac Toe ###########################\n\n");

        printf("\n%s Symbol: X\n", player1Name);
        printf("%s Symbol: 0\n\n", player2Name);

        printMatrix(matrix);

        printf("\n\nTo mark X or 0 at a particular position on board, press the same number key which is present at that particular position.\n\n");
        printf("\nPress e to exit the game anytime\n\n");

        if(moveCount % 2)
        {
            printf("Current Turn of Player: %s\n", player1Name);
            markingEmptySlotsWithSymbols(matrix, &moveCount, 'X');
        }
        else
        {
            printf("Current Turn of Player: %s\n", player2Name);
            markingEmptySlotsWithSymbols(matrix, &moveCount, 0);
        }

        if(moveCount % 2)
        {
            if(player2Won(matrix))
            {
                system("cls");
                printf("##################### Tic Tac Toe ###########################\n\n");

                printf("\n%s Symbol: X\n", player1Name);
                printf("%s Symbol: 0\n\n", player2Name);

                printMatrix(matrix);
                printf("\n\n#############################################################");
                printf("\n\n\nCongratulations %s\n\n You Won!!!\n\n\n", player2Name);
                printf("#############################################################\n\n");
                break;
            }

        }
        else
        {
            if(player1Won(matrix))
            {
                system("cls");
                printf("##################### Tic Tac Toe ###########################\n\n");

                printf("\n%s Symbol: X\n", player1Name);
                printf("%s Symbol: 0\n\n", player2Name);

                printMatrix(matrix);
                printf("\n\n#############################################################");
                printf("\n\n\nCongratulations %s\n\n You Won!!!\n\n\n", player1Name);
                printf("#############################################################\n\n");
                break;
            }
        }
    }
    if(isBoardFull(matrix))
    {
        system("cls");
        printf("##################### Tic Tac Toe ###########################\n\n");

        printf("\n%s Symbol: X\n", player1Name);
        printf("%s Symbol: 0\n\n", player2Name);

        printMatrix(matrix);
        printf("\n\n#############################################################");
        printf("\n\n\nGame Draw!\n\n\n");
        printf("#############################################################\n\n");
    }
}

void regame()
{
    char response;
    printf("\n\nPress y to play again OR press any key to exit......\n");
    response = getch();
    switch (response)
    {
    case 'y':
        main();
        break;
    default:
        exit(0);
    }
}

int main()
{
    int response;
    system("cls");
    printf("Hello, Welcome to Smart Tic Tac Toe Game!\n\n");
    printf("Select the game type that you want to play:\n");
    printf("1. Play with smart computer\n");
    printf("2. Play with evil computer\n");
    printf("3. Play with player\n");
    printf("4. Exit\n");
    response = getch();
    switch (response)
    {
        case '1':
            gameWithSmartComputer();
            break;
        case '2':
            gameWithEvilComputer();
            break;
        case '3':
            gameWithPerson();
            break;
        case '4':
            exit(0);
        default:
            printf("Please select correct choice!");
    }
    regame();
    return 0;
}