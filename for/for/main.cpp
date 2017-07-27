//
//  main.cpp
//  for
//
//  Created by kim on 2017. 7. 18..
//  Copyright © 2017년 kim. All rights reserved.
//

//#include <stdio.h>
//
//int main()
//{
//    int N = 0;
//    scanf("%d", &N);
//    
//    for(int i = N; i > 0; i--) {
//        printf("%d\n", i);
//    }
//    
//    return 0;
//}

// 구구단

//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    int N;
//    cin >> N;
//    
//    for(int i = 1; i <= 9; i++)
//    {
//        cout << N << " * " << i << " = " << N * i << endl;
//    }
//    
//    return 0;
//}

// 별찍기 - 1

//#include <iostream>
//
//using namespace std;
//
//int main ()
//{
//    int N;
//    cin >> N;
//    
//    for(int i = 0; i < N; i++)
//    {
//        for(int j = 0 ; j <= i; j++)
//        {
//            cout << "*";
//        }
//        cout << '\n';
//    }
//    return 0;
//}

// 별찍기 - 2
//#include <iostream>
//
//using namespace std;
//
//int main ()
//{
//        int N;
//        cin >> N;
//    
//        for(int i = 0; i < N; i++)
//        {
//            for(int j = N - 1 ; j >= 0; j--)
//            {
//                if(j <= i) {
//                    cout << "*";
//                } else {
//                    cout << " ";
//                }
//            }
//            cout << '\n';
//        }
//
//    return 0;
//}

// 별찍기 - 3
//#include <iostream>
//
//using namespace std;
//
//int main ()
//{
//    int N;
//    cin >> N;
//    
//    for(int i = 0; i < N; i++)
//    {
//        for(int j = N - i ; j > 0; j--)
//        {
//            cout << "*";
//        }
//        cout << '\n';
//    }
//    
//    return 0;
//}

// 별찍기 - 4

//#include <iostream>
//
//using namespace std;
//
//int main ()
//{
//    int N;
//    cin >> N;
//    
//    for(int i = 0; i < N; i++)
//    {
//        for(int j = 0; j < N; j++)
//        {
//            if(j >= i) {
//                cout << "*";
//            } else {
//                cout << " ";
//            }
//        }
//        cout << '\n';
//    }
//    
//    return 0;
//}

// 오늘은 2007년 1월 1일 월요일이다. 그렇다면 2007년 x월 y일은 무슨 요일일까? 이를 알아내는 프로그램을 작성하시오.
//첫째 줄에 빈 칸을 사이에 두고 x(1≤x≤12)와 y(1≤y≤31)이 주어진다. 참고로 2007년에는 1, 3, 5, 7, 8, 10, 12월은 31일까지, 4, 6, 9, 11월은 30일까지, 2월은 28일까지 있다.

//#include <iostream>
//
//using namespace std;
//
//int main ()
//{
//    int x, y;
//    cin >> x >> y;
//    
//    for (int i = 1; i < x; i++) {
//        switch (i) {
//            case 1 :
//            case 3 :
//            case 5 :
//            case 7 :
//            case 8 :
//            case 10 :
//            case 12 :
//                y += 31;
//                break;
//            case 4 :
//            case 6 :
//            case 9 :
//            case 11 :
//                y += 30;
//                break;
//            case 2 :
//                y += 28;
//                
//            default:
//                break;
//        }
//    }
//    
//    y %= 7;
//    
//// 첫째 줄에 x월 y일이 무슨 요일인지에 따라 SUN, MON, TUE, WED, THU, FRI, SAT중 하나를 출력한다.
//    switch (y) {
//        case 0:
//            cout << "SUN" << endl;
//            break;
//        case 1:
//            cout << "MON" << endl;
//            break;
//        case 2:
//            cout << "TUE" << endl;
//            break;
//        case 3:
//            cout << "WED" << endl;
//            break;
//        case 4:
//            cout << "THU" << endl;
//            break;
//        case 5:
//            cout << "FRI" << endl;
//            break;
//        case 6:
//            cout << "SAT" << endl;
//            break;
//            
//        default:
//            break;
//    }
//    
//    return 0;
//
//}

//n이 주어졌을 때, 1부터 n까지 합을 구하는 프로그램을 작성하시오.

//#include <iostream>
//
//using namespace std;
//
//int main ()
//{
//    int n = 0;
//    int sum = 0;
//    cin >> n;
//    
//    for(int i = 1; i <= n; i++){
//        sum += i;
//    }
//    
//    cout << sum << endl;
//    
//    return 0;
//
//}

// N개의 숫자가 공백 없이 쓰여있다. 이 숫자를 모두 합해서 출력하는 프로그램을 작성하시오.

//#include <iostream>
//
//
//using namespace std;
//
//int main ()
//{
//    int n = 0;
//    string num;
//    int temp;
//    
//    cin >> n;
//    cin >> temp;
//    
//    num = to_string(temp);
//    temp = 0;
//    
//    for(int i = 0; i < n; i++) {
//        temp += num[i] - '0';
//    }
//    
//    cout << temp << endl;
//    
//    return 0;
//    
//}

//#include<stdio.h>
//
//int main(){
//    int testCase = 0,temp=0,sum=0;
//    scanf("%d", &testCase);
//    for (int i = 0; i < testCase; i++){
//        
//        scanf("%1d", &temp);//%d 사이에 수를 넣으면, 그 길이 만큼 입력을 받게 된다.
//        sum = sum + temp;
//    }
//    printf("%d", sum);
//    return 0;
//}

//알파벳 소문자와 대문자로만 이루어진 길이가 N인 단어가 주어진다.
//
//한 줄에 10글자씩 끊어서 출력하는 프로그램을 작성하시오.

#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    
    while(s.length() != 0) {
        cout << s.substr(0, 10) << endl;
        s.erase(0, 10);
    }
}

