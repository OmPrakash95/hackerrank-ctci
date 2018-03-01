#include<iostream>
#include<string>
#include<stack>

using namespace std;

stack <int> s;
//{{[[(())]]}}



bool is_balanced(string expression) {
    for(int i=0; i< expression.length(); i++){
    	if(expression[i] == '(')
    		s.push(0);
    	else if(expression[i] == ')'){
    		if(s.empty())return false;
    		if(s.top() == 0)s.pop();
            else return false;
    	}
    	else if(expression[i] == '[')
    		s.push(1);
    	else if(expression[i] == ']'){
    		if(s.empty())return false;
    		if(s.top() == 1)s.pop();
            else return false;
    	}
    	else if(expression[i] == '{')
    		s.push(2);
    	else if(expression[i] == '}'){
    		if(s.empty())return false;
    		if(s.top() == 2)s.pop();
            else return false;
    	}    	    	
    }
   	if(s.empty())return true;
   	while (!s.empty()) {
      s.pop();
   	}        
   	return false;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}