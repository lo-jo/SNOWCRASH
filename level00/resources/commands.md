# LEVEL 00
At this point, no obvious hints found in the vm.
Since we have to find the password that will log us with the flag00 account, let's try and search the entire filesystem for files and directories owned by the user `flag00`, while suppressing any error messages that might occur (such as permission denied errors) with the following command :

    find / -user flag00 2> /dev/null

    cat /usr/sbin/john
The previous command ill output what looks like a crypted password.

Online tools such as https://www.dcode.fr/caesar-cipher are able to detect encryption patterns and a simple research will lead us to believe that this is a Caesar cipher encryption.
The ceaser cipher replaces each letter by another letter located a little further in the alphabet. Here it is shifted by 11.
`c` becomes `n`
`d` becomes `o`
`i` becomes `t`
and so on.
 

## Security weaknesses

-   **Limited Key Space**: The Caesar cipher uses a fixed shift of the alphabet, typically 0 to 25 for the English alphabet. This means there are only 26 possible keys. With such a small key space, a brute-force attack (trying all possible keys) is trivial and can be done almost instantly even by hand.
    
-   **Frequency Analysis**: The Caesar cipher does not disguise letter frequencies. In English, certain letters (like 'E', 'T', 'A', 'O', 'I', 'N') appear more frequently than others. An attacker can perform a frequency analysis on the ciphertext to identify the most common letters and match them to their likely counterparts in the plaintext. This makes the Caesar cipher vulnerable to frequency analysis attacks.
    
-   **Pattern Preservation**: The Caesar cipher preserves the structure and patterns of the plaintext. For example, repeated letters and common digraphs (pairs of letters) in the plaintext will appear as repeated letters and common digraphs in the ciphertext. This can give clues to an attacker about the content of the plaintext.
    
-   **Lack of Diffusion and Confusion**: Modern cryptographic algorithms rely on principles of diffusion (spreading out the plaintext's influence over the ciphertext) and confusion (making the relationship between the ciphertext and the key complex). The Caesar cipher does neither of these, resulting in a simple and predictable transformation that is easy to reverse.
    
-   **Historical and Educational Use Only**: The Caesar cipher is one of the oldest known encryption techniques, dating back to Julius Caesar, who used it for military communications. While it serves as a good introduction to the concept of encryption, it is not secure against any serious attempt at cryptanalysis.