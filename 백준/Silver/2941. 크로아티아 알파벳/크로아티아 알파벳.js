const fs = require('fs');
let input = fs.readFileSync(0,'utf-8').toString().trim();
let cnt = -1;

while(true){
    cnt++;
    if(input.includes('c=')){
        input = input.replace(/c=/," ");
        continue
    }
    if(input.includes('c-')){
        input = input.replace(/c-/," ");
        continue
    }
    if(input.includes('dz=')){
        input = input.replace(/dz=/," ");
        continue
    }
    if(input.includes('d-')){
        input = input.replace(/d-/," ");
        continue
    }
    if(input.includes('lj')){
        input = input.replace(/lj/," ");
        continue
    }
    if(input.includes('nj')){
        input = input.replace(/nj/," ");
        continue
    }
    if(input.includes('s=')){
        input = input.replace(/s=/," ");
        continue
    }
    if(input.includes('z=')){
        input = input.replace(/z=/," ");
        continue
    }   
    break;
}
console.log(cnt+input.replace(/ /g,"").trim().length);