//
// Created by kyoto on 09.10.23.
//

#include "kernel/types.h"
#include "kernel/syscall.h"
#include "user/user.h"

int success;

void test1();

void test2();

int main(void) {
    printf("tests started\n");
    printf("dump2 syscall found. Start testing\n");
    success = 0;
    test1();
    test2();
    printf("2 tests were run. %d tests passed\n", success);
    exit(0);
}


void test1() {
    uint64 value;
    printf("test 1 started\n");
    int error = mydiv(4, 2, &value);
    if (error != 0) {
        printf("[ERROR]");
        return;
    }
    if (value != 2) {
        printf("[ERROR] expected: %d, found: %d\n", 2, value);
        return;
    }
    success++;
    printf("test 1 finished\n");
}

void test2() {
    uint64 value;
    printf("test 2 started\n");
    int error = mydiv(1, 0, &value);
    if (error == -1) {
        printf("[ERROR] division by zero.\n");
        success++;
        return;
    }
    printf("test 2 finished\n");
}