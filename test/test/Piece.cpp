//
//  Piece.cpp
//  test
//
//  Created by Vighneshan Moorthy on 11/29/17.
//  Copyright © 2017 Vighneshan Moorthy. All rights reserved.
//

#include "Piece.hpp"


Piece::Piece(void){}
Piece::~Piece(void){}

Piece::Piece(string t, int p)
{
    name = t;
    player = p;
}
