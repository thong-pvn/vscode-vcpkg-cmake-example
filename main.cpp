#include <sqlite3.h>
#include <iostream>

int main(int argc, char* argv[]) {
    printf("SQLITE3 = %s\n", sqlite3_libversion());
    return 0;
}