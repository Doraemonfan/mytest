	.file	"rsum.c"
	.text
	.globl	rsum
	.type	rsum, @function
rsum:
.LFB0:
	.cfi_startproc
	testq	%rsi, %rsi
	jle	.L3
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	subq	$1, %rsi
	leaq	8(%rdi), %rdi
	call	rsum
	addq	(%rbx), %rax
	jmp	.L2
.L3:
	.cfi_def_cfa_offset 8
	.cfi_restore 3
	movl	$0, %eax
	ret
.L2:
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	popq	%rbx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE0:
	.size	rsum, .-rsum
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
