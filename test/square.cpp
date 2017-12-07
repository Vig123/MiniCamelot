//
//  square.cpp
//  test
//
//  Created by Vighneshan Moorthy on 11/28/17.
//  Copyright © 2017 Vighneshan Moorthy. All rights reserved.
//

#include "square.hpp"

Square::Square(void)
{
    piece = nullptr;	//initialize the square to null
}

Square::Square(Piece *p){
    
    piece = p;
    
}


Square::~Square(void)
{
}
