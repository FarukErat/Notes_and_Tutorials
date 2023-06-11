const express = require('express');
const jwt = require('jsonwebtoken');
const crypto = require('crypto');

const app = express();
const port = 3001;

require('dotenv').config();
app.use(express.json());

app.post('/create-jws', async (req, res) => {
    try {
        const token = jwt.sign(req.body, process.env.JWT_SECRET);
        res.status(200).json({ token: token });
    } catch (error) {
        res.status(400).json({ error: error.message })
    }
});

app.post('/verify-jws', async (req, res) => {
    try {
        const token = req.headers.authorization.split(' ')[1];
        const decoded = jwt.verify(token, process.env.JWT_SECRET);
        res.status(200).json(decoded)
    } catch (error) {
        res.status(400).json({ error: error.message })
    }
});

// Encryption function using AES algorithm
function encrypt(text, secretKey) {
    const cipher = crypto.createCipher('aes-256-cbc', secretKey);
    let encrypted = cipher.update(text, 'utf8', 'hex');
    encrypted += cipher.final('hex');
    return encrypted;
}

// Decryption function using AES algorithm
function decrypt(encryptedText, secretKey) {
    const decipher = crypto.createDecipher('aes-256-cbc', secretKey);
    let decrypted = decipher.update(encryptedText, 'hex', 'utf8');
    decrypted += decipher.final('utf8');
    return decrypted;
}

app.post('/create-jwe', async (req, res) => {
    try {
        const tokenData = JSON.stringify(req.body);
        const encryptedToken = encrypt(tokenData, process.env.SECRET);

        const token = jwt.sign({ encryptedToken }, process.env.JWT_SECRET);
        res.status(200).json({ token });
    } catch (error) {
        res.status(400).json({ error: error.message });
    }
});

app.post('/verify-jwe', async (req, res) => {
    try {
        const token = req.headers.authorization.split(' ')[1];
        const decodedToken = jwt.verify(token, process.env.JWT_SECRET);

        const encryptedToken = decodedToken.encryptedToken;
        const decryptedToken = decrypt(encryptedToken, process.env.SECRET);

        const decoded = JSON.parse(decryptedToken);
        res.status(200).json(decoded);
    } catch (error) {
        res.status(400).json({ error: error.message });
    }
});

app.listen(port, () => {
    console.log(`listening on http://localhost:${port}`);
});
