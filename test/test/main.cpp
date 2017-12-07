//
//  main.cpp
//  test
//
//  Created by Vighneshan Moorthy on 11/28/17.
//  Copyright © 2017 Vighneshan Moorthy. All rights reserved.
//

#include <iostream>
#include "Piece.hpp"
#include "square.hpp"
#include <sstream>
#include <ctype.h>
#include <cmath>
#include <stdlib.h>
#include <string>

using namespace std;

void playGame();
bool validateMoveFormat(string);
bool validateMoveRules(string, Square[14][8], int);
void Display(Square[14][8]);

int main()
{
    playGame();
    return 0;
}

void playGame()
{
    Square board[14][8];
    
//identifying each player's pieces
    
    //player 1's pieces
    Piece w1("white", 1);
    Piece w2("white", 1);
    Piece w3("white", 1);
    Piece w4("white", 1);
    Piece w5("white", 1);
    Piece w6("white", 1);
    
    //player 2's pieces
    Piece b1("black", 2);
    Piece b2("black", 2);
    Piece b3("black", 2);
    Piece b4("black", 2);
    Piece b5("black", 2);
    Piece b6("black", 2);
    
//Putting pieces on the board
    
    //player 1
    board[4][2].piece = &w1;
    board[4][3].piece = &w2;
    board[4][4].piece = &w3;
    board[4][5].piece = &w4;
    board[5][3].piece = &w5;
    board[5][4].piece = &w6;
    
    //player 2
    board[8][2].piece = &b1;
    board[8][3].piece = &b2;
    board[8][4].piece = &b3;
    board[8][5].piece = &b4;
    board[9][3].piece = &b5;
    board[9][4].piece = &b6;
    
    int currentPlayer = 2;
    
    int p1Pieces = 6;
    int p2Pieces = 6;
    
    string move;
    
    while(true)
    {
        if(currentPlayer == 1)
        {
            currentPlayer = 2;
        }
        else
        {
            currentPlayer = 1;
        }
        
       // system("cls");
        
        Display(board);
        
        cout << "P" << currentPlayer << " Enter your move:";
        getline(cin, move);
        cin.ignore( numeric_limits <streamsize> ::max(), '\n' );
        
        while(validateMoveFormat(move) == false)
        {
            cout << "That is an invalid move. Please re-enter." << endl;
            cout << "something" << endl;
            getline(cin, move);
            cout << "something else" << endl;
        }
        
        while(validateMoveRules(move, board, currentPlayer) == false)
        {
            cout << "Please try another move." << endl;
            getline(cin, move);
        }
        
    }
    
}

bool validateMoveFormat(string move)
{
    
    //A valid move has 8, 9, or 10 characters
    if(move.length() != 8 && move.length() != 9 && move.length() != 10)
    {
        cout << move.length() << endl;
        return false;
    }
    /*
    
    //Checks that the first letter typed by the user is a valid letter
    if(move[0] != 'a' && move[0] != 'b' && move[0] != 'c' && move[0] != 'd' &&
       move[0] != 'e' && move[0] != 'f' && move[0] != 'g' && move[0] != 'h')
    {
        return false;
    }
    
    //Checks that the first number entered is valid
    if(move[1] != '0' && move[1] != '1' && move[1] != '2' && move[1] != '3' && move[1] != '4'
       && move[1] != '5' && move[1] != '6' && move[1] != '7')
    {
        return false;
    }
    
    //Checks that the letters 't' and 'o' are being typed to indicate where piece is being moved
    if(move[3] != 't' || move[4] != 'o')
    {
        return false;
    }
    
    //Checks that the destination letter is valid
    if(move[6] != 'a' && move[6] != 'b' && move[6] != 'c' && move[6] != 'd' && move[6] != 'e'
       && move[6] != 'f' && move[6] != 'g' && move[6] != 'h')
    {
        return false;
    }
    
    //Checks that the destination number is valid
    if(move[7] != '0' && move[7] != '1' && move[7] != '2' && move[7] != '3' && move[7] != '4'
       && move[7] != '5' && move[7] != '6' && move[7] != '7')
    {
        return false;
    }
     */
    
    else
    {
        return true;
    }
}

