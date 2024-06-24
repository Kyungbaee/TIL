function solution(num){
    let result = +num;
    for(let i=0; i<num.length; i++)
        result += +num[i];
    return result
}

self_number = []
for(let i=1; i<=10000; ++i)
    self_number[solution(i.toString())] = 1;

for(let i=1; i<=10000; ++i)
    if(!self_number[i]) console.log(i);