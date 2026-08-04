class Solution {
public:
    uint32_t reverseBits(uint32_t n)
    {
        string binary = "";

        for(int i = 0; i < 32; i++)
        {
            if(n & (1 << i))
            {
                binary = binary + '1';
            }
            else
            binary = binary + '0';
        }

        return stoul (binary, nullptr, 2);

        
        
    }
};
