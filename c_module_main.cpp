//
// Created by alpha on 23. 10. 2.
//
#define EXPORT
#include <stdio.h>
#include <iostream>

using namespace std;

struct s{
    int id;
    int user_id;
} s;

extern "C"
{

    EXPORT
    int add_lib(int a, int b)
    {
        return a+b;
    }

    EXPORT
    void sub(int a, int b, int* ptr)
    {
        *ptr = a+b;
        printf("%d", *ptr);

    }
    EXPORT
    void get_struct(struct s* s)
    {
        cout << "id : " << s->id << " user_id : " << s->user_id;

    }


}