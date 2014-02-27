
var fs = require("fs");
fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
    if (line != ""){
	var words = line.split(' ');
	for(var i = 0; i<words.length; i++){
	    words[i] = words[i].replace("s/^[a-z]/[A-Z]/")
	}
	var l = "";
	for(var i = 0; i<words.length; i++){
	    l += words[i];
	}
	console.log(l);
    }
});