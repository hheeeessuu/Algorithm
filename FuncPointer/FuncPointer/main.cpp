//
//  main.cpp
//  FuncPointer
//
//  Created by kim on 2017. 8. 1..
//  Copyright © 2017년 kim. All rights reserved.
//

//#include <stdio.h>
//
//void SimpleAdder(int n1, int n2)
//{
//    printf("%d + %d = %d \n", n1, n2, n1 + n2);
//}
//
//void ShowString(char *str)
//{
//    printf("%s \n", str);
//}
//
//int main(void)
//{
//    char *str = "Function Pointer";
//    int num1 = 10, num2 = 20;
//    
//    void (*fptr1)(int, int) = SimpleAdder;
//    void (*fptr2)(char *) = ShowString;
//    
//    // 함수 포인터 변수에 의한 호출
//    fptr1(num1, num2);
//    fptr2(str);
//    
//    return 0;
//}

//#include <stdio.h>
//
//int WhoIsFirst(int age1, int age2, int (*cmp)(int n1, int n2))
//{
//    return cmp(age1, age2);
//}
//
//int OlderFirst(int age1, int age2)
//{
//    if(age1 > age2){
//        return age1;
//    } else if (age1 < age2) {
//        return age2;
//    } else {
//        return 0;
//    }
//}
//
//int YoungerFirst(int age1, int age2)
//{
//    if(age1 < age2) {
//        return age1;
//    } else if (age1 > age2) {
//        return age2;
//    } else {
//        return 0;
//    }
//}
//
//int main(void)
//{
//    int age1 = 20;
//    int age2 = 30;
//    int first;
//    
//    printf("입장순서 1 \n");
//    first = WhoIsFirst(age1, age2, OlderFirst);
//    printf("%d세와 %d세 중 %d세가 먼저 입장! \n\n", age1, age2, first);
//    
//    printf("입장순서 2 \n");
//    first = WhoIsFirst(age1, age2, YoungerFirst);
//    printf("%d세와 %d세 중 %d세가 먼저 입장! \n\n", age1, age2, first);
//    return 0;
//}


//////////////////////////////////////////////////////////////////////////
// void 포인터

//#include <stdio.h>
//
//void SoSimpleFunc(void)
//{
//    printf("I'm so simple");
//}
//
//int main(void)
//{
//    int num = 20;
//    void *ptr;
//    
//    ptr = &num;     // 변수 num의 주소 값 저장.
//    printf("%p \n", ptr);
//    
//    ptr = (void *)SoSimpleFunc; // 함수 SoSimpleFunc의 주소 값 저장
//    printf("%p \n", ptr);
//    return 0;
//}

//////////////////////////////////////////////////////////////////////////
//main 함수로의 인자전달

//#include <stdio.h>
//
//int main(int argc, char *argv[])
//{
//    printf("전달된 문자열의 수 : %d \n", argc);
//    
//    for(int i = 0; i < argc; i++) {
//        printf("%d번째 문자열 : %s \n", i + 1, argv[i]);
//    }
//    
//    return 0;
//}

//#include <stdio.h>
//
//void ShowAllString(int argc, char *argv[])
//{
//    int i = 0;
//    for(i = 0; i < argc; i++){
//        printf("%s \n", argv[i]);
//    }
//}
//
//int main(void)
//{
//    char * str[3] = {
//        "C Programming",
//        "C++ Programming",
//        "JAVA Programming"
//    };
//    
//    ShowAllString(3, str);
//    return 0;
//}

//////////////////////////////////////////////////////////////////////////
// 문자열을 반환하는 함수를 정의하는 문제의 해결

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//char* ReadUserName(void)
//{
//    char name[30];
//    printf("What's your name?");
//    gets(name);
//    return name;
//}

char* ReadUserName(void)
{
    char *name = (char *)malloc(sizeof(char) * 30);
    printf("What's your name?");
    gets(name);
    return name;
}

int main(void)
{
//    char *name1;
//    char *name2;
//    name1 = ReadUserName();
//    printf("name1: %s \n", name1);
//    name2 = ReadUserName();
//    printf("name2: %s \n", name2);
//    
//    printf("again name1: %s \n", name1);
//    printf("again name2: %s \n", name2);
//    free(name1);
//    free(name2);

    float rad_f = M_PI / 4.0f;
    float sin_f = sinf(rad_f);
    float cos_f = cosf(rad_f);
    float tan_f = tanf(rad_f);
    
    double rad_d = M_PI / 4.0f;
    double sin_d = sin(rad_d);
    double cos_d = cos(rad_d);
    double tan_d = tan(rad_d);
    
    printf("sin 45 (float) : %f\n", sin_f);
    printf("cos 45 (float) : %f\n", cos_f);
    printf("tan 45 (float) : %f\n", tan_f);
    printf("sin 45 (double) : %lf\n", sin_d);
    printf("cos 45 (double) : %lf\n", cos_d);
    printf("tan 45 (double) : %lf\n", tan_d);
    
    
    return 0;
}


