Assembly
========

Introduction
------------

- Tight coupling between code and machine instructions
- Not portable, code is written for a specific ISA
- Can be extremely efficient if optimized properly

Registers
---------

- Internal CPU data storage
- Very limited in number
- Hold operands for asm instructions

Instructions
------------

- Generally operate on registers
- May perform other functions `call`, `ret`, `syscall`

ISA
---

- Instruction set architecture
- Set of instructions provided by a CPU
- Examples inlcude `x86`, `x86_64`, `ARM`, and `ARM64`

Hello World
-----------

```asm
.LC0:
 .string "Hello, world!\n"
 .globl _start
_start:
 leaq .LC0(%rip), %rsi
 movl $14, %edx
 mov $1, %rax
 syscall
 xorl %edi, %edi
 mov $60, %rax
 syscall
```

Functions
---------

- `call` and `ret` perform jumps and adjust state
- `push` and `pop` access stack
- `rax` register is used for return value is [x64 calling convention](https://raw.githubusercontent.com/wiki/hjl-tools/x86-psABI/x86-64-psABI-1.0.pdf)

Common Function Registers
-------------------------

Register  Purpose
--------  -------
%rax      1st return register
%rdi      used to pass 1st argument to functions
%rsi      used to pass 2nd argument to functions
%rdx      used to pass 3rd argument to functions
%rcx      used to pass 4th argument to functions
%rsp      stack pointer

Call Function
-------------

```asm
.LC0:
 .string "Hello, world!\n"
 .globl _start
get_message:
 leaq .LC0(%rip), %rax
 ret
_start:
 call get_message
 mov %rax, %rsi
 movl $14, %edx
 mov $1, %rax
 syscall
 xorl %edi, %edi
 mov $60, %rax
 syscall
```
