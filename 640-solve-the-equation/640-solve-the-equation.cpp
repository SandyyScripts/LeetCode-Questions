class Solution {
public:
     void solveSide(string equation, int& coeff, int& num) {
        int N = equation.size();
        int sign = 1;
        coeff = 0, num = 0;
        
        for (int i=0; i<N; i++) {
            if (equation[i]=='-') { sign = -1; continue; }
            if (equation[i]=='+') { sign = 1; continue; }
            int j=i;
            while (i<N && isdigit(equation[i])) i++;
            if (j==i) { // -x, +x
                coeff += 1*sign;
                continue;
            }
            int tmp = stoi(equation.substr(j, i-j));
            if (equation[i]=='x')
                coeff += sign*tmp;
            else {
                num += sign*tmp;
                i--;
            }
        }
    }
    string solveEquation(string equation) {
       int posEqual = equation.find_first_of('=');
        string leftSide = equation.substr(0, posEqual);
        string rightSide = equation.substr(posEqual+1);
        
        int num1, num2, coeff1, coeff2;
        solveSide(leftSide, coeff1, num1);
        solveSide(rightSide, coeff2, num2);
        
        if (coeff1==coeff2)
            if (num1==num2) return "Infinite solutions";
            else return "No solution";
        return "x=" + to_string((num2-num1)/(coeff1-coeff2));
    }
};