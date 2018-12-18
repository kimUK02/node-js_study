var http = require('http');
var fs = require('fs');
const port = 8888;
//404: if not exist html file
function send404Res(res) { 
    res.writeHead(404,{
        "Content-Type":"text/plain"
    });
    res.write("404 Not Found : oops;;");
    res.end();
}


http.createServer((req,res)=>{
    if(req.method == 'GET' && req.url == '/'){
        res.writeHead(200,{
            "Context-Type": "text/html" 
        });
        fs.createReadStream("./index.html").pipe(res);
    } else if(req.method == "GET" && req.url == '/click'){
        
        res.writeHead(200,{
            "Context-Type" : "text/html"
        });
        fs.createReadStream("./click.html").pipe(res);
    }else
        send404Res(res);
}).listen(port);
console.log("Server is Running on "+port); 