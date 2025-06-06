
/* Copyright (C) 2002, David McCullough <davidm@snapgear.com> */
/* This file is released under the LGPL, any version you like */

#include <features.h>
#include <jmpbuf-offsets.h>

.globl _setjmp;
.type  _setjmp,@function
.align 4;

_setjmp:
	moveal	%sp@(4), %a0
	movel	%sp@(0), %a0@(JB_PC)
	moveml	%d2-%d7/%a2-%a7, %a0@(JB_REGS)
#if defined(__mcffpu__) && defined(__UCLIBC_HAS_FPU__)
	fmovemd %fp2-%fp7, %a0@(JB_FPREGS)
#elif defined(__HAVE_68881__)
	fmovemx %fp2-%fp7, %a0@(JB_FPREGS)
#endif
	clrl	%d0
	movl	%d0, JB_SIZE(%a0) /* No signal mask set.  */
	rts


