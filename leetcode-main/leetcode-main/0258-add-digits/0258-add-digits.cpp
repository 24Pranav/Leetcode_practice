class Solution {
public:
    int addDigits(int num) {      \
        //O(N) Solution
//         int sum=0;
//         do
//         {
//             sum=0;
//         while(num)
//         {
//             // cout<<sum<<" "<<num<<endl;
//             sum+=num%10;
//             num/=10;
//         }
//             num=sum;
//     }while(sum>9);
        
//         return sum;
        
        //O(1) Solution
        return 1+(num-1)%9;
    }
};