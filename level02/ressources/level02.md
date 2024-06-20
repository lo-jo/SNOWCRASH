LOG INTO LEVEL02
ls 
output : level02.pcap
What is a .pcap ?
Packet CAPture file is a file created by tools that capture network packets and monitors network.

Problem :
No tool to analyse the file.

Solution:
Transfer .pcap file to our local machine where WireShark is installed:
scp -P 4242 level02@<ip-of-the-machine>:/home/user/level02/level02.pcap .
chmod it 
Open it in WireShark
Line 43 > packet shows "password"
Follow > TCP stream 

