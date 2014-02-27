
var fs = require("fs");
fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
    if (line !== ""){
        var words = line.split(' ');
        for(var i = 0; i < words.length; i++){
            var c = words[i].charAt(0);
            words[i] = words[i].replace(c, c.toUpperCase());
        }
        var l = "";
        for(var j = 0; j<words.length; j++){
            l += words[j];
	    //They're very tricky on this one and have input lines

            if (j < words.length - 1){
                l += ' ';
            }
        }
        console.log(l);
    }
});