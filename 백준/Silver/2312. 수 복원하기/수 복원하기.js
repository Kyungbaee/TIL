const fs = require('fs');
let input = fs.readFileSync(0,'utf-8').toString().trim().split("\n").map(value=>+value);
let N = input[0];

for(i=1; i<=N; i++){
    dict = {}
    cnt = 2;

    while(input[i]>=cnt){
        if(input[i]%cnt==0){
            input[i] = input[i]/cnt;
            if (cnt in dict)
                dict[cnt] += 1
            else
                dict[cnt] = 1
        }
        else
            cnt++;
    }

    for(var key in dict)
        console.log(key,dict[key]);
}