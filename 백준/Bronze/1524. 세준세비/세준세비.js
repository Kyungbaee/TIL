const fs = require('fs');
let input = fs.readFileSync(0,'utf-8').toString().trim().split('\n').map(value=>value.trim().split(' '));
let testcase = input[0], idx = 3;

for(let i=0; i<testcase; i++){
    let sejun = input[idx], sebi = input[idx+1];
    sejun = Math.max.apply(Math,sejun), sebi = Math.max.apply(Math,sebi);

    if (sejun > sebi)
        console.log("S");
    else if (sejun < sebi)
        console.log("B");
    else if (sejun == sebi){
        sejun_cnt = input[idx].filter(value => sejun == value).length;
        sebi_cnt = input[idx+1].filter(value => sebi == value).length;
        if (sejun_cnt>=sebi_cnt)
            console.log("S");
        else
            console.log("B");
    }
    idx += 4;
}