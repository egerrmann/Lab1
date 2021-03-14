#include <iostream>

int main()
{
	unsigned int a = 2000000000, b = 2000000000, c = 3000000000, result;
	__asm {
		mov eax, a
		mov ebx, b
		adc eax, ebx
		mov ecx, c

		mov result, 0
		jc _end_method1
		cmp eax, ecx
		jng _less_end1
		jmp _end_method1
		
		_less_end1:
		mov result, 1

		_end_method1:
	}
	if (result == 1)
	{
		std::cout << "False" << std::endl;
		return 0;
	}
	__asm {
		mov eax, a
		mov ebx, c
		adc eax, ebx
		mov ecx, b

		mov result, 0
		jc _end_method2
		cmp eax, ecx
		jng _less_end2
		jmp _end_method2

		_less_end2:
		mov result, 1

		_end_method2:
	}
	if (result == 1)
	{
		std::cout << "False" << std::endl;
		return 0;
	}
	__asm {
		mov eax, c
		mov ebx, b
		adc eax, ebx
		mov ecx, a

		mov result, 0
		jc _end_method3
		cmp eax, ecx
		jng _less_end3
		jmp _end_method3

		_less_end3:
		mov result, 1

		_end_method3:
	}
	if (result == 1)
	{
		std::cout << "False" << std::endl;
	}
	else
	{
		std::cout << "True" << std::endl;
	}
	int arr1[4] = { 2000001, -3000000, -1000000, 1 }, arr2[4] = { 2000000, 2000000, -2000000, 2 }, n = 4, result1[3];
	__asm {
		mov [result1], 0
		mov [result1 + 4], 0
		mov [result + 8], 0
		lea edi, arr1
		lea esi, arr2

		xor ecx, ecx
		forbegin1 :
		cmp ecx, n
		je forend1
		mov ebx, dword ptr[edi] 
		add edi, 4				
		mov eax, dword ptr[esi] 
		add esi, 4				
		imul ebx				
		add [result1], eax
		add [result1 + 4], edx
		adc [result1 + 8], 0
		inc ecx
		jmp forbegin1
		forend1:
	}

	std::cout << result1[0] << std::endl;
	return 0;
}
