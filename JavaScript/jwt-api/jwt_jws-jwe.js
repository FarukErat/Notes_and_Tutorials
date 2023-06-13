const express = require("express");
const jwt = require("jsonwebtoken");
const crypto = require("crypto");
require("dotenv").config();

const app = express();
const port = 3002;

app.use(express.json());

const jwsSecret = process.env.JWS_SECRET;
const toJwt = (payload) => jwt.sign(payload, jwsSecret);
const fromJwt = (payload) => jwt.verify(payload, jwsSecret);

app.post("/create-jws", async (req, res) => {
  try {
    const token = toJwt(req.body);
    res.status(200).json({ token: token });
  } catch (error) {
    res.status(400).json({ error: error.message });
  }
});

app.post("/verify-jws", async (req, res) => {
  try {
    const token = req.headers.authorization.split(" ")[1];
    const payload = fromJwt(token);
    res.status(200).json(payload);
  } catch (error) {
    res.status(400).json({ error: error.message });
  }
});

//! JWE

// resize secret
// since createCipheriv and createDecipheriv requires string of 32 characters
const jweSecret = crypto
  .createHash("sha256")
  .update(String(process.env.JWE_SECRET))
  .digest("base64")
  .substring(0, 32);

function encrypt(text) {
  return new Promise((resolve, reject) => {
    const iv = crypto.randomBytes(16);
    const cipher = crypto.createCipheriv("aes-256-cbc", jweSecret, iv);
    let encrypted = cipher.update(text, "utf8", "hex");
    encrypted += cipher.final("hex");
    resolve(iv.toString("hex") + encrypted);
  });
}

function decrypt(encryptedText) {
  return new Promise((resolve, reject) => {
    const iv = Buffer.from(encryptedText.slice(0, 32), "hex");
    const decipher = crypto.createDecipheriv("aes-256-cbc", jweSecret, iv);
    let decrypted = decipher.update(encryptedText.slice(32), "hex", "utf8");
    decrypted += decipher.final("utf8");
    resolve(decrypted);
  });
}

app.post("/create-jwe", async (req, res) => {
  try {
    const tokenPayload = JSON.stringify(req.body);
    const encryptedPayload = await encrypt(tokenPayload, jweSecret);
    const token = toJwt({ encryptedPayload });
    res.status(200).json({ token });
  } catch (error) {
    res.status(400).json({ error: error.message });
  }
});

app.post("/verify-jwe", async (req, res) => {
  try {
    const token = req.headers.authorization.split(" ")[1];
    const payload = fromJwt(token);
    const encryptedPayload = payload.encryptedPayload;
    const decryptedPayload = await decrypt(encryptedPayload, jweSecret);
    const decoded = JSON.parse(decryptedPayload);
    delete payload.encryptedPayload;
    res.status(200).json({ ...decoded, ...payload });
  } catch (error) {
    res.status(400).json({ error: error.message });
  }
});

app.listen(port, () => {
  console.log(`listening on http://localhost:${port}`);
});
