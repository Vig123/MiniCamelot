//
//  Piece.hpp
//  test
//
//  Created by Vighneshan Moorthy on 11/29/17.
//  Copyright © 2017 Vighneshan Moorthy. All rights reserved.
//

#ifndef Piece_hpp
#define Piece_hpp

#include <stdio.h>
#include <string>

using namespace std;


class Piece
{
public:
    Piece(string, int);
    Piece();
    ~Piece();
    
    string name;
    int player;
};

#endif /* Piece_hpp */
