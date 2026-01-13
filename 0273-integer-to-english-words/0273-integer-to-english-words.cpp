class Solution {
public:
    vector<string> below20 = {
        "", "One", "Two", "Three", "Four", "Five", "Six",
        "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
        "Thirteen", "Fourteen", "Fifteen", "Sixteen",
        "Seventeen", "Eighteen", "Nineteen"
    };

    vector<string> tens = {
        "", "", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    string convertBelow1000(int num){
        string ans = "";
        if(num >= 100){
            ans += below20[num/100] + " Hundred";
            num = num % 100;
            if(num > 0) ans += " ";
        }

        if(num >= 20){
            ans += tens[num/10];
            num = num % 10 ;
            if(num > 0) ans += " " + below20[num];
        }
        else if(num > 0){
            ans += below20[num];
        }

        return ans ;
    }

    string numberToWords(int num) {
        if(num == 0 ) return "Zero";
        string ans = "";

        if(num >= 1000000000){
            ans += convertBelow1000(num/1000000000) + " Billion";
            num = num % 1000000000;
            if(num > 0 ) ans += " ";
        }

        if(num >= 1000000){
            ans += convertBelow1000(num/1000000) + " Million";
            num = num % 1000000;
            if(num > 0 ) ans += " ";
        }

        if(num >= 1000){
            ans += convertBelow1000(num/1000) + " Thousand";
            num = num % 1000;
            if(num > 0) ans += " ";
        }

        if(num > 0){
            ans += convertBelow1000(num);
        }

        return ans ;
    }
};