const fs = require('fs');
//let input = fs.readFileSync(0, 'utf-8').toString();
let input = fs.readFileSync(0, 'utf-8').toString().trim().split(" ").map(value=>+value);
console.log(input[0]+input[1]);