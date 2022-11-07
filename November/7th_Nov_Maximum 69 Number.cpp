class Solution {
public:
    int dig(int n){
        int temp = n;
        int c = 0;
        while(temp > 0){
            temp /= 10;
            c++;
        }
        return c;
    }
    int maximum69Number (int num) {
        int digit = dig(num);
        int arr[digit];
        int i = 0;
        while(num > 0){
            arr[i] = num%10;
            num /= 10;
            i++;
        }
        for(int j = digit - 1;j >=0 ;j--){
            if(arr[j] == 6){
                arr[j] = 9;
                break;
            }
        }
        int ans = 0;
        for(int j = digit-1;j >=0;j--){
            ans = ans*10 + arr[j];
        }
        return ans;
    }
};
