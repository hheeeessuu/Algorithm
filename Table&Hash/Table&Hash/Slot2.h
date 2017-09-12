//
//  Slot2.h
//  Table&Hash
//
//  Created by kim on 2017. 9. 8..
//  Copyright © 2017년 kim. All rights reserved.
//

#ifndef Slot2_h
#define Slot2_h

#include "Person.h"

typedef int Key;
typedef Person *Value;

typedef struct _slot {
    Key key;
    Value val;
} Slot;

#endif /* Slot2_h */
