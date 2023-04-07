const https = require("https");

const url = "https://www.blablabla.com/";
const delayMs = 10;

setInterval(() => {
  https.get(url, () => {
    console.log("request sent");
  });
}, delayMs);
