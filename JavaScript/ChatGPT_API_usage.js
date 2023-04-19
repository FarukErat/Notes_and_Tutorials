const https = require("https");

require("dotenv").config();

const apiKey = process.env.OPENAI_API_KEY;

const input = "Compare Axios and Superagent";

const options = {
  hostname: "api.openai.com",
  path: "/v1/chat/completions",
  method: "POST",
  headers: {
    "Content-Type": "application/json",
    Authorization: `Bearer ${apiKey}`,
  },
};

const data = JSON.stringify({
  model: "gpt-3.5-turbo",
  messages: [{ role: "user", content: input }],
  temperature: 0.7,
});

const req = https.request(options, (res) => {
  let responseData = "";

  res.on("data", (chunk) => {
    responseData += chunk;
  });

  res.on("end", () => {
    const response = JSON.parse(responseData);
    const message = response.choices[0].message.content;
    console.log(message);
  });
});

req.on("error", (error) => {
  console.error(error);
});

req.write(data);
req.end();

// output when I ran the program
/*
As an AI language model, I do not have personal experiences, opinions, or biases. However, I can provide a comparison between Axios and Superagent based on their features and functionalities:

Axios:
- Axios is a popular HTTP client library for JavaScript that is widely used in web applications, mobile apps, and Node.js servers.
- It supports both browser and server-side environments, including React, Angular, Vue.js, and Node.js.
- Axios uses Promises to handle asynchronous requests and responses, and it allows for interceptors to modify requests and responses globally.
- It has a simple and intuitive API that supports various HTTP methods (GET, POST, PUT, DELETE, etc.) and provides options for sending data, headers, and authentication tokens.
- Axios also has built-in support for canceling requests, handling errors, and transforming data.

Superagent:
- Superagent is another popular HTTP client library for JavaScript that is designed to be lightweight and flexible.
- It also supports both browser and server-side environments, including React, Angular, Vue.js, and Node.js.
- Superagent uses callbacks to handle asynchronous requests and responses, and it allows for chaining methods to create complex requests.
- It has a simple and flexible API that supports various HTTP methods (GET, POST, PUT, DELETE, etc.) and provides options for sending data, headers, and authentication tokens.
- Superagent also has built-in support for handling errors, cookies, and file uploads.

In summary, Axios and Superagent are both powerful HTTP client libraries with similar features and functionalities. However, Axios is more popular and widely used due to its simple API, Promise-based approach, and interceptors support. Superagent, on the other hand, is more lightweight and flexible, and it may be a better choice for smaller projects or specific use cases.
*/
