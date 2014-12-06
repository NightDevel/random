#!/bin/bash

if [ "x$1" = "x" ]; then
    echo "$0 op_file"
    exit 0
fi
cat| fmt -w 80 > /tmp/.file 
echo "
#include <stdio.h>
#if 0
#ifdef DEBUG
#define dprintf(fmt, ...) do { fprintf(stderr, fmt, __VA_ARGS__); } while (0)
#else
#define dprintf(fmt, ...) 
#endif
#endif
#ifdef DEBUG
#define dprintf(...) printf(__VA_ARGS__)
#else
#define dprintf(...) 
#endif

int main()
{
    int t;
    scanf(\"%d\", &t);
    while (t--){
    }
    return 0;
}
">>/tmp/.file
cp /tmp/.file $1
