const ip = require("ip");
const uri = "https://myexternalip.com/raw";

fetch(uri)
  .then((response) => response.text())
  .then((data) => {
    console.log("local ip : " + ip.address());
    console.log("public ip: " + data);
  })
  .catch((error) => console.error(error));
