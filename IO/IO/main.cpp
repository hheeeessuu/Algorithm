//
//  main.cpp
//  IO
//
//  Created by kim on 2017. 7. 17..
//  Copyright © 2017년 kim. All rights reserved.
//

#include <iostream>
using namespace std;

int main ()
{

    // 10172번
    // 아래 예제와 같이 개를 출력하시오.
    
//    cout << "|\\_/|" << '\n';
//    cout << "|q p|   /}" << '\n';
//    cout << "( 0 )\"\"\"\\" << '\n';
//    cout << "|\"^\"`    |" << '\n';
//    cout << "||_/=\\\\__|" << '\n';

    // 11718번 그대로 출력하기
    // 입력 받은 대로 출력하는 프로그램을 작성하시오.
    
    string str;
        
    for (int i = 0 ; i < 100 ; i++)
    {
        getline(cin, str);
        cout<<str<<endl;
    }
        
    return 0;
    
}
