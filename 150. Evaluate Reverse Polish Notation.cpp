class Solution {
public:
int evalRPN(vector<string>& tokens) {
	stack<int> s;
	for(auto& t : tokens) 
		if(t == "+" || t == "-" || t == "*" || t == "/") {
			int op1 = s.top(); s.pop();// poping the element from stack - 1st
			int op2 = s.top(); s.pop();// poping the next number from the stack- 2nd
			if(t == "+") op1 = op2 + op1;
			if(t == "-") op1 = op2 - op1;// here we are evaluating the expression
			if(t == "/") op1 = op2 / op1;// calculating the value
			if(t == "*") op1 = op2 * op1;   
			s.push(op1);// pushing the calculated value
		}
		else s.push(stoi(t));    // stoi - converts from string to int     
	return s.top(); // returing the final value
}
};
