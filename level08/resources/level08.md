# LEVEL 08

ltrace on the executable :

    level08@SnowCrash:~$ ltrace ./level08 token

The output shows the use of the function strstr that takes "token" as parameter.
Concluding that we shouldn't use "token" as parameter.
We can then modify the name of the file token creating a symbolic link as follow:

    ln -s /home//user/level08/token /tmp/test

and then execute as follow:

    ./level08 /tmp/test
