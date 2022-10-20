class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        while(num >= 1000){
            num -= 1000;
            ans += "M";
        }
        while(num >= 900){
            num -= 900;
            ans += "CM";
        }
        while(num >= 500){
            num -= 500;
            ans += "D";
        }
        while(num >= 400){
            num -= 400;
            ans += "CD";
        }
        while(num >= 100){
            ans += "C";
            num -= 100;
        }
        while(num >= 90){
            ans += "XC";
            num -= 90;
        }
        while(num >= 50){
            num -= 50;
            ans += "L";
        }
        while(num >= 40){
            num -= 40;
            ans += "XL";
        }
        while(num >= 10){
            num -= 10;
            ans += "X";
        }
         while(num >= 9){
            num -= 9;
            ans += "IX";
        }
        while(num >= 5){
            num -= 5;
            ans += "V";
        }
        while(num >= 4){
            num -= 4;
            ans += "IV";
        }
        while(num > 0){
            num--;
            ans += "I";
        }
        return ans;
    }
};
