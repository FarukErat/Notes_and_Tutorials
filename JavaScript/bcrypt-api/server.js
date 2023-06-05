const express = require("express");
const bcrypt = require("bcrypt");
const ip = require("ip");

const app = express();
const port = 3013;
const workFactor = 12;

app.use(express.json());

app.post("/hash", async (req, res) => {
  const { password } = req.body;
  const salt = await bcrypt.genSalt(workFactor);
  const hash = await bcrypt.hash(password, salt);
  res.send({ hash: hash });
});

app.post("/validate", async (req, res) => {
  const { password, hash } = req.body;
  const match = await bcrypt.compare(password, hash);
  res.send({ match: match });
});

app.listen(port, () => {
  console.log(`app listening at http://${ip.address()}:${port}`);
});

