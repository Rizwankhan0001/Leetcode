class Solution {
 public:
  string largestOddNumber(string num) {
     
        int last=-1;
        
         for(int i=0;i<num.size();i++){
             if(num[i]%2!=0){
                last=i;
            }
        }
        if(last!=-1){
            return num.substr(0,last+1);  
        }
        else
        return "";
  }
};
