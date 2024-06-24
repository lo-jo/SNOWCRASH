# LEVEL 02
    ls

 Will output a .pcap file.

## What is a .pcap ?
A Packet Capture File is a file created by tools that capture network packets and monitors network.

Analysis of such files can be done using packet analysers like [Wireshark](https://www.wireshark.org/download.html).

Wireshark is available on school dumps, contrarily to our Snow Crash vm.
A simple way around this problem is to transfer the .pcap file to our host machine via scp.

    scp -P 4242 level02@<ip-of-the-machine>:/home/user/level02/level02.pcap .

    chmod 777 <file>
Open it in Wireshark and analyze it.
@line 43 the packet shows "password".

If we trace back the TCP Stream, by right-clicking on the line then "Follow TCP", and show the data as C arrays. we will be able to analyse it.
Since the values are output as ASCII, a simple C program will output the result.
 
## Security weakness

Plaintext Password Transmission:

 - Unencrypted Passwords: If passwords are transmitted in plaintext over
   a TCP stream, anyone with access to the network traffic can intercept
   and read these passwords. This is a significant risk, especially on
   unsecured networks (e.g., public Wi-Fi).

The TCP stream analysis here shows that both IP adresses belong to the same subnet, suggesting that they are located on the same local network.

    - peer: 0
    
    host: 59.233.235.218
    
    port: 39247
    
    - peer: 1
    
    host: 59.233.235.223
    
    port: 12121
