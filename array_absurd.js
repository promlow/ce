
var fs = require("fs");
fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
    if (line !== ""){
	var tmp = line.split(';');
	//should check the length first
	var size = tmp[0];
	var nums = tmp[1].split(',')
	var i;
	var map = {}
	for(var i = 0; i < nums.length; i++){
	    // to run in proportional N assuming JS has constant lookup/assign
	    if (map[nums[i]] === undefined){
		map[nums[i]] = 'x'
	    }else{
		console.log(nums[i]);
	    }
	}
    }
}); 
