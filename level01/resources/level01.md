
# LEVEL 01
    cat /etc/passwd | grep flag01

 Will output what looks like a crypted password.
Tools  such as [John The Ripper](https://www.kali.org/tools/john/) will help us decrypt the token.

John the Ripper is a popular password cracking tool designed to help systems administrators to find weak (easy to guess or crack through brute force) passwords, and even automatically mail users warning them about it, if it is desired.

Since we cannot install anything on the given VM, we have to create a VM where we can install it.

    vagrant up

    vagrant ssh 

    echo <token> > <file>

    john <file> --show
Will output the decrypted password.

 
## Security weakness
John the Ripper exploits some key security weaknesses such as 

-   **Weak Passwords**:
    
    -   **Short Length**: Passwords that are too short can be quickly cracked by brute force attacks.
    -   **Common Words and Patterns**: Passwords based on dictionary words, common phrases, or easily guessable patterns (e.g., "password", "123456", "qwerty") are highly vulnerable to dictionary attacks.
    -   **Lack of Complexity**: Passwords lacking a mix of uppercase letters, lowercase letters, numbers, and special characters are easier to crack.
-   **Inadequate Hashing Algorithms**:
    
    -   **Weak Hash Functions**: Older or less secure hashing algorithms (e.g., MD5, SHA-1) are more susceptible to attacks. John the Ripper can exploit weaknesses in these algorithms to speed up the cracking process.
    -   **Lack of Salting**: Password hashes that are not salted (a unique random value added to each password before hashing) can be attacked more easily using precomputed tables (rainbow tables).
-   **Reused Passwords**:
    
    -   Users who reuse passwords across multiple sites or systems are at greater risk. Once a password is cracked for one account, it can be used to access other accounts if the same password is used.
-   **Poorly Managed Password Storage**:
    
    -   Storing passwords in plaintext or using reversible encryption methods poses significant risks. If an attacker gains access to such storage, they can retrieve the passwords directly without needing to crack them.
-   **Infrequent Password Changes**:
    
    -   Passwords that are not regularly changed can be compromised over time, especially if an attacker is able to capture and work on the hash for an extended period.
-   **Uncontrolled Access to Hashes**:
    
    -   If an attacker gains access to the hashed passwords (e.g., through a database breach), they can use tools like John the Ripper to attempt to crack the hashes offline without detection.