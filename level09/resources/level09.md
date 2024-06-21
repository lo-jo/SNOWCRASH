## level09
outputs the token, seems hashed.....

what could it be... ?

various tests with random texts makes us believe that the encryption program is just
<current char> -current index

copy past the decode.c into /tmp/
compile it
cd ~
cat token | xargs /tmp/a.out
and the token is decrypted

