/*
third party module

automatically transforms request and response data to JSON

uses XMLHttpRequest, therefore supported in old browsers too

request cancellation

automatic retries

support for XHR requests
*/

const axios = require("axios");

const url = "https://reqres.in";
const path = "/api/users";
const uri = url + path;

const options = {
  method: "POST",
  timeout: 1000,
  headers: {
    "Content-Type": "application/json",
  },
  data: {
    name: "morpheus",
    job: "leader",
  },
};

axios(uri, options)
  .then((response) => console.log(response.data))
  .catch((error) => console.error(error));
