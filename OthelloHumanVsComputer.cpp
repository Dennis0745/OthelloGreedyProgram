#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int Count = 8;
int max = Count - 1;
char PlayerX = 'X';
char PlayerO = 'O';
char Empty = ' ';

char Board [8][8];
int brs, klm , xInput, yInput, CountX, CountO, CountEmpty, xC, yC;
char Turn;
int CountTable [8];
int AICount[8][8];

void ClearBoard()
{
	for (brs = 0; brs < Count; brs++)
	 for (klm = 0; klm < Count; klm++)
	  Board[brs][klm] = Empty;
}

void NewBoard()
{
	ClearBoard();
	Board[3][3] = PlayerX;
	Board[4][4] = PlayerX;
	Board[3][4] = PlayerO;
	Board[4][3] = PlayerO;
}

void PrintBoard()
{
	printf(" 01234567\n");
	for (brs = 0; brs < Count; brs++)
	{
		printf("%i", brs);
		for (klm = 0; klm < Count; klm++)
		 printf("%c", Board[brs][klm]);
		puts("");
	}
}

int CalculateGained (int yp, int xp)
{
	int x, y, i;
	int TotalCount = 0;
	
	// 0 arah atas
	x = xp;
	y = yp - 1;
	CountTable[0] = 0;
	
	while (y >= 0)
	{
		if (Board[y][x] == Empty)
		{
			CountTable[0] = 0;
			break;
		}
		else if (Board[y][x] == Turn)
		{
			break;
		}
		else
		{
			y -= 1;
			CountTable[0] += 1;
		}
	}
	
	// 1 arah bawah
	x=xp;
	y=yp+1;
	CountTable[1]=0;

	while (y < Count){
		if (Board[y][x] == Empty)
		{
			CountTable[1] = 0;
			break;
		}
		else if (Board[y][x]==Turn)
		{
			break;
		}
		else
		{
			y++;
			CountTable[1] += 1;
		}
	}
	
	// 2 arah kanan
	x = xp + 1;
	y = yp;
	CountTable[2] = 0;
	
	while (x < Count)
	{
		if (Board[y][x] == Empty)
		{
			CountTable[2] = 0;
			break;
		}
		else if (Board[y][x] == Turn)
		{
			break;
		}
		else
		{
			x += 1;
			CountTable[2] += 1;
		}
	}
	
	
	// 3 arah kiri 
	x = xp - 1;
	y = yp;
	CountTable[3] = 0;

	while (x >= 0){
		if (Board[y][x] == Empty)
		{
			CountTable[3] = 0;
			break;
		}
		else if (Board[y][x] == Turn)
		{
			break;
		}
		else
		{
			x -= 1;
			CountTable[3] += 1;
		}
	}
	
	// 4 arah atas kiri
	x = xp - 1;
	y = yp - 1;
	CountTable[4] = 0;
	while(y >= 0 && x >= 0)
	{
		if(Board[y][x] == Empty)
		{
			CountTable[4] = 0;
			break;
		}
		else if (Board[y][x] == Turn)
		{
			break;
		}
		else
		{
			x -= 1;
			y -= 1;
			CountTable[4] += 1;
		}
	}
	
	// 5 arah bawah kiri
	x = xp - 1;
	y = yp + 1;
	CountTable[5] = 0;
	while (y < Count && x >= 0)
	{
		if(Board[y][x] == Empty)
		{
			CountTable[5] = 0;
			break;
		}
		else if (Board[y][x]==Turn)
		{
			break;
		}
		else
		{
			x -= 1;
			y += 1;
			CountTable[5] += 1;
		}
	}
	
	// 6 arah atas kanan
	x = xp + 1;
	y = yp - 1;
	CountTable[6] = 0;
	while (x < Count && y >= 0)
	{
		if(Board[y][x] == Empty)
		{
			CountTable[6] = 0;
			break;
		}
		else if (Board[y][x]==Turn)
		{
			break;
		}
		else
		{
			x += 1;
			y -= 1;
			CountTable[6] += 1;
		}
	}
	
	// 7 arah bawah kanan
	x = xp + 1;
	y = yp + 1;
	CountTable[7] = 0;
	while (x < Count && y < Count)
	{
		if(Board[y][x] == Empty)
		{
			CountTable[7] = 0;
			break;
		}
		else if (Board[y][x]==Turn)
		{
			break;
		}
		else
		{
			x += 1;
			y += 1;
			CountTable[7] += 1;
		}
	}
	
	
	TotalCount = 0;
	for (i = 0; i < Count; i++)
	{
		TotalCount += CountTable[i];
	}
	return TotalCount;
}



