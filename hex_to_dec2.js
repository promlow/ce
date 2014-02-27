
function doOp(op1, op2, operator){
    if      (operator == '+') { return op1 + op2; }
    else if (operator == '-') { return op1 - op2; }
    else if (operator == '/') { return op1 / op2; }
    else if (operator == '*') { return op1 * op2; }
}


var fs = require("fs");
fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
    if (line !== ""){
	var exp = line.split(' ');
	exp = exp.reverse();
	var arr = new Array();
	var result = 0;
	for(var i = 0; i < exp.length; i++){
	    if(isNaN(parseInt(exp[i]))){//it's not a number, so it's an operator
		result = doOp(arr.pop(), arr.pop(), exp[i]);
		arr.push(result);
	    }else{//it's a number
		arr.push(exp[i]);
	    }	
	}
        console.log(result);
    }
});