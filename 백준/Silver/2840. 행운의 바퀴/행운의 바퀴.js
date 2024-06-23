const fs = require('fs');
let input = fs.readFileSync(0,'utf-8').toString().trim().split("\n");
let N = +input[0].split(" ")[0], K = +input[0].split(" ")[1];
let wheel = [];

cursor = 0, check = 1;
for(let i=0; i<K; i++){
    cursor = (cursor+parseInt(input[i+1].split(" ")[0]))%N;
    value = input[i+1].split(" ")[1].trim();
    index = wheel.findIndex(v=> v==(value));
    if(wheel[cursor]==null)
        wheel[cursor]=value;
    if(wheel[cursor]!=value || (index != -1 && index != cursor)){
        console.log("!");
        check = 0;
        break;
    }
}

if (check){
    for(let i=cursor; i>=0; i--){
        char = wheel[i];
        if (char != null)
            process.stdout.write(char);
        else
            process.stdout.write("?")
    }
    for(let i=N-1; i>cursor; i--){
        char = wheel[i];
        if (char != null)
            process.stdout.write(char);
        else
            process.stdout.write("?")
    }
}