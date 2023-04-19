const request = require('superagent');

const url = 'https://reqres.in';
const path = '/api/users';
const uri = url + path;

const data = {
  name: 'morpheus',
  job: 'leader',
};

const options = {
  headers: {
    'Content-type': 'application/json; charset=utf-8',
  },
  body: JSON.stringify(data),
};

request
  .post(uri)
  .set(options.headers)
  .send(options.body)
  .then((response) => console.log(response.body))
  .catch((error) => console.error(error));
