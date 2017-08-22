//
//  main.cpp
//  if
//
//  Created by kim on 2017. 7. 27..
//  Copyright © 2017년 kim. All rights reserved.
//

//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    시험 점수를 입력받아 90 ~ 100점은 A, 80 ~ 89점은 B, 70 ~ 79점은 C, 60 ~ 69점은 D, 나머지 점수는 F를 출력하는 프로그램을 작성하시오.
    
//    int N;
//    cin >> N;
//    
//    if(N >= 90 && N <= 100) {
//        cout << "A" << endl;
//    } else if(N >= 80 && N < 90) {
//        cout << "B" << endl;
//    } else if(N >= 70 && N < 80) {
//        cout << "C" << endl;
//    } else if(N >= 60 && N < 70) {
//        cout << "D" << endl;
//    } else {
//        cout << "F" << endl;
//    }

    
//    세 정수 A, B, C가 주어진다. 이 때, 두 번째로 큰 정수를 출력하는 프로그램을 작성하시오.
    
//    int A, B, C;
//    
//    cin >> A >> B >> C;
//    
//    if(A > B) {
//        int temp = A;
//        A = B;
//        B = temp;
//    }
//    
//    if( A > C) {
//        int temp = A;
//        A = C;
//        C = temp;
//    }
//    
//    if( B > C) {
//        int temp = B;
//        B = C;
//        C = temp;
//    }
//    
//    cout << B << endl;

//    int A[10001] = {};
//    
//    int N, X;
//    cin >> N >> X;
//    
//    for (int i = 0; i < N; i++) {
//        cin >> A[i];
//        if(A[i] < X) {
//            cout << A[i] << ' ';
//        }
//    }
    
//    세준이는 기말고사를 망쳤다. 세준이는 점수를 조작해서 집에 가져가기로 했다. 일단 세준이는 자기 점수 중에 최대값을 골랐다. 이 값을 M이라고 한다. 그리고 나서 모든 점수를 점수/M*100으로 고쳤다.
//    
//    예를 들어, 세준이의 최고점이 70이고, 수학점수가 50이었으면 수학점수는 50/70*100이 되어 71.43점이 된다.
//    
//    세준이의 성적을 위의 방법대로 새로 계산했을 때, 새로운 평균을 구하는 프로그램을 작성하시오.
    
//    int d[1001] = {0};
//    int N = 0, max = 0;
//    int average = 0;
//    
//    cin >> N;
//    
//    for(int i = 0; i < N; i++) {
//        cin >> d[i];
//        
//        average += d[i];
//        
//        if(max < d[i]) {
//            max = d[i];
//        }
//    }
//    
//    printf("%.2f\n", (float)average / (float)N / (float)max * 100);
    
//    대학생 새내기들의 90%는 자신이 반에서 평균은 넘는다고 생각한다. 당신은 그들에게 슬픈 진실을 알려줘야 한다.
    
//    int d[1001] = {0};
//    int C = 0, N = 0, T = 0;
//    float average = 0;
//    
//    cin >> C;
//    
//    for(int i = 0; i < C; i++) {
//        cin >> N;
//        
//        for(int i = 0; i < N; i++) {
//            cin >> d[i];
//            average += (float)d[i];
//        }
//
//        average /= (float)N;
//        
//        for(int i = 0; i < N; i++) {
//            if(d[i] > average) {
//                T++;
//            }
//        }
//        
//        printf("%.3f\n", ((float)T / (float)N) * 100);
//        
//        T = 0;
//        average = 0;
//    }
//    
//    return 0;
//}

#include <stdio.h>
int main(int argc, const char * argv[])
{
    int T ;
    int N ;
    int score[1000] ;
    
    scanf("%d", &T);
    
    while (T--)
    {
        float average = 0 ;
        int count = 0 ;
        scanf("%d", &N);
        
        for(int i=0 ; i<N ; i++)
        {
            scanf("%d", &score[i]);
            average += score[i] ;
        }
        average /= N ;
        
        for(int i=0 ; i<N ; i++)
        {
            if((float)score[i] > average)
            {
                count++ ;
            }
        }
        printf("%.3f%%\n", (float)count/N * 100);
    }
    return 0;
}



//#include <iostream>
//
//using namespace std;
//
//int main()
//{
