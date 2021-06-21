const readline = require("readline");

function factorial(n){
	if(n < 2){
		return 1;
	}
	else{
		return n * factorial(n - 1);
	}
}

const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdou
});

rl.on("line", function(line) {
	const answer = factorial(parseInt(line));
	console.log(answer);
	
	rl.close();
}).on("close", function(){
	process.exit();
});
