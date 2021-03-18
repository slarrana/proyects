extern _ft_strlen
extern _malloc
extern _ft_strcpy

segment .text
	global _ft_strdup

_ft_strdup:
	push rdi
	call _ft_strlen
	inc rax
	mov rdi, rax
	call _malloc
	jc error
	mov rdi, rax
	pop rsi
	call _ft_strcpy
	jc error
	ret
error:
	mov rax, 0
	ret

