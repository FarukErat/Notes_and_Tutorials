const express = require("express");
const jwt = require("jsonwebtoken");
const crypto = require("crypto");
require("dotenv").config();

const app = express();
const port = 3001;

app.use(express.json());

const secret = crypto
  .createHash("sha256")
  .update(String(process.env.SECRET))
  .digest("base64")
  .substring(0, 32);

const toJwt = (data) => jwt.sign(data, process.env.JWT_SECRET);
const fromJwt = (data) => jwt.verify(data, process.env.JWT_SECRET);

app.post("/create-jws", async (req, res) => {
  try {
    const token = await toJwt(req.body);
    res.status(200).json({ token: token });
  } catch (error) {
    res.status(400).json({ error: error.message });
  }
});

app.post("/verify-jws", async (req, res) => {
  try {
    const token = req.headers.authorization.split(" ")[1];
    const decoded = fromJwt(token);
    res.status(200).json(decoded);
  } catch (error) {
    res.status(400).json({ error: error.message });
  }
});

function encrypt(text) {
  return new Promise((resolve, reject) => {
    const iv = crypto.randomBytes(16);
    const cipher = crypto.createCipheriv("aes-256-cbc", secret, iv);
    let encrypted = cipher.update(text, "utf8", "hex");
    encrypted += cipher.final("hex");
    resolve(iv.toString("hex") + encrypted);
  });
}

function decrypt(encryptedText) {
  return new Promise((resolve, reject) => {
    const iv = Buffer.from(encryptedText.slice(0, 32), "hex");
    const decipher = crypto.createDecipheriv("aes-256-cbc", secret, iv);
    let decrypted = decipher.update(encryptedText.slice(32), "hex", "utf8");
    decrypted += decipher.final("utf8");
    resolve(decrypted);
  });
}

app.post("/create-jwe", async (req, res) => {
  try {
    const tokenData = JSON.stringify(req.body);
    const encryptedToken = await encrypt(tokenData, process.env.SECRET);
    const token = toJwt(encryptedToken);
    res.status(200).json({ token });
  } catch (error) {
    res.status(400).json({ error: error.message });
  }
});

app.post("/verify-jwe", async (req, res) => {
  try {
    const token = req.headers.authorization.split(" ")[1];
    const encryptedToken = fromJwt(token);
    const decryptedToken = await decrypt(encryptedToken, process.env.SECRET);
    const decoded = JSON.parse(decryptedToken);
    res.status(200).json(decoded);
  } catch (error) {
    res.status(400).json({ error: error.message });
  }
});

app.listen(port, () => {
  console.log(`listening on http://localhost:${port}`);
});
