#include "stdbool.h"
#include "stdlib.h"

void do_thing() {
    int a = 1;
    (void)a;
}

void do_more() {
    int *b = 0;
    (void)b;
}

int main2() {
    bool a = false;
    bool b = !a;
    (void)b;

    atexit(do_more);
    atexit(do_thing);

    exit(100);
    return 50;
}
