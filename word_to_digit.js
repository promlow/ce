
var fs = require("fs");
fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
    if (line !== ""){
        var words = line.split(';');
        var l = "";
        for(var i = 0; i<words.length; i++){
            if      (words[i].charAt(0) === 'z') l += '0';
            else if (words[i].charAt(0) === 'o') l += '1';
            else if (words[i].charAt(0) === 'e') l += '8';
            else if (words[i].charAt(0) === 'n') l += '9';
            else if (words[i].charAt(0) === 't'){
                 if (words[i].charAt(1) === 'w')  
                     l += '2';
                else l+= '3';
            }
            else if (words[i].charAt(0) === 'f'){
                 if (words[i].charAt(1) === 'i')
                     l += '5';
                else l += '4';
            }
            else if (words[i].charAt(0) === 's'){
                 if (words[i].charAt(1) === 'i')
                     l += '6';
                else l += '7';
            }
        }
        console.log(l);
    }
});