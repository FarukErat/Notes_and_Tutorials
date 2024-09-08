# Authentication Methods

1. **Password Authentication:**
   - **How it works:** The user's password is hashed using a secure hashing algorithm (e.g., bcrypt, argon2id) and stored in a database. When the user logs in, the entered password is hashed, and this hash is compared with the stored hash.
   - **Security considerations:** It's important to use a slow hashing algorithm (like bcrypt) to make brute-force attacks more difficult. Salting is also crucial to prevent rainbow table attacks.

2. **HMAC (Hash-Based Message Authentication Code):**

   - **Symmetric:**
     - **How it works:** The hash of a message (e.g., JSON data) is generated using a secret key. The generated hash is then compared with the provided hash to verify the message's integrity and authenticity.
     - **Common usage:** Often used in JSON Web Tokens (JWT) for signing tokens (JWS, HS256).

   - **Asymmetric:**
     - **How it works:** The message's hash is created and then encrypted with a private key. The recipient decrypts the ciphertext using the corresponding public key and compares the decrypted hash with the calculated hash from the message. If they match, the message is authenticated.
     - **Common usage:** Also used in JWTs, especially when tokens need to be verified by parties other than the issuer (RS256).

3. **Public Key Authentication:**
   - **How it works:** A pair of keys (public and private) is generated. The public key is stored on the server, and the private key remains securely on the client’s machine. When the client attempts to authenticate, the server sends a challenge (random data) that is encrypted with the public key. The client uses its private key to decrypt the challenge and sends back the decrypted data. If it matches the server’s expectation, the client is authenticated.
   - **Common usage:** Used in SSH to provide a secure, passwordless login. The private key never leaves the client machine, making it highly secure as long as the private key is kept safe.

4. **Two-Factor Authentication:**
   - **How it works:** A code is sent to the user's email, phone, or via SMS. The user must input this code to verify they have access to the channel, which adds an additional layer of security beyond just the password.
   - **Common usage:** Used as a second factor in two-factor authentication (2FA) to enhance security.

5. **Biometric Authentication:**
   - **How it works:** This method uses unique biological traits of the user, such as fingerprints, facial recognition, iris scans, or voice recognition, to authenticate them.
   - **Security considerations:** While biometric data is difficult to forge, it also cannot be changed if compromised. Systems using biometrics often combine them with other factors (like passwords) for multi-factor authentication (MFA).

6. **DNS/HTTP Challenge (Ownership Verification):**
   - **How it works:** To prove domain ownership, the user is asked to make a specific modification to their DNS records or host a specific file at a certain URL. The service then checks if the modification has been made to verify ownership.
   - **Common usage:** Often used in obtaining SSL certificates (e.g., Let's Encrypt) or verifying domain ownership for various services.

7. **CAPTCHA:**
   - **How it works:** CAPTCHA (Completely Automated Public Turing test to tell Computers and Humans Apart) challenges the user with a task that is easy for humans but difficult for bots, like recognizing distorted text or identifying objects in images.
   - **Common usage:** Preventing automated attacks on websites, such as spam submissions or brute-force login attempts.

8. **Behavioral Authentication:**
   - **How it works:** This method analyzes user behavior, such as typing speed, mouse movements, or browsing patterns, to authenticate users. It creates a unique profile for each user and checks for consistency during login.
   - **Common usage:** Continuous authentication in sensitive systems, reducing the need for repeated logins.

9. **LDAP Authentication:**
   - **How it works:** LDAP is a protocol used for accessing and maintaining distributed directory information services. With LDAP authentication, user credentials (typically username and password) are verified against an LDAP directory, such as Microsoft Active Directory or OpenLDAP. When a user attempts to log in, the application sends a bind request to the LDAP server using the provided credentials. If the credentials are valid, the LDAP server allows access; otherwise, the authentication fails.
   - **Common usage:** LDAP is commonly used in enterprise environments for centralized authentication across multiple systems, services, and applications. It allows for user management in one place, making it easier for organizations to control and maintain access to various resources.

# Terminology

- **Coding:** Transforming data into a specific format (e.g., base64). No secrets are used; it’s for data formatting or transmission.
- **Decoding:** Reversing the coding process to retrieve the original data. No secrets are involved.

- **Encryption:** Converting data into a secure format using an encryption algorithm, typically requiring a secret key or password. This ensures data confidentiality.
- **Decryption:** Reversing the encryption process to restore the original data. This also requires some keys.

- **Hash:** Generating a fixed-size hash value from input data. It’s a one-way process, and no secrets are involved. Hashing is used for data integrity checks and securely storing passwords by comparing hashes.

- **HMAC (Hash-Based Message Authentication Code):** Combines a cryptographic hash function with a secret key to ensure both data integrity and authenticity. The secret key is used along with the hash function to create a MAC (Message Authentication Code). The sender and receiver use the same secret key to validate that the message hasn’t been tampered with and is from a legitimate source.
