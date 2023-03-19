const http = require("http");
const dotenv = require("dotenv");

dotenv.config();
port = process.env.PORT || 3001;

function sendRequest() {
  http.get("http://localhost:" + port + "/", (res) => {
    res.on("data", (chunk) => {
      console.log(chunk.toString());
    });
  });
}

function repeatSendRequest() {
  const intervalId = setInterval(() => {
    sendRequest();
  }, 1000);

  setTimeout(() => {
    clearInterval(intervalId);
  }, 5000);
}

repeatSendRequest();
