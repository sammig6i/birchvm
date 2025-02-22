/* birchvm.h */
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#include <birchutils/birchutils.h>

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int int64;

#define $1 (int8 *)
#define $2 (int16)
#define $4 (int32)
#define $8 (int64)
#define $c (char *)
#define $i (int)

typedef unsigned short int Reg;
struct s_registers {
    Reg ax;
    Reg bx;
    Reg cx;
    Reg dx;
    Reg sp; // Stack pointer
    Reg ip; // Instruction pointer
};
typedef struct s_registers Registers;

struct s_cpu {
    Registers r;
};
typedef struct s_cpu CPU;

enum e_opcode {
    mov = 0x01,
    nop = 0x02
};
typedef enum e_opcode Opcode;

struct s_instrmap {
    Opcode o;
    int8 size;
};
typedef struct s_instrmap IM;

typedef int8 Args;
struct s_instruction {
    Opcode o;
    Args a[]; // 0-2 bytes for arguments
};
typedef struct s_instruction Instruction;

typedef int8 Stack[((unsigned int)(-1))];
typedef Instruction Program;

struct s_vm {
    CPU c;
    Stack s;
    Program *p;
};
typedef struct s_vm VM;

static Opcode opc;
static IM instrmap[] = {
    { mov, 0x03 },
    { nop, 0x01 }
};

// TODO start at 44:42 "let's make a construct function for creating a virtual machine"