segment .text
	global _ft_strcpy

	_ft_strcpy:
		mov rcx, 0
		jmp while
	
	while:
		mov bl, byte [rsi + rcx]
		mov byte [rdi + rcx], bl
		cmp bl, 0
		je return
		add rcx, 1
		jmp while
	
	return:
		mov rax, rdi
		ret
