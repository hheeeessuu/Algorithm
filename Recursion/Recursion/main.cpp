//
//  main.cpp
//  Recursion
//
//  Created by kim on 2017. 7. 26..
//  Copyright © 2017년 kim. All rights reserved.
//

#include <stdio.h>

char A[10];

void Binary(int n)
{
    if(n < 1)
        printf("%s\n", A); // A는 전역 변수이다.
    else {
        A[n-1] = 0;
        Binary(n-1);
        A[n-1] = 1;
        Binary(n-1);
    }
}

void TowersOfHanoi(int n, char from, char to, char temp)
{
    if(n == 1) {
        printf("Move disk 1 from %c to %c \n", from, to);
        return;
    }
    TowersOfHanoi(n - 1, from, temp, to);
    
    printf("Move disk %d from %c to %c \n", n, from, to);
    
    TowersOfHanoi(n - 1, temp, to, from);
}

int main()
{
//    Binary(10);
    TowersOfHanoi(4, 'A', 'C', 'B');
    printf("\n");
    
    return 0;
}
