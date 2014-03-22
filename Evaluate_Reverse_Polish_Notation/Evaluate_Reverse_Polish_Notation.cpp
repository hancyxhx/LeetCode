// Evaluate the value of an arithmetic expression in Reverse Polish Notation.

// Valid operators are +, -, *, /. Each operand may be an integer or another expression.

//     Some examples:
//     ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//     ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6



#include <stack>

    class Solution {
    public:
	int evalRPN(vector<string> &tokens) {

	    stack<int> st;
	    int a, b;
	    for (int i = 0; i < tokens.size(); i++){
		if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
		    st.push(atoi(tokens[i].c_str()));
		    continue;
		}

		b = st.top();st.pop();
		a = st.top();st.pop();
		switch(tokens[i][0]){
		case '+':
		    st.push(a+b);break;
		case '-':
		    st.push(a-b);break;
		case '*':
		    st.push(a*b);break;
		case '/':
		    st.push(a/b);break;
		}
	    }
	    return st.top();
	}

    };

