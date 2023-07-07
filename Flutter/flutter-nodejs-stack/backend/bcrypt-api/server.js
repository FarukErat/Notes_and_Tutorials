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
  const start = Date.now();

  // log request
  console.log("-".repeat(40));
  console.log("\x1b[36m%s\x1b[0m", `${req.path} [${req.method}]`);
  console.log("\x1b[33m%s\x1b[0m", "Request Body:", req.body);

  // log response
  // when a request is made, res.send is set to a custom function to log response
  const originalSend = res.send;
  res.send = function (data) {
    const end = Date.now();
    const elapsedTime = end - start;

    console.log("\x1b[32m%s\x1b[0m", "Response:", data);
    console.log(`Elapsed Time: ${elapsedTime}ms`);
    console.log("+".repeat(40));

    // Restore the original send function
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