bool validateMoveRules(string move, Square board[14][8], int currentPlayer)
{
    stringstream stream;
    
    int c1 = 0;
    int c2 = 0;
    int n1 = 0;
    int n2 = 0;
    
    if(move.length() == 9)
    {
        if(move[2] == ' ')
        {
            stream << move[1];
            stream >> n1;
            
            stream.clear();
            
            stream << move[7] + move[8];
            stream >> n2;
        }
        else if(move[3] == ' ')
        {
            stream << move[1] + move[2];
            stream >> n1;
            
            stream.clear();
            
            stream << move[8];
            stream >> n2;
        }
    }
    else if(move.length() == 10)
    {
        stream << move[1] + move[2];
        stream >> n1;
        
        stream.clear();
        
        stream << move[8] + move[9];
        stream >> n2;
    }
    else if(move.length() == 8)
    {
        stream << move[1];
        stream >> n1;
        
        stream.clear();
        
        stream << move[7];
        stream >> n2;
    }
    //The first character of a move will always be a letter, regardless of the length of the move. This will make c1 equal to the the 0th index character of the move string
    if(move[0] == 'a')
        c1 = 0;
    else if(move[0] == 'b')
        c1 = 1;
    else if(move[0] == 'c')
        c1 = 2;
    else if(move[0] == 'd')
        c1 = 3;
    else if(move[0] == 'e')
        c1 = 4;
    else if(move[0] == 'f')
        c1 = 5;
    else if(move[0] == 'g')
        c1 = 6;
    else
        c1 = 7;
    
    if(move.length() == 8)
    {
        if(move[6] == 'a')
            c2 = 0;
        else if(move[6] == 'b')
            c2 = 1;
        else if(move[6] == 'c')
            c2 = 2;
        else if(move[6] == 'd')
            c2 = 3;
        else if(move[6] == 'e')
            c2 = 4;
        else if(move[6] == 'f')
            c2 = 5;
        else if(move[6] == 'g')
            c2 = 6;
        else
            c2 = 7;
    }
    
    //This if statement runs if the entire move has 9 letters
    if(move.length() == 9)
    {
        //If the first part of the move has a double digit number and the second part has a single digit number, then this part of the if statement will set c2 equal to the second letter in the 7th index
        if(move[3] == ' ')
        {
            if(move[7] == 'a')
                c2 = 0;
            else if(move[7] == 'b')
                c2 = 1;
            else if(move[7] == 'c')
                c2 = 2;
            else if(move[7] == 'd')
                c2 = 3;
            else if(move[7] == 'e')
                c2 = 4;
            else if(move[7] == 'f')
                c2 = 5;
            else if(move[7] == 'g')
                c2 = 6;
            else
                c2 = 7;
        }
        //This else statement is if the first part of the move has a single digit number and the second part has a double digit number
        else
        {
            if(move[6] == 'a')
                c2 = 0;
            else if(move[6] == 'b')
                c2 = 1;
            else if(move[6] == 'c')
                c2 = 2;
            else if(move[6] == 'd')
                c2 = 3;
            else if(move[6] == 'e')
                c2 = 4;
            else if(move[6] == 'f')
                c2 = 5;
            else if(move[6] == 'g')
                c2 = 6;
            else
                c2 = 7;
        }
    }
    //When there are 10 letters in the move string, this will determine the second letter and what the variable c2 will hold. There are 10 letters when both parts of the move have double digit numbers.
    if(move.length() == 10)
    {
        if(move[7] == 'a')
            c2 = 0;
        else if(move[7] == 'b')
            c2 = 1;
        else if(move[7] == 'c')
            c2 = 2;
        else if(move[7] == 'd')
            c2 = 3;
        else if(move[7] == 'e')
            c2 = 4;
        else if(move[7] == 'f')
            c2 = 5;
        else if(move[7] == 'g')
            c2 = 6;
        else
            c2 = 7;
    }
    //This checks to see if a player is trying to move a piece that is not at the location they typed in
    if(board[n1][c1].piece == nullptr)
    {
        cout  <<"There is no piece at that spot." << endl;
        return false;
    }
    
    //This checks if the player is moving their own piece, and the currentPlayer value must be equal to the value of the piece in question
    if(board[n1][c1].piece != nullptr && currentPlayer != board[n1][c1].piece->player)
    {
        cout << "That is not your piece!" << endl;
        return false;
    }
    
    //This checks if the player already has a piece at the destination that they are trying to move another piece to
    if(board[n2][c2].piece != nullptr && currentPlayer == board[n2][c2].piece->player)
    {
        cout << "You already have a piece there." << endl;
        return false;
    }
    
    if(board[n1][c1].piece->name.compare("white") == 0 && currentPlayer == 1)
    {
        cout << "The move was successful!" << endl;
        board[n2][c2].piece = board[n1][c1].piece;
        board[n1][c1].piece = nullptr;
        return true;
    }
    
    if(board[n1][c1].piece->name.compare("black") == 0 && currentPlayer == 2)
    {
        cout << "The move was successful!" << endl;
        board[n2][c2].piece = board[n1][c1].piece;
        board[n1][c1].piece = nullptr;
        return true;
    }
    
    else
    {
        return false;
    }
    
    
}


