.text
.globl CountChars_
CountChars_:
	pushq %rsi
	movb %sil,%cl
	movq %rdi,%rsi
	xorq %rdx,%rdx
	xorq %r8,%r8
loop:
	lodsb
	testb %al,%al
	jz end
	cmpb %cl,%al
	sete %r8b
	addq %r8,%rdx
	jmp loop
end:
	movq %rdx,%rax
	popq %rsi
	ret
