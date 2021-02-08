package com.company;

public class OthelloFunctionWithComputer extends Main
{
    int count = 8;
    char playerX = 'X';
    char playerO = 'O';
    char empty = 32;

    char [][] board = new char [count][count];
    int row, col, xInput, yInput, countX, countO, countEmpty, xC, yC;
    char turn = playerX;
    int [] countTable = new int [count];

    void clearBoard()
    {
        for (row = 0; row < count; row++)
        {
            for (col = 0; col < count; col++)
            {
                board[row][col] = empty;
            }
        }
    }

    void newBoard()
    {
        clearBoard();
        board[3][3] = playerX;
        board[4][4] = playerX;
        board[3][4] = playerO;
        board[4][3] = playerO;
    }

    void printBoard()
    {
        System.out.print(" 01234567\n");
        for (row = 0; row < count; row++)
        {
            System.out.print(row);
            for (col = 0; col < count; col++)
            {
                System.out.print(board[row][col]);
            }
            System.out.println();
        }
    }

    int calculateGained (int yp, int xp)
    {
        int x, y, i;
        int totalCount = 0;

        // 0 arah atas
        x = xp;
        y = yp - 1;
        countTable[0] = 0;

        while (y >= 0)
        {
            if (board[y][x] == empty)
            {
                countTable[0] = 0;
                break;
            }
            else if (board[y][x] == turn)
            {
                break;
            }
            else
            {
                y -= 1;
                countTable[0] += 1;
            }
        }

        // 1 arah bawah
        x = xp;
        y = yp + 1;
        countTable[1] = 0;

        while (y < count)
        {
            if (board[y][x] == empty)
            {
                countTable[1] = 0;
                break;
            }
            else if (board[y][x] == turn)
            {
                break;
            }
            else
            {
                y += 1;
                countTable[1] += 1;
            }
        }

        // 2 arah kanan
        x = xp + 1;
        y = yp;
        countTable[2] = 0;

        while (x < count)
        {
            if (board[y][x] == empty)
            {
                countTable[2] = 0;
                break;
            }
            else if (board[y][x] == turn)
            {
                break;
            }
            else
            {
                x += 1;
                countTable[2] += 1;
            }
        }

        // 3 arah kiri
        x = xp - 1;
        y = yp;
        countTable[3] = 0;

        while (x >= 0)
        {
            if (board[y][x] == empty)
            {
                countTable[3] = 0;
                break;
            }
            else if (board[y][x] == turn)
            {
                break;
            }
            else
            {
                x -= 1;
                countTable[3] += 1;
            }
        }

        // 4 arah atas kiri
        x = xp - 1;
        y = yp - 1;
        countTable[4] = 0;
        while (y >= 0 && x >= 0)
        {
            if(board[y][x] == empty)
            {
                countTable[4] = 0;
                break;
            }
            else if (board[y][x] == turn)
            {
                break;
            }
            else
            {
                x -= 1;
                y -= 1;
                countTable[4] += 1;
            }
        }

        // 5 arah bawah kiri
        x = xp - 1;
        y = yp + 1;
        countTable[5] = 0;
        while (y < count && x >= 0)
        {
            if(board[y][x] == empty)
            {
                countTable[5] = 0;
                break;
            }
            else if (board[y][x] == turn)
            {
                break;
            }
            else
            {
                x -= 1;
                y += 1;
                countTable[5] += 1;
            }
        }

        // 6 arah atas kanan
        x = xp + 1;
        y = yp - 1;
        countTable[6] = 0;
        while (x < count && y >= 0)
        {
            if(board[y][x] == empty)
            {
                countTable[6] = 0;
                System.out.println("a");
                break;
            }
            else if (board[y][x] == turn)
            {
                System.out.println("b");
                break;
            }
            else
            {
                System.out.println("c");
                x += 1;
                y -= 1;
                countTable[6] += 1;
            }
        }

        // 7 arah bawah kanan
        x = xp + 1;
        y = yp + 1;
        countTable[7] = 0;
        while (x < count && y < count)
        {
            if(board[y][x] == empty)
            {
                countTable[7] = 0;
                break;
            }
            else if (board[y][x] == turn)
            {
                break;
            }
            else
            {
                x += 1;
                y += 1;
                countTable[7] += 1;
            }
        }

        for (i = 0; i < count; i++)
        {
            totalCount += countTable[i];
        }
        return totalCount;
    }

    void changeColor (int yp, int xp)
    {
        int x, y, i;

        //0 ganti warna ke atas
        x = xp;
        y = yp - 1;
        for (i = 0; i < countTable[0]; i++)
        {
            board[y][x] = turn;
            y -= 1;
        }

        //1 ganti warna ke bawah
        x = xp;
        y = yp + 1;
        for (i = 0; i < countTable[1]; i++)
        {
            board[y][x] = turn;
            x += 1;
        }

        //2 ganti warna ke kanan
        x = xp + 1;
        y = yp;
        for (i = 0; i < countTable[2]; i++)
        {
            board[y][x] = turn;
            x += 1;
        }

        //3 ganti warna ke kiri
        x = xp - 1;
        y = yp;
        for (i = 0; i < countTable[3]; i++)
        {
            board[y][x] = turn;
            x -= 1;
        }

        //4 ganti warna ke atas kiri
        x = xp - 1;
        y = yp - 1;
        for (i = 0; i < countTable[4]; i++)
        {
            board[y][x] = turn;
            x -= 1;
            y -= 1;
        }

        //5 ganti warna ke bawah kiri
        x = xp - 1;
        y = yp + 1;
        for (i = 0; i < countTable[5]; i++)
        {
            board[y][x] = turn;
            x -= 1;
            y += 1;
        }

        //6 ganti warna ke atas kanan
        x = xp + 1;
        y = yp - 1;
        for (i = 0; i < countTable[6]; i++)
        {
            board[y][x] = turn;
            x += 1;
            y -= 1;
        }

        //7 ganti warna ke bawah kanan
        x = xp + 1;
        y = yp + 1;
        for (i = 0; i< countTable[7]; i++)
        {
            board[y][x] = turn;
            x += 1;
            y += 1;
        }
    }

    void countPlayer()
    {
        countEmpty = 0;
        countX = 0;
        countO = 0;

        for(row = 0; row < count; row++)
        {
            for (col = 0; col < count; col++)
            {
                if(board[row][col] == playerX)
                {
                    countX += 1;
                }
                else if (board[row][col] == playerO)
                {
                    countO += 1;
                }
                else
                {
                    countEmpty += 1;
                }
            }
        }
    }

    void computerCount()
    {
        int x, y, greedyMax;
        greedyMax = 0;
        for(y = 0; y < count; y++)
        {
            for (x = 0; x < count; x++)
            {
                if (board[y][x] == empty)
                {
                    if (greedyMax < calculateGained(y, x))
                    {
                        greedyMax = calculateGained(y, x);
                        xC = x;
                        yC = y;
                    }
                }
            }
        }
    }

    void computerPrograms()
    {
        computerCount();
        board[yC][xC] = turn;
        calculateGained(yC, xC);
        changeColor(yC, xC);
        turn = playerX;
        countPlayer();
    }
}
