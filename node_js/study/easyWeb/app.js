var http = require('http');

function onRequest(res,req) {
        
}

http.createServer(onRequest).listen(8888);
console.log("Server is Running"); 