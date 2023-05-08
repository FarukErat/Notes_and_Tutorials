const { createServer } = require("http");

const myServer = {
  _endpoints: [],
  handleRequest: (req, res) => {
    const { method, url } = req;
    const route = myServer._endpoints.find(
      (route) => route.method === method && route.url === url
    );
    if (route) {
      route.todo(req, res);
      res.end();
    } else {
      res.statusCode = 405;
      res.end();
    }
  },
  addRequestListener: (url, method, todo) =>
    myServer._endpoints.push({ url, method, todo }),
  listen: (port) => {
    const server = createServer(myServer.handleRequest);
    server.listen(port);
    console.log(`server running on http://localhost:${port}`);
  },
  getRoutes: () => myServer._endpoints,
};

myServer.addRequestListener("/", "GET", (req, res) => {
  console.log("get request to root");
  res.write("Hello, world!");
});

console.log(myServer._endpoints);

myServer.listen(3001);
