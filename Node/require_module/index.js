var http = require('http');
var dt = require('./my_module');

http.createServer(function (req, res) {
    res.writeHead(200, { 'Content-Type': 'text/html' });
    res.write("The date and time are currently: " + dt.myDateTime());
    res.end();
}).listen(8080);

// The date and time are currently: Thu Dec 01 2022 21:06:09 GMT+0300 (GMT+03:00)
