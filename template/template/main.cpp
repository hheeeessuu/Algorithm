//
//  main.cpp
//  template
//
//  Created by kim on 2017. 8. 4..
//  Copyright © 2017년 kim. All rights reserved.
//

#include <iostream>

// 템플릿 파마미터 3개
///////////////////////////////////////////////////////////////////////
/*
using namespace std;

template <typename R, typename T, typename U>
R const add (T const &a, U const &b)
{
    return a + b;
}

int main()
{
    int i = 5;
    double j = 10.2;
    
    cout << i << " + " << j << " = " << add<double>(i, j) << endl;
    
    return 0;
}
*/

///////////////////////////////////////////////////////////////////////
// 템플릿 특수화
/*
#include <iostream>
#include <string.h>

using namespace std;

template <typename T>
T const add (T const &a, T const &b)
{
    cout << "typename T" << endl;
    return a+b;
}

template<>
char* const add<char*> (char* const &a, char* const &b)
{
    cout << "specialized" << endl;
    return strcat(a, b);
}

char * const add(char* const &a, char* const &b)
{
    cout << "overloading" << endl;
    return strcat(a, b);
}

int main()
{
    int i = 5;
    int j = 10;
    
    double a = 5.1;
    double b = 10.2;
    
    char m[20] = "Hello";
    char n[20] = "World";
    
    cout << i << " + " << j << " = " << add(i, j) << endl;
    cout << endl;
    cout << a << " + " << b << " = " << add(i, j) << endl;
    cout << endl;
    cout << add<char*>(m, n) << endl;
    cout << endl;
    cout << add(m, n) << endl;
    cout << endl;
    
    return 0;
}
 */

///////////////////////////////////////////////////////////////////////
// 템플릿 클래스 / 템플릿 파라미터
/*
#include <iostream>
#include <vector>

using namespace std;

template <typename T, int init>
class MyArray
{
private :
    vector<T> list;
public :
    MyArray()
    {
        for (int i = 0; i < init; i++) {
            list.push_back(i);
        }
    }
    
    void add_list(T const&);
    void delete_last_list();
    void show_list();
};

template <typename T, int init>
void MyArray<T, init>::add_list(T const &element)
{
    list.push_back(element);
}

template <typename T, int init>
void MyArray<T, init>::delete_last_list()
{
    list.pop_back();
}

template <typename T, int init>
void MyArray<T, init>::show_list()
{
    cout << "[MyArray list look up]" << endl;
    for(typename vector<T>::iterator i = list.begin(); i != list.end(); ++i) {
        cout << *i << endl;
    }
}

int main()
{
    MyArray<int, 3> array1;
    array1.add_list(1);
    array1.add_list(2);
    array1.add_list(3);
    array1.add_list(4);
    array1.add_list(5);
    
    array1. show_list();
    
    array1.delete_last_list();
    array1.delete_last_list();
    
    array1.show_list();
    
    MyArray<double, 4> array2;
    array2.add_list(1.1);
    array2.add_list(2.2);
    array2.add_list(3.3);
    array2.add_list(4.4);
    array2.add_list(5.5);
    
    array2.show_list();
    
    array2.delete_last_list();
    array2.delete_last_list();
    
    array2.show_list();
    
    return 0;
}
 */

///////////////////////////////////////////////////////////////////////
// 클래스 템플릿의 특수화

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MyArray
{
private :
    vector<T> list;
    
public :
    void add_list(T const&);
    void delete_last_list();
    void show_list();

};

template <typename T>
void MyArray<T>::add_list(T const& element)
{
    list.push_back(element);
}

template <typename T>
void MyArray<T>::delete_last_list()
{
    list.pop_back();
}

template <typename T>
void MyArray<T>::show_list()
{
    cout << "[MyArray list look up]" << endl;
    for(typename vector<T>::iterator i = list.begin(); i != list.end(); ++i) {
        cout << *i << endl;
    }
}

template<>
class MyArray<int>
{
private :
    vector<int> list;
public :
    void add_list(int const&);
    void delete_last_list();
    void show_list();
};

void MyArray<int>::add_list(int const& element)
{
    list.push_back(element);
}

void MyArray<int>::delete_last_list()
{
    list.pop_back();
}

void MyArray<int>::show_list()
{
    cout << "[MyArray list look up (specialization for int)]" << endl;
    for(typename vector<int>::iterator i = list.begin(); i != list.end(); ++i){
        cout << *i << endl;
    }
}

int main()
{
    MyArray<int> array1;
    array1.add_list(1);
    array1.add_list(2);
    array1.add_list(3);
    array1.add_list(4);
    array1.add_list(5);
    
    array1.show_list();
    array1.delete_last_list();
    array1.delete_last_list();
    
    array1.show_list();
    
    MyArray<double> array2;
    array2.add_list(1.1);
    array2.add_list(2.2);
    array2.add_list(3.3);
    array2.add_list(4.4);
    array2.add_list(5.5);
    
    array2.show_list();
    array2.delete_last_list();
    array2.delete_last_list();
    
    array2.show_list();
    
    return 0;   
    
}











