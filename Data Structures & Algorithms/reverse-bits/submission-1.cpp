class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        uint32_t res = 0;

        for(int i = 0; i < 32; i++)
        {
            //we extracted the bit at the nth position
            uint32_t bit = (n >> i) & 1;
            res+= (bit << (31-i));
        }
        return res;
    }
};
