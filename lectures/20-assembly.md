# Assembly

## Introduction

- Tight coupling between code and machine instructions
- Not portable, code is written for a specific ISA
- Can be extremely efficient if optimized properly

## Registers

- Internal CPU data storage
- Very limited in number
- Hold operands for asm instructions

## Instructions

- Generally operate on registers
- May perform other functions `call`, `ret`, `syscall`

## ISA

- Instruction set architecture
- Set of instructions provided by a CPU
- Examples include `x86`, `x86_64`, `ARM`, and `ARM64`

## System Call

- Used to run kernel code from userspace
- `syscall` instruction triggers kernel
- Values are picked up from appropriate registers

## System Call Registers

Register Purpose

---

%rax System call number
%rdi 1st parameter
%rsi 2nd parameter
%rdx 3rd parameter
%r10 4th parameter
%r8 5th parameter
%r9 6th parameter

---

```asm
.globl _start
_start:
 mov $1, %rdi
 leaq message(%rip), %rsi
 mov $14, %rdx
 mov $1, %rax
 syscall
 xor %rdi, %rdi
 mov $60, %rax
 syscall

message:
 .string "Hello, world!\n"
```

## Functions

- `call` and `ret` perform jumps and adjust state
- `push` and `pop` access stack
- `rax` register is used for return value in [x64 calling convention](https://raw.githubusercontent.com/wiki/hjl-tools/x86-psABI/x86-64-psABI-1.0.pdf)

## Common Function Registers

Register Purpose

---

%rax 1st return register
%rdi used to pass 1st argument to functions
%rsi used to pass 2nd argument to functions
%rdx used to pass 3rd argument to functions
%rcx used to pass 4th argument to functions
%rsp stack pointer

---

```asm
.globl _start
_start:
 call get_message
 mov $1, %rdi
 mov %rax, %rsi
 mov $14, %rdx
 mov $1, %rax
 syscall
 xor %rdi, %rdi
 mov $60, %rax
 syscall

get_message:
 leaq message(%rip), %rax
 ret

message:
 .string "Hello, world!\n"
```
