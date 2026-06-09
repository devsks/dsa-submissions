class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev=0, one=1;

        for(int i=31;i>=0;--i)
        {
            uint32_t setBit = one<<i;
            if(n&setBit)
            {
                int ind = 31-i;
                rev|=(one<<ind);
            }
        }

        return rev;
    }
};
