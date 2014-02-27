
var fs = require("fs");
fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
    if (line !== ""){
	var num = parseInt(10);
	var bin = num.toString(2);
	var ones = 0;
	for(var i=0; i<bin.length; bin++){
	    if(bin.charAt(i) == '1'){
		ones++;
	    }
	}
        console.log(ones);
    }
});