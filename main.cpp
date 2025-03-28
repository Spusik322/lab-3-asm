#include <iostream>

int main() {
    unsigned long nm1;
    unsigned long res1 = 0;
    std::cin >> nm1;

    _asm {
        xor eax, eax
        xor edx, edx
        xor ecx, ecx
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

    /*unsigned int res2 = 0, num, akum = 0;
    std::cin >> num;

    _asm {
        xor ecx, ecx
        mov eax, num
        mov ebx, 10
            metka :
        xor edx, edx
        div ebx
        add ecx, edx
        cmp eax, 0
        jne metka
            metka_end :
        mov res2, ecx
    }

    std::cout << "summa: " << res2;*/
    return 0;
}