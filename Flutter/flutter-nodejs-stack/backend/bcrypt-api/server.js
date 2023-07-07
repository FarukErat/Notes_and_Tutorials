const express = require("express");
const bcrypt = require("bcrypt");
const ip = require("ip");
const cors = require("cors");

const app = express();
const port = 3013;
const workFactor = 10;

app.use(express.json());
app.use(cors());

app.use((req, res, next) => {
  console.log(req.path, req.method, req.body);

  // when a request is made, res.send is set to a custom function to log response
  const originalSend = res.send;
  res.send = function (data) {
    console.log(data);
    // such a custom function that when it is called, it is set back to the original
    res.send = originalSend;
    res.send(data);
  };

  next();
});

app.post("/hash", async (req, res) => {
  const { password } = req.body;
  const salt = await bcrypt.genSalt(workFactor);
  const hash = await bcrypt.hash(password, salt);
  res.send({ hash });
});

app.post("/validate", async (req, res) => {
  const { password, hash } = req.body;
  const match = await bcrypt.compare(password, hash);
  res.send({ match });
});

app.listen(port, () => {
  console.log(`app listening at http://${ip.address()}:${port}`);
});
