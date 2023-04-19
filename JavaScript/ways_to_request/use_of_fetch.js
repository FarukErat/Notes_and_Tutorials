/*
built in function

support for streaming large files via Streams API

not supported in old browsers

handles cookies and redirects
*/

const url = "https://reqres.in";
const path = "/api/users";
const uri = url + path;

const options = {
  method: "POST",
  headers: {
    "Content-type": "application/json; charset=utf-8",
  },
  body: JSON.stringify({
    name: "morpheus",
    job: "leader",
  }),
};

fetch(uri, options)
  .then((response) => response.json())
  .then((data) => console.log(data))
  .catch((error) => console.error(error));
