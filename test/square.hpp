//
//  square.hpp
//  test
//
//  Created by Vighneshan Moorthy on 11/28/17.
//  Copyright © 2017 Vighneshan Moorthy. All rights reserved.
//

#ifndef square_hpp
#define square_hpp

#include <stdio.h>
#include "Piece.hpp"

class Square
{
public:
    Square(Piece*);
    Square();
    ~Square();
    
    Piece* piece;	
};

#endif /* square_hpp */
