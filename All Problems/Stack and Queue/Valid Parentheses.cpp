bool isValidParenthesis(string expression)
{
    int n = expression.size();
    stack<char> s;
    for (int i = 0; i < n; i++)
    {
        char ch = expression[i];

        if (ch == '(' || ch == '{' || ch == '[')
            s.push(ch);

        else
        {
            // for closing bracket
            if (!s.empty())
            {
                char top = s.top();

                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
                    s.pop();

                else
                    return false;
            }

            else
                return false;
        }
    }

    if (s.empty())
        return true;

    else
        return false;
}

