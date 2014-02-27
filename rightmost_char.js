
var fs = require("fs");
fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
    if (line !== ""){
	var sline = line.split(',');
	console.log(sline[0].lastIndexOf(sline[1]));
    }
}); 