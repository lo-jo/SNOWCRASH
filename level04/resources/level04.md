# LEVEL 04
Ls into the current directory will output a .pl script.
Executing it will output a http header.

    level04@SnowCrash:~$ cat level04.pl 
    #!/usr/bin/perl
    # localhost:4747
    use CGI qw{param}; 
    print "Content-type: text/html\n\n";
    sub x {
      $y = $_[0];
      print `echo $y 2>&1`;
    }
    x(param("x"));

This script imports the param function from the CGI module which is used to retrieve parameters sent to the script.

The sub keyword is used to define a subroutine in which $y = $_[0} assigns the first parameter passed to the subroutine.
Backticks are used to execute a shell command.

Given the commented text at the top of the file, we can assume that the script is running on port `4747` on our localhost (current OS).

## Security weaknesses
1. command injection
This script is vulnerable to command injection. Since it directly uses the parameter value in a shell command without any sanitization or validation, an attacker could potentially execute arbitrary commands on the server. This is a major security risk.

    ```curl 'localhost:4747/?x=$(getflag)'```

2. Privilege Escalation
The privileges inherited when the Perl script (`perl`) executes depend on the user running the web server process (`localhost:4747` in this case).  The web server process (`perl` in this case) has read access to certain files or directories, it can execute commands that read and manipulate those files within its permissions

```
level04@SnowCrash:~$ ps -eo user,cmd | grep apache
    root     /usr/sbin/apache2 -k start
    www-data /usr/sbin/apache2 -k start
    www-data /usr/sbin/apache2 -k start
    www-data /usr/sbin/apache2 -k start
    www-data /usr/sbin/apache2 -k start
    www-data /usr/sbin/apache2 -k start
   ```