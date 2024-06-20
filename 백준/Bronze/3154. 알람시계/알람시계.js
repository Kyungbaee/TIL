const fs = require('fs');
let input = fs.readFileSync(0, 'utf-8').toString().split(':');
let cal_input = { ...input };
let effort_min = 13, answer = "";

while(parseInt(cal_input[0])<=99){
    let effort = 0, list = [];

    for(let i=0; i<2; ++i){
        if(cal_input[i][0]=="0"){
            list.push(3,1);
        }else{
            point = parseInt(cal_input[i][0])-1;
            list.push(parseInt(point/3),point%3);
        }
        if(cal_input[i][1]=="0"){
            list.push(3,1);
        }else {
            point = parseInt(cal_input[i][1])-1;
            list.push(parseInt(point/3),point%3);
        }
    }

    for(let i=0; i<=4; i+=2){
        effort += Math.abs(list[i]-list[i+2])+Math.abs(list[i+1]-list[i+3]);
    }
    if (effort_min > effort){
        effort_min = effort;
        answer = cal_input[0].toString()+':'+cal_input[1].toString();
    }
    cal_input[1] = (parseInt(cal_input[1])+60).toString();

    if(parseInt(cal_input[1])>99){
        cal_input[1] = input[1];
        cal_input[0] = (parseInt(cal_input[0])+24).toString();
    }
}

console.log(answer);