# LEVEL09

While analyzing the files in this level we have an binary called level09 which outputs :

    level09@SnowCrash:~$ ./level09
    You need to provied only one arg.
    level09@SnowCrash:~$ ./level09 jkj
    jll

 We can then determine that it might be hashed/encrypted, after determining adding the index to the current character. Creating a simple C program to determine the encrypted parameter:

     #include <stdio.h>
     
     int  main(int  argc, char  **argv)
    {
    char  *arg;
    int i =  0;
    
    arg =  argv[1];
    while(*arg)
    {
	    printf("%c", *arg - i);
	    i++;
	    arg++;
    }
    printf("\n");
    return  0;
    }

Paste this program into /tmp and compile it
cd back into ~

    cat token | xargs /tmp/a.out
