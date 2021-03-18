segment .text
	global _ft_strlen

	_ft_strlen:
		mov rax, 0
		jmp while

	return:
		ret

	while:
		cmp byte [rdi + rax], 0
		je return
		add rax, 1
		jmp while
