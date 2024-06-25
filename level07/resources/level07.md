# LEVEL07

ltrace on the executable 

    level07@SnowCrash:~$ ltrace ./level07

Will output a pattern similar to the one encounter on level04.
The program prints the environment variable "LOGNAME" via a call to system("/bin/echo logname")

Just like in level04, ls-la will show that flag07 has specific permissions, all we have to do is switch the LOGNAME env value with our getflag excecutable like so:

    level07@SnowCrash:~$ export LOGNAME='`getflag`'
And then launch the executable.

    ./level07

