const fs = require('fs');
let input = fs.readFileSync(0,'utf-8').toString().trim().split('\n').map(m=>m.trim());

for(let i=0; i<input.length-1; i++){
    if(input[i].includes(' ')){
        let N = +input[i].split(' ')[0], M = +input[i].split(' ')[1];
        let list = [];
        for(let j=1; j<=N; j++) list.push(input[i+j]);
        let answer_list = [];
        for(let j=0; j<input[i+N+1].length; j++)
            for(let k=0; k<N; k++){
                if(list[k].indexOf(input[i+N+1][j])!=-1)
                    answer_list.push([k, list[k].indexOf(input[i+N+1][j])]);
            }
        answer_list = answer_list.map(function(a,b) { 
            if (b<answer_list.length && b>0)
                return (Math.abs(a[0]-answer_list[b-1][0])+Math.abs(a[1]-answer_list[b-1][1]))+1;
            else
                return (a[0]+a[1]+1);
        });
        console.log(answer_list.reduce((a,b)=>a+b,0));
    }
}