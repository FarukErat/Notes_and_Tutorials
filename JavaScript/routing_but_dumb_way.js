const http = require("http");
const fs = require("fs");

const PORT = 3001;

const server = http.createServer((req, res) => {
  // set header content type
  res.setHeader("Content-Type", "text/html");

  //! routing
  let path = "./views/";
  switch (req.url) {
    //! root
    case "/":
      switch (req.method) {
        //! GET
        case "GET":
          path += "index.html";
          res.statusCode = 200;
          break;
        //! POST
        case "POST":
          console.log("POST request");
          let body = "";
          req.on("data", (chunk) => {
            body += chunk;
          });
          req.on("end", () => {
            console.log(body);
            res.end("<h1>Success</h1>");
          });
          break;
        //! default
        default:
          res.statusCode = 405;
          res.end();
      }
      break;
    //! about
    case "/about":
      switch (req.method) {
        //! GET
        case "GET":
          path += "about.html";
          res.statusCode = 200;
          break;
        //! POST
        case "POST":
          console.log("POST request");
          let body = "";
          req.on("data", (chunk) => {
            body += chunk;
          });
          req.on("end", () => {
            console.log(body);
            res.end("<h1>Success</h1>");
          });
          break;
        //! default
        default:
          res.statusCode = 405;
          res.end();
      }
      break;
    //! about-us (redirect to about)
    case "/about-us":
      switch (req.method) {
        //! GET
        case "GET":
          res.statusCode = 301;
          res.setHeader("Location", "/about");
          res.end();
          break;
        //! default
        default:
          res.statusCode = 405;
          res.end();
      }
      break;
    //! non-existing page
    default:
      path += "404.html";
      res.statusCode = 404;
  }

  // send a response file
  fs.readFile(path, (err, data) => {
    if (err) {
      if (err.code === "ENOENT") {
        res.statusCode = 404;
        res.end("404 Not Found");
      } else {
        console.log(err);
        res.statusCode = 500;
        res.end("500 Internal Server Error");
      }
    } else {
      res.write(data);
      res.end();
    }
  });
});

// localhost is the default value for 2nd argument
server.listen(PORT, "localhost", () => {
  console.log(`listening for requests on http://localhost:${PORT}`);
});
