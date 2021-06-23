const readline = require("readline");

const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdou
});

rl.on("line", function(line) {
	const fib = [];
	
	fib[0] = 0;
	fib[1] = 1;
	fib[2] = 1;
	
	for(let i = 3; i <= parseInt(line); i++){
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	
	console.log(fib[parseInt(line)]);
	
	rl.close();
}).on("close", function(){
	process.exit();
});