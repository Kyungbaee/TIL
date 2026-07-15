class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0, sumEven = 0, answer = 0;

        for(int i=1; i<= 2*n; i++){
            if(i%2 == 1) sumOdd += i;
            else sumEven += i;
        }

        for(int i=1; i<=int(sqrt(sumEven)); i++)
            if(sumOdd%i == 0 && sumEven%i ==0) answer = i;

        return answer;
    }
};