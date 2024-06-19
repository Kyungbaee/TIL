const fs = require('fs');
let input = fs.readFileSync(0, 'utf-8').toString().split('\n');
const testCaseNum = +input[0];

for (let i=1; i<=testCaseNum; ++i){
    const cal = input[i].split(' ');
    if (cal[1] == '+' && BigInt(cal[0])+BigInt(cal[2])==BigInt(cal[4])){
        console.log("correct");
    }
    else if (cal[1] == '-' && BigInt(cal[0])-BigInt(cal[2])==BigInt(cal[4])){
        console.log("correct");
    }
    else if (cal[1] == '*' && BigInt(cal[0])*BigInt(cal[2])==BigInt(cal[4])){
        console.log("correct");
    }
    else if (cal[1] == '/' && BigInt(cal[0])/BigInt(cal[2])==BigInt(cal[4])){
        console.log("correct");
    }else{
        console.log("wrong answer");
    }
}