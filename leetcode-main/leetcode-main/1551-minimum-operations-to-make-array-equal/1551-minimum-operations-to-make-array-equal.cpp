class Solution {
public:
    int nposelement(int n)
    {
        return 1+(n-1)*2;
    }
    int minOperations(int n) {
        //Odd length
        int mid;
        if(n%2!=0)
        {
            mid=n/2 +1;
            //To find mid element an=a+(n-1)d Arithmetic Progression
            int mid_ele=nposelement(mid);
            //Sum of AP n/2[2a+(n-1)d]
            int sum=0;
            // cout<<mid<<" "<<mid_ele<<endl;
            for(int i=1;i<=mid;i++)
            {
                sum+=abs((nposelement(i)-mid_ele));
                // cout<<sum<<" ";
            }
            // cout<<endl;
            return sum;
        }
        else
        {
            mid=n/2;
            int mid1=mid+1;
            int mid_ele=nposelement(mid);
            int mid_ele1=nposelement(mid+1);
            int mid_val=(mid_ele+mid_ele1)/2;
            int sum=0;
            for(int i=1;i<=mid;i++)
            {
                sum+=abs((nposelement(i)-mid_val));
            }
            return sum;
        }
        return 0;
    }
};