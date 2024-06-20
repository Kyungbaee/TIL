const fs = require('fs');
let input = fs.readFileSync(0, 'utf-8').toString().trim();
let cnt = 0;
let currentNum = input;

while (currentNum.length > 1) {
    let sum = 0n; // BigInt 초기화
    for (let i = 0; i < currentNum.length; i++) {
        sum += BigInt(currentNum[i]); // 각 자릿수를 BigInt로 더함
    }
    currentNum = sum.toString(); // 다음 반복을 위해 문자열로 변환
    cnt++;
}

console.log(cnt);

// 마지막 숫자가 3의 배수인지 판단
if (BigInt(currentNum) % 3n === 0n && BigInt(currentNum) !== 0n) {
    console.log("YES");
} else {
    console.log("NO");
}