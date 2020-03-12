#include "stdlib.h"

#include "platform/syscall.h"

#define HANDLERS 32
static void (*_exit_handlers[HANDLERS])(void);

void exit(int exit_code) {
    for (int i = 0; i < HANDLERS; ++i) {
        if (_exit_handlers[i]) {
            _exit_handlers[i]();
        }
    }

    _exit(exit_code);
    while (1) {}
}

int atexit(void (*func)(void)) {
    static int i = HANDLERS - 1;

    if (i < 0) {
        return 1;
    }

    _exit_handlers[i--] = func;
    return 0;
}
