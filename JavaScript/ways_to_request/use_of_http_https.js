/*
http and https are built-in nodejs modules

no need for a package.json
*/

const https = require("https");

const options = {
  hostname: "reqres.in",
  path: "/api/users",
  method: "POST",
  headers: {
    "Content-Type": "application/json",
  },
};

const request = https.request(options, (response) => {
  let data = "";

  response.on("data", (chunk) => {
    data += chunk;
  });

  response.on("end", () => {
    console.log(JSON.parse(data));
  });
});

request.on("error", (error) => {
  console.error(error);
});

const postData = JSON.stringify({
  name: "morpheus",
  job: "leader",
});

request.write(postData);
request.end();
