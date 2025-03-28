#include <iostream>

int main() {
    unsigned long nm1;
    unsigned long res1 = 0;
    std::cin >> nm1;

    _asm {
        xor eax, eax
        xor edx, edx
        xor ecx, ecx
        xor ebx, ebx
        mov eax, nm1       
        mov ebx, eax       
        mov res1, eax       
        mov ecx, 7          
            pow8_loop:
        mul ebx             
        loop pow8_loop      
        add res1, eax      
        mov ecx, 4
            pow12_loop:
        mul ebx             
        loop pow12_loop
            add res1, eax
    }

    std::cout << "Result: " << res1 << std::endl;








    int solutions[16];
    int count = 0;

    _asm {
        xor eax, eax
        xor edx, edx
        xor ecx, ecx
        xor ebx, ebx
        mov ecx, 1
        mov esi, 25
            loop_start :
        cmp ecx, esi
        jge loop_end
        mov edx, ecx
        imul edx, 2
        mov ebx, 50
        sub ebx, edx
        mov eax, ebx
        xor edx, edx
        mov ebx, 3
        div ebx
        cmp edx, 0
        jne skip_solution
        lea edi, solutions
        mov ebx, count
        mov edx, ebx
        imul edx, 8
        add edi, edx
        mov dword ptr[edi], ecx
        mov dword ptr[edi + 4], eax
        inc dword ptr[count]
            skip_solution :
        inc ecx
        jmp loop_start
            loop_end :
    }

    std::cout << "Solutions: " << count << "\n";
    for (int i = 0; i < count; i++)
    {
        int x = solutions[i * 2];
        int y = solutions[i * 2 + 1];
        std::cout << "2*" << x << " + 3*" << y << " = " << (2 * x + 3 * y) << "\n";
    }
    return 0;
}