void ChangeColor (int yp, int xp)
{
	int x, y, i;
	// 0 ganti warna ke atas
	x = xp;
	y = yp - 1;
	for (i = 0; i < CountTable[0]; i++)
	{
		Board[y][x] = Turn;
		y -= 1;
	}
	
	// 1 ganti warna ke bawah
	x = xp;
	y = yp + 1;
	for (i = 0; i < CountTable[1]; i++)
	{
		Board[y][x] = Turn;
		x += 1;
	}
	
	// 2 ganti warna ke kanan
	x = xp + 1;
	y = yp;
	for (i = 0; i < CountTable[2]; i++)
	{
		Board[y][x] = Turn;
		x += 1;
	}
	
	// 3 ganti warna ke kiri
	x = xp - 1;
	y = yp;
	for (i = 0; i < CountTable[3]; i++)
	{
		Board[y][x] = Turn;
		x -= 1;
	}
	
	
	// 4 ganti warna ke atas kiri
	x = xp - 1;
	y = yp - 1;
	for (i = 0; i < CountTable[4]; i++)
	{
		Board[y][x] = Turn;
		x -= 1;
		y -= 1;
	}
	
	// 5 ganti warna bawah kiri
	x = xp - 1;
	y = yp + 1;
	for (i = 0; i < CountTable[5]; i++)
	{
		Board[y][x] = Turn;
		x -= 1;
		y += 1;
	}
	
	// 6 ganti warna atas kanan
	x = xp + 1;
	y = yp - 1;
	for (i = 0; i < CountTable[6]; i++)
	{
		Board[y][x] = Turn;
		x += 1;
		y -= 1;
	}
	
	// 7 ganti warna bawah kanan
	x = xp + 1;
	y = yp + 1;
	for (i = 0; i < CountTable[7]; i++)
	{
		Board[y][x] = Turn;
		x += 1;
		y += 1;
	}
}

void CountPlayer()
{
	CountEmpty = 0;
	CountX = 0;
	CountO = 0;
	
	for (brs = 0; brs < Count; brs++)
	 for (klm = 0; klm < Count; klm++)
	 {
	 	if (Board[brs][klm] == PlayerX)
	 	{
	 		CountX += 1;
		}
		else if (Board[brs][klm] == PlayerO)
		{
			CountO += 1;
		}
		else
		{
			CountEmpty += 1;
		}
	 }
}

void ComputerCount()
{
	int x, y, GreedyMax;
	GreedyMax = 0;
	for(y = 0; y < Count; y++)
	 for (x = 0; x < Count; x++)
	 {
	 	if (Board[y][x] == Empty)
	 	{
	 		if (GreedyMax < CalculateGained(y , x))
	 		{
	 			GreedyMax = CalculateGained(y , x);
	 			xC = x;
	 			yC = y;
			}
		}
	 }
}


int main()
{
	char GameType;
	printf("Game Othello Greedy Method\n");
	puts("");
	printf("1. Human vs Greedy Computer\n");
	printf("2. Human vs Human\n");
	printf("Please enter your choice: ");
	scanf("%i", &GameType);
	if (GameType == 1)
	 PlayerO = 'C';
	else
	 PlayerO = 'O';
	
	Turn = PlayerX;
	NewBoard();
	
	do
	{
		PrintBoard();
		puts("");
		printf ("Player %c:", Turn);
		puts("");
		printf("Please enter row: ");
		scanf("%i", &yInput);
		printf("Please enter col: ");
		scanf("%i", &xInput);
		
		if ((xInput >= 0) && (xInput < Count) && (yInput >= 0) && (yInput < Count))
		 if (Board[yInput][xInput] > 0)
		  if (CalculateGained(yInput, xInput) > 0)
		  {
		  	Board[yInput][xInput] = Turn;
		  	ChangeColor(yInput, xInput);
		  	CountPlayer();
		  	
		  	if (Turn == PlayerX)
		  	 Turn = PlayerO;
		  	else
		  	 Turn = PlayerX;
		  	
		  	if (CountEmpty > 0)
		  	{
		  		if (GameType == 1)
		  		{
		  			PrintBoard();
		  			printf("Press any key for computer to play\n");
		  			getch();
		  			//AI Greedy start working
		  			ComputerCount();
		  			Board[yC][xC] = Turn;
		  			CalculateGained(yC, xC);
		  			ChangeColor(yC, xC);
		  			Turn = PlayerX;
		  			CountPlayer();
				}
			}
		  }	
	} while ((xInput < Count) && (yInput < Count) && (CountEmpty > 0));
	
	if (CountX > CountO)
	 printf("Player %c wins", PlayerX);
	else if (CountX < CountO)
	 printf("Player %c wins", PlayerO);
	else
	 printf("A Draw Game");
}
