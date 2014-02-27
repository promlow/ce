
var fs = require("fs");
fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
    if (line !== ""){
	var nums = line.split(' ');
	nums = nums.reverse();
	var i = 0;
	var l = "";
	for(var j = 0; j<nums.length; j++){
	    if(i++ % 2 == 0){
		l = l + nums[j] + " ";
	    }
	}
	console.log(l.trim());
    }
}); 