# 1 "switch-linux.s"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "switch-linux.s"
# 39 "switch-linux.s"
# 1 "copyright.h" 1
# 40 "switch-linux.s" 2
# 1 "switch.h" 1
# 21 "switch.h"
# 1 "copyright.h" 1
# 22 "switch.h" 2
# 41 "switch-linux.s" 2



        .text
        .align 2

        .globl ThreadRoot
# 57 "switch-linux.s"
ThreadRoot:
        pushl %ebp
        movl %esp,%ebp
        pushl %edx
        call %ecx
        call %esi
        call %edi

        # NOT REACHED
        movl %ebp,%esp
        popl %ebp
        ret
# 83 "switch-linux.s"
        .comm _eax_save,4

        .globl SWITCH
SWITCH:
        movl %eax,_eax_save # save the value of eax
        movl 4(%esp),%eax # move pointer to t1 into eax
        movl %ebx,8(%eax) # save registers
        movl %ecx,12(%eax)
        movl %edx,16(%eax)
        movl %esi,24(%eax)
        movl %edi,28(%eax)
        movl %ebp,20(%eax)
        movl %esp,0(%eax) # save stack pointer
        movl _eax_save,%ebx # get the saved value of eax
        movl %ebx,4(%eax) # store it
        movl 0(%esp),%ebx # get return address from stack into ebx
        movl %ebx,32(%eax) # save it into the pc storage

        movl 8(%esp),%eax # move pointer to t2 into eax

        movl 4(%eax),%ebx # get new value for eax into ebx
        movl %ebx,_eax_save # save it
        movl 8(%eax),%ebx # retore old registers
        movl 12(%eax),%ecx
        movl 16(%eax),%edx
        movl 24(%eax),%esi
        movl 28(%eax),%edi
        movl 20(%eax),%ebp
        movl 0(%eax),%esp # restore stack pointer
        movl 32(%eax),%eax # restore return address into eax
# movl %eax,4(%esp) # copy over the ret address on the stack
        movl %eax,0(%esp)
 #This is a bug, the offset for return address should be 0, not 4.
 # -- ptang, Sep/1/03, at UALR

        movl _eax_save,%eax

        ret