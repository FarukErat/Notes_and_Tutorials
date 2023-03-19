const express = require("express");
const morgan = require("morgan");
const dotenv = require("dotenv");

const app = express();
dotenv.config();
port = process.env.PORT || 3001;

app.use(morgan("dev"));

let output = "";

app.get("/", (req, res) => {
  output = "get request to the homepage";
  res.send(output);
  console.log(output);
});

app.post("/", (req, res) => {
  output = "post request to the homepage";
  res.send(output);
  console.log(output);
});

app.put("/", (req, res) => {
  output = "put request to the homepage";
  res.send(output);
  console.log(output);
});

app.delete("/", (req, res) => {
  output = "delete request to the homepage";
  res.send(output);
  console.log(output);
});

app.listen(port, () => console.log("Server started on port: " + port + ""));
