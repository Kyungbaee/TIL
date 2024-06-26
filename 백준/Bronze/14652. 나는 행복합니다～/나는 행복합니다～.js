const fs = require('fs');
let input = fs.readFileSync(0,'utf-8').toString().trim().split(' ').map(value=>Number(value));
console.log(parseInt(input[2]/input[1]), parseInt(input[2]%input[1]));