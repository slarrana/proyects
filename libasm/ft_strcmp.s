segment .text
	global _ft_strcmp

	_ft_strcmp:
		jmp while

	while:
		mov bl, byte [rdi]
		mov cl, byte [rsi]
		cmp bl, cl
		jne return
		cmp bl, 0
		je return
		cmp cl, 0
		je return
		inc rdi
		inc rsi
		jmp while

	return:
		movzx rax, bl
		movzx rbx, cl
		sub rax, rbx
		ret
