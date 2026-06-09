class Solution {
public:
    int getSum(int a, int b) {
        
        // a+b
        // a+b
        /*
            111110
            00001
            011110
            100010
        */
        bool neg = false;
        if(a<0 && b<0)
        {
            a*=-1;
            b*=-1;
            neg = true;
        }
        if(a< 0)
        {
            while(a<0)
            {
                ++a;
                --b;
            }
            return b;
        }
        if(b<0)
        {
            while(b<0)
            {
                ++b;
                --a;
            }
            return a;
        }
        int result = 0, carry =0;
        for(int i=0;i<32;++i)
        {
            int bitVal = 1<<i;
            if(bitVal > a && bitVal > b)
                break;

          
            if((a&bitVal) || (b&bitVal))
            {
                cout<<"["<<i<<"]";
                if( ( (a&bitVal) && (b&bitVal) ))
                {
                    if(carry && carry==i)
                    {
                        result|=(1<<carry);
                    }
                    carry = i+1;
                }
                else if(carry)
                {

                   // result|=(1<<carry);
                    carry = i+1;

                }
                else
                    result |=bitVal; 
         
            }
            if(carry && carry==i)
            {
                result|=(1<<carry);
                carry = 0;
            }
          //  cout<<result<<" ";
        }
        //cout<<result << " ";
        if(carry)
        {
            result|=(1<<carry);
        }
        if(neg)
            result*=-1;
        return result;
    }
};
