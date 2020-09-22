class Solution {
public:
    
    string check_tmb(int count){
        switch(count){
            case 0:
                return "";
            case 1:
                return "Thousand ";
            case 2:
                return "Million ";
            case 3:
                return "Billion ";
        }
        return "";
    }
    
    }
    string digit2_special_case(int num){
        switch(num){
            case 10:
                return "Ten";
            case 11:
                return "Eleven";
            case 12:
                return "Twelve";
            case 13:
                return "Thirteen";
            case 14:
                return "Fourteen";
            case 15:
                return "Fifteen";
            case 16:
                return "Sixteen";
            case 17:
                return "Seventeen";
            case 18:
                return "Eighteen";
            case 19:
                return "Nineteen";
            default:
                return "";       
        }
    }
    string digit2_to_english(int num){
            switch(num){
            case 2:
                return "Twenty";
            case 3:
                return "Thirty";
            case 4:
                return "Forty";
            case 5:
                return "Fifty";
            case 6:
                return "Sixty";
            case 7:
                return "Seventy";
            case 8:
                return "Eighty";
            case 9:
                return "Ninety";
            default:
                return "";
                
        }
    }
    
    string digit_to_english(int num){
        switch(num){
            case 1:
                return "One";
            case 2:
                return "Two";
            case 3:
                return "Three";
            case 4:
                return "Four";
            case 5:
                return "Five";
            case 6:
                return "Six";
            case 7:
                return "Seven";
            case 8:
                return "Eight";
            case 9:
                return "Nine";
            default:
                return "";
                
        }
    }
    string change_to_english(int num){
        string s;
        if (num / 100 >0){
            s +=  digit_to_english(num/100) + " " + "Hundred ";
            num %= 100;
        }
        if (num /10 >0){
            if (num/10 == 1){
                s += digit2_special_case(num) + " ";
                return s;
            } else{
                s += digit2_to_english(num/10) + " ";
            } 
            num %= 10;
        }
        if (num != 0)
            s += digit_to_english(num)+" ";
        return s;
        
    
    
    string numberToWords(int num) {
        vector<string> s;
        string ans;
        if (num ==0) return "Zero";
        int base =1000;
        int count = 0;
        while( num > 0){
            string str;
            int digit3_num = num %1000;
            if (digit3_num != 0){
                str = change_to_english(digit3_num) + check_tmb(count);
                s.push_back(str);
            }
            num /=1000;
            count++;
        }
        
        for (int i=s.size()-1; i>=0; i--){
            ans += s[i];
        }
        ans.pop_back();
        return ans;
    }
};