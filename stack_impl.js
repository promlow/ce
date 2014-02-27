
var fs = require("fs");
fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
    if (line !== ""){
	var nums = line.split(' ');
	//this is a bit of a cheat
	//instead of pushing and popping, just reverse
	//and grab every other item, starting with 0
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