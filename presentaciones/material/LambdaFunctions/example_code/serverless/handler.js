'use strict';


const work = (time) => {
  return new Promise(resolve => {
    for (var i = 0; i < time * 1000000; i++);
    resolve();
  })
}

module.exports.server = async (event, context) => {

  await work(500);
  
  return {
    "statusCode": 200,
    "headers": {
      "my_header": "my_value",
      'Content-Type': 'text/html'
    },
    body: "Hello World",
    "isBase64Encoded": false
  };
};
