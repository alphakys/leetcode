//
// Created by alpha on 23. 10. 2.
//

#define EXPORT
#include <stdio.h>
#include <iostream>

using namespace std;

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

    struct S {
        int id;
        int user_id;
    };

    EXPORT
    void getStruct(S* s)
    {
        //printf("%d %d", s->id, s->user_id);
        cout << s->id <<" " << s->user_id;
        // cout << "id : " << id << " user_id : " << s->user_id;
    }

}

