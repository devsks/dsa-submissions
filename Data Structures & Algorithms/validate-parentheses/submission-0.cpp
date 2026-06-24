class Solution {
public:
    char reverse(char ch)
    {
        switch(ch)
        {
            case '}': return '{';
            case ')': return '(';
            case ']': return '[';
        }
        return 0;
    }
    bool isValid(string s) {
        stack<char> validator;
        string openParen = "([{";
        for(char ch : s)
        {
            if( openParen.find(ch)== string::npos)
            {
                if(validator.size() == 0 || validator.top() != reverse(ch))
                {
                    return false;
                }
                else
                    validator.pop();
            }
            else
                validator.push(ch);


        }
        return validator.size()==0;
    }
};
