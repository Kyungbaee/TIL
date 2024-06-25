const fs = require('fs');
let input = fs.readFileSync(0,'utf-8').toString().trim().split('\n').map(value=>Number(value));
let num_list = [];

for(let i=1; i<input.length; i++){
    if(input[i]==0)
        num_list.pop();
    else
        num_list.push(input[i]);
}
console.log(num_list.reduce((a,b)=>a+b,0));