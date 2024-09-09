# AUTHENTICATION METHODS



## Password Authentication:

User sets a password.<br>
A random piece of data, so called salt, is generated.<br>
The salt is appended to the password in such a way that it is possible to parse.<br>
If there are some parameters like iteration number, parallelism and etc., they are also appended the same manner.<br>
The result is stored in a database.<br>

User enters a password for login.<br>
The entry from database is retrieved.<br>
The hash, salt and parameters are parsed.<br>
The entered password is hashed according to the parsed salt and paramaters.<br>
Check is done by comparing the calculated hash and the parsed hash.<br>

### Why do we need to hash password anyway?

People tend to use the same password on different platforms.<br>
Once you learn their password on a platform, you can try to login with that password on different platforms.<br>
Therefore, passwords should be kept secret, as it should be, even from developers and admins.<br>
Since, plain text passwords can be read easily.<br>
If passwords are encrypted, it can be decrypted using keys.<br>
If keys are note used, passwords cannot be validated agains ciphertexts.<br>
We need a way to obfuscate passwords irreversibly.<br>
That's why we use hash functions.<br>

### Why do we even use salts?

We can simply hash passwords using SHA256.<br>
However, there is a catch.<br>
Hash functions always produce the same output, so called digest, when fed with the same input.<br>
That leads to users having same password, having same hash.<br>
Which makes it easier to guess ones password.<br>
Moreover, an attacker can pre-hash some common passwords and store them in a database,<br>
when the attacker obtains a password hash, they can directly search it in the database to find corresponding password, which is called `dictionary attack`.<br>

### Why don't we just use SHA256?

We can use salt to create different digests and store salt appended to the password.<br>
This way an attacker cannot use a dictionary database since the salt makes the difference.<br>
However, hash functions like SHA256 are developed to be fast to do integrity check with big files.<br>
Therefore, an attacker can focus on one single password hash,<br>
hashes common passwords with the salt to find a hash match and is still fast enough to do it in a feasible time, which is called ``rainbow table attack``.<br>
We need to slow down the attacker so much to make the process infeasible.<br>
There comes the purposfuly slowed hash functions(bcrypt, scrypt, argon2id).<br>
These hash functions create digests too slow for an attacker to do brute-force attacke, since the attacker has to do a lot of guess (O(n)).<br>
It does not harm login process that much since it does it once (O(1)).<br>

---

## Public Key Authentication:

If A sends public key to B
and B wants to check if A has the corresponding private key

- **1. method**
    - B generates some random data
    - and encrypt it with the public key
    - sends the ciphertext to A

    - A decrypts the ciphertext with the private key
    - and sends the plain data to B

    - B then checks if the generated and received data match

- **2. method**
    - B generates some random data
    - sends it to A without encrypting

    - A encrypts the plain data with the private key
    - then sends the ciphertext to B

    - B decrypts the ciphertext with the public key
    - then checks if the data sent and decrypted match

- **3. method**
    - B generates some random data
    - and encrypt it with the public key
    - sends the ciphertext to A

    - A decrypts the ciphertext with the private key
    - then encrypts it with the private key
    - then sends the ciphertext to B

    - B decrypts the ciphertext with the public key
    - then checks if the data generated and decrypted match

---

## Time-Based One-Time Password(TOTP):

When a service requires an authenticator app, it generates a secret and a QR code to transfer the secret.<br>
An authenticator app scans the QR code and gets the secret.<br>
From this point on, they are able to create the same authentication code without even communicating anymore,<br>
using the secret and current time.<br>
The code may be valid for 30 or 60 second by a simple modulus operation on current time.<br>
Once a code is used, it is marked as used in the server.<br>

---

## Read / Write Authentication:

Read (One Time Password - OTP - 2FA):<br>
    A code is generated and stored in a cache or database.<br>
    The code is sent throug a channel like email, phone, or SMS.<br>
    If user enters the same code, then it is proven that the user has read access to those.<br>

Write:<br>
    The user is asked to make a specific modification to some resource.<br>
    The service then checks if the modification has been made to verify write access.<br>
    Such as DNS/HTTP challenge to prove domain ownership.<br>

---

## Hash based Message Authentication Code:

Symmetric:
    The hash of a message (e.g., JSON data) is generated using a secret key.<br>
    The generated hash is then compared with the provided hash to verify the message's integrity and authenticity. (HS256)<br>

Asymmetric:
    The message's hash is created and then encrypted with a private key.<br>
    The recipient decrypts the ciphertext using the corresponding public key and compares the decrypted hash with the calculated hash from the message.<br>
    If they match, the message is authenticated. (RS256)<br>

---

## Smart Card / Hardware Authentication:

Users authenticate by inserting a smart card into a reader. The card contains a secure cryptographic key that is used to verify the user's identity.

---

## Biometric Authentication:

This method uses unique biological traits of the user, such as fingerprints, facial recognition, iris scans, or voice recognition, to authenticate them.

---

## CAPTCHA

CAPTCHA (Completely Automated Public Turing test to tell Computers and Humans Apart) challenges the user with a task that is easy for humans but difficult for bots, like recognizing distorted text or identifying objects in images.

---

## Behavioral Authentication:

This method analyzes user behavior, such as typing speed, mouse movements, or browsing patterns, to authenticate users. It creates a unique profile for each user and checks for consistency during login.

---

## Kerberos Authentication:

Kerberos is a network authentication protocol designed to provide strong authentication for client-server applications using secret-key cryptography.<br>
It works based on the concept of "tickets" to allow nodes to prove their identity in a secure manner.<br>
When a user tries to authenticate, they first request a Ticket Granting Ticket (TGT) from the Key Distribution Center (KDC).<br>
Once they have the TGT, they can use it to request service tickets for access to specific services.<br>
The service tickets are used to authenticate the user to each service without needing to transmit passwords across the network.<br>

---


## Terminology:

### Coding
Transforming data into a specific format (e.g., base64). No secrets are used; it’s for data formatting or transmission.

### Decoding
Reversing the coding process to retrieve the original data. No secrets are involved.

### Encryption
Converting data into a secure format using an encryption algorithm, typically requiring a secret key or password. This ensures data confidentiality.

### Decryption
Reversing the encryption process to restore the original data. This also requires some keys.

### Hash
Generating a fixed-size hash value from input data. It’s a one-way process, and no secrets are involved.
Hashing is used for data integrity checks and securely storing passwords by comparing hashes.

### HMAC
Combines a cryptographic hash function with a secret key to ensure both data integrity and authenticity.<br>
The secret key is used along with the hash function to create a MAC (Message Authentication Code).<br>
The sender and receiver use the same secret key to validate that the message hasn’t been tampered with and is from a legitimate source.<br>

### Asymmetric Encryption
A kind of encryption that requires two different keys that are mathematically paired.<br>
Data that was encrypted by one can only be decrypted by another.<br>
It is not practical to find the other if one is used.<br>
Both keys have the exact same functionalities like encryption and decryption.<br>
