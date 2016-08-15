class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count1[NUM_CHAR] = {0};
        int count2[NUM_CHAR] = {0};
        int i;
        int len1 = ransomNote.length();
        int len2 = magazine.length();
        
        for (i = 0; i < len1; ++i)
        {
            count1[ransomNote[i]]++;
        }
        
        for (i = 0; i < len2; ++i)
            count2[magazine[i]]++;
        
        for (i = 0; i < NUM_CHAR; ++i)
            if (count2[i] < count1[i])
                return false;

        return true;
    }
private:
    const static int NUM_CHAR = 256;
};