void Display(Square board[14][8])
{
    char displayBoard[38][53] =
    {
        
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', 'A', ' ', ' ', ' ', ' ', ' ', 'B', ' ', ' ', ' ', ' ', ' ', 'C', ' ', ' ', ' ', ' ', ' ', 'D', ' ', ' ', ' ', ' ', ' ', 'E', ' ', ' ', ' ', ' ', ' ', 'F', ' ', ' ', ' ', ' ', ' ', 'G', ' ', ' ', ' ', ' ', ' ', 'H', ' ', ' ', ' '
        },
        
        {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
        },
        
        
        {' ', '1', '3', ' ', '#', ' ', ' ', 'x', ' ', ' ', '#', ' ', ' ', 'x', ' ', ' ', '#', ' ', ' ', 'x', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', 'x', ' ', ' ', '#', ' ', ' ', 'x', ' ', ' ', '#', ' ', ' ', 'x', ' ', ' ', '#'
        },

        {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
        },
        
        
        {' ', '1', '2', ' ', '#', ' ', ' ', 'x', ' ', ' ', '#', ' ', ' ', 'x', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', 'x', ' ', ' ', '#', ' ', ' ', 'x', ' ', ' ', '#'
        },
        
        {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
        },
        
        
        {' ', '1', '1', ' ', '#', ' ', ' ', 'x', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', 'x', ' ', ' ', '#'
        },
        
        {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
        },
        
        
        {' ', '1', '0', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'
        },
        
        {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
        },
        
        
        {' ', ' ', '9', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', 'B', ' ', ' ', '#', ' ', ' ', 'B', ' ', ' ', '#', ' ', ' ', 'B', ' ', ' ', '#', ' ', ' ', 'B', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'
        },
        
        {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
        },
        
        
        {' ', ' ', '8', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', 'B', ' ', ' ', '#', ' ', ' ', 'B', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'
        },
        
        {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
        },
        

        {' ', ' ', '7', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'
        },
        
        
        {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
        },
        
        {' ', ' ', '6', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'
        },
        
        {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
        },
        
        {' ', ' ', '5', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', 'W', ' ', ' ', '#', ' ', ' ', 'W', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'
        },
        
        {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
        },
        
        {' ', ' ', '4', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', 'W', ' ', ' ', '#', ' ', ' ', 'W', ' ', ' ', '#', ' ', ' ', 'W', ' ', ' ', '#', ' ', ' ', 'W', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'
        },

        {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
        },

        {' ', ' ', '3', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'
        },

        {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
        },

        {' ', ' ', '2', ' ', '#', ' ', ' ', 'x', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', 'x', ' ', ' ', '#'
        },

        {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
        },

        {' ', ' ', '1', ' ', '#', ' ', ' ', 'x', ' ', ' ', '#', ' ', ' ', 'x', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', 'x', ' ', ' ', '#', ' ', ' ', 'x', ' ', ' ', '#'
        },

        {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
        },

        {' ', ' ', '0', ' ', '#', ' ', ' ', 'x', ' ', ' ', '#', ' ', ' ', 'x', ' ', ' ', '#', ' ', ' ', 'x', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', 'x', ' ', ' ', '#', ' ', ' ', 'x', ' ', ' ', '#', ' ', ' ', 'x', ' ', ' ', '#'
        },

        {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
        },
        
    };
    
    int dR0 = 28;
    int dR1 = 26;
    int dR2 = 24;
    int dR3 = 22;
    int dR4 = 20;
    int dR5 = 18;
    int dR6 = 16;
    int dR7 = 14;
    int dR8 = 12;
    int dR9 = 10;
    int dR10 = 8;
    int dR11 = 6;
    int dR12 = 4;
    int dR13 = 2;
    
    int dC0 = 7;
    int dC1 = 13;
    int dC2 = 19;
    int dC3 = 25;
    int dC4 = 31;
    int dC5 = 37;
    int dC6 = 43;
    int dC7 = 49;
    
    int aRow = 0;
    int aColumn = 0;
    
    //fill in rows
    for(int i = 0; i < 8; i++)
    {
        
        if(i == 0)
        {
            aRow = dR0;
        }
        else if(i == 1)
        {
            aRow = dR1;
        }
        else if(i == 2)
        {
            aRow = dR2;
        }
        else if(i == 3)
        {
            aRow = dR3;
        }
        else if(i == 4)
        {
            aRow = dR4;
        }
        else if(i == 5)
        {
            aRow = dR5;
        }
        else if(i == 6)
        {
            aRow = dR6;
        }
        else if(i == 7)
        {
            aRow = dR7;
        }
        else if(i == 8)
        {
            aRow = dR8;
        }
        else if(i == 9)
        {
            aRow = dR9;
        }
        else if(i == 10)
        {
            aRow = dR10;
        }
        else if(i == 11)
        {
            aRow = dR11;
        }
        else if(i == 12)
        {
            aRow = dR12;
        }
        else
        {
            aRow = dR13;
        }
        
        //fill in columns
        for(int j = 0; j < 8; j++)
        {
            
            if(j == 0)
            {
                aColumn = dC0;
            }
            else if(j == 1)
            {
                aColumn = dC1;
            }
            else if(j == 2)
            {
                aColumn = dC2;
            }
            else if(j == 3)
            {
                aColumn = dC3;
            }
            else if(j == 4)
            {
                aColumn = dC4;
            }
            else if(j == 5)
            {
                aColumn = dC5;
            }
            else if(j == 6)
            {
                aColumn = dC6;
            }
            else
            {
                aColumn = dC7;
            }
            
            //Updates the pieces in the real board to match the display board
            if(board[i][j].piece == nullptr)
            {
                displayBoard[aRow][aColumn] = ' ';
            }
            
            else if(board[i][j].piece->name.compare("white") == 0)
            {
                displayBoard[aRow][aColumn] = 'W';
            }
            
            else if(board[i][j].piece->name.compare("black") == 0)
            {
                displayBoard[aRow][aColumn] = 'B';
            }
        }
    }
    
    
    for(int i = 0; i < 34; i++)
    {
        
        cout<<endl;
        
        for(int j = 0; j < 53; j++)
        {
            
            cout<<displayBoard[i][j];
            
        }
        
    }
    cout << endl;
}
