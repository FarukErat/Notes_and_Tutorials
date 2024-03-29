const express = require("express");
const bcrypt = require("bcrypt");
const ip = require("ip");
const cors = require("cors");
const YAML = require("yamljs");
const path = require("path");
const swaggerUi = require("swagger-ui-express");

const app = express();
const port = 3013;
const workFactor = 12;
const swaggerDocument = YAML.load(path.join(__dirname, "swagger.yaml"));
const swaggerPath = "/api-docs";

app.use(express.json());
app.use(cors());
app.use(swaggerPath, swaggerUi.serve, swaggerUi.setup(swaggerDocument));

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
  console.log(`can be tested at http://${ip.address()}:${port}${swaggerPath}`);
});
