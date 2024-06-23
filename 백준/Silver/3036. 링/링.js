const fs = require('fs');
let input = fs.readFileSync(0,'utf-8').toString().trim().split("\n");
let rings = +input[0], ring_len = input[1].split(" ").map(value=>+value);

for(let i=1; i<rings; i++){
    let num1 = ring_len[0], num2 = ring_len[i];
    let cnt = ring_len[i];
    while(cnt>1){
        if(num1%cnt==0 && num2%cnt==0){
            num1 /= cnt;
            num2 /= cnt;
        }
        cnt--;
    }
    console.log(num1.toString()+'/'+num2.toString());
}