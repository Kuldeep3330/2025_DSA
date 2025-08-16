// 1323. Maximum 69 Number
class Solution {
public:
    int maximum69Number (int num) {
        int placeValue=0;
        int placeValueSix=-1;
        int temp=num;
        while(temp>0){
            int remainder=temp%10;
            if(remainder==6){
                placeValueSix=placeValue;
            }
            temp=temp/10;

            placeValue++;
        }
        if(placeValueSix==-1)
        return num;

        return num+ 3* pow(10, placeValueSix);
        
    }
};