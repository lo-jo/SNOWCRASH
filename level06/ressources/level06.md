# Level06
Ls into the working directory. There is one executable and one .php file.
The first executable takes one file as argument and looks like it just outputs its content.

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
