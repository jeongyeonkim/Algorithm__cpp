class Solution {
public:
    int reverse(int x) {
        string result_strX = "";
        
        for(int i = to_string(abs(x)).length() - 1; i >= 0; i--){
            result_strX += to_string(abs(x))[i];
        }
        
        long long result_int  = stoll(result_strX);
        
        if(result_int >= pow(2, 31)){
            return 0;
        }else if(x > 0){
            return result_int;
        }else {
            return -1 * result_int;
        }
    }
};