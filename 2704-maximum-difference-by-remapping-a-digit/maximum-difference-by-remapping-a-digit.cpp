class Solution {
public:
    int minMaxDifference(int num) {
        vector<int>arr,smallest;
        while(num>0){
            arr.push_back(num%10);
            num = num/10;
        }
        reverse(arr.begin(),arr.end());
        smallest = arr;
        int n  = arr.size();
        int nine=0;
        for(int i =0;i<n;i++){
            if(arr[i]!=9){
                nine = arr[i];
                break;
            }
        }
        for(int j=0;j<n;j++){
            if(arr[j]==nine){
                arr[j]=9;
            }
        }
        int zero =0;
        for(int k =0;k<n;k++){
            if(smallest[k]!=0){
               zero=smallest[k];
               break;
            }
        }
        for(int l=0;l<n;l++){
            if(smallest[l]==zero) smallest[l]=0;
        }
        for(int m =0;m<n;m++){
            arr[m]=arr[m]-smallest[m];
        }
        int number =0;
        int base =1;
        for(int p =n-1;p>=0;p--){
            number += arr[p]*base;
            base = base*10;
        }
        return number;
    }
};