package com.company;
import java.util.Scanner;
public class Main {

    public static void main(String[] args)
    {
        int count = 8;
        int gameType;
        int xInput, yInput;

        Scanner scanner = new Scanner(System.in);
        OthelloFunctionWithComputer game = new OthelloFunctionWithComputer();
        game.newBoard();
        System.out.println("Game Othello Greedy Method");
        System.out.println();
        System.out.println("1. Human vs Greedy Computer");
        System.out.println("2. Human vs Human");
        System.out.println("Please enter your choice: ");
        gameType = scanner.nextInt();

        do
        {
            game.printBoard();
            System.out.println("Player" + game.turn + " : ");
            System.out.println("Please enter row: ");
            yInput = scanner.nextInt();
            System.out.println("Please enter col: ");
            xInput = scanner.nextInt();

            if ((xInput >= 0) && (xInput < count) && (yInput>= 0) && (yInput < count))
            {
                if (game.board[yInput][xInput] > 0)
                {
                    if ((game.calculateGained(yInput, xInput)) > 0)
                    {
                        game.board[yInput][xInput] = game.turn;
                        game.changeColor(yInput, xInput);
                        game.countPlayer();

                        if (game.turn == game.playerX)
                        {
                            game.turn = game.playerO;
                        }
                        else
                        {
                            game.turn = game.playerX;
                        }

                        if (game.countEmpty > 0)
                        {
                            if (gameType == 1)
                            {
                                game.printBoard();
                                System.out.println("Press any key for computer to play");
                                System.out.flush();
                                // AI Greedy start working
                                game.computerPrograms();
                            }
                        }
                    }
                }
            }
        }while ((xInput < count) && (yInput < count) && (game.countEmpty > 0));

        if (game.countX > game.countO)
        {
            System.out.println("Player " + game.playerX + " wins");
        }
        else if (game.countX < game.countO)
        {
            System.out.println("Player " + game.playerO + " wins");
        }
        else
        {
            System.out.println("A Draw Game");
        }
    }
}
