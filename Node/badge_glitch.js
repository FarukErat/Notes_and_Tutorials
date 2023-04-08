const https = require("https");

const url = "https://visitor-badge.laobi.icu/badge?page_id=RandomID";
const regex = /<text.*>\s*(\d+)\s*<\/text>/;
const delayMs = 10;
let counter = 0;

setInterval(() => {
  https.get(url, (res) => {
    let data = "";
    res.on("data", (chunk) => {
      data += chunk;
    });
    res.on("end", () => {
      const match = data.match(regex);
      if (match) {
        counter++;
        const visitors = match[1];
        process.stdout.write(
          `\rTotal Visitors: ${visitors}, New Visitors: ${counter}`
        );
      }
      data = "";
    });
  });
}, delayMs);
