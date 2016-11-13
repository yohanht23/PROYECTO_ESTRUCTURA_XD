#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

bool checkOperator(const string &input);
void calculateRPN(const string &input, stack<double> &rpnStack);

int main()
{
    stack<double> rpnStack;
    string input;
    double number;

    cout << "==================================" << endl;
    cout << "Calculadora Notacion Polaca Inversa" << endl;
    cout << "==================================\n" << endl;

    cout << "Inserta lo que quieres calcular: " << endl;
    cout << "Entra 'C' para calcular\n" << endl;

    while (true)
    {
        cout << ">>" ;
        cin >> input;

        if(istringstream(input) >> number) //take numerical input if double add to stack
        {
            rpnStack.push(number);
        }

        else if(checkOperator(input)) //if not double check if operator
        {
            calculateRPN(input, rpnStack); //call calculation function
        }

        else if(input == "q" && "Q") //
        {
            cout << "Abortando operacion..." << endl;
            return 0;
        }

        else if(input == "c" && "C") //if c or C is input calculate RPN on the stack
        {
            if(rpnStack.size() < 1)
            {
                cout << "No hay nada, por favor inserte algo para calcular..." << endl;
            }

            if(rpnStack.size() == 1)
            {
                cout << "\nEl resultado del calculo es: " << rpnStack.top() << endl;
                rpnStack.pop();

                cout << "=======================================================" << endl;
                cout << "Inserta tus expresiones de nuevo o escribe 'Q' para salir" << endl;
                cout << "=====================================================\n" << endl;
            }

            if (rpnStack.size() > 1)
            {
                cout << "Demasiados operandos para realizar cálculos" << endl;

                while (!rpnStack.empty())
                {
                    rpnStack.pop();
                }
                cout << "Entra un nuevo sufijo..." << endl;
            }
        }

        else
        {
            cout << "Expresion invalida" << endl;
        }
    }
}

/*************************************************
* Checking for operator                          *
*************************************************/
bool checkOperator(const string &input)
{
    string operators[] = {"-", "+", "*", "/", "sqrt"};

    for(int i = 0; i < 5; i++)
    {
        if(input == operators[i])
        {
            return true;
        }
    }

    return false;
}

/*************************************************
* RPN Calculation Function                       *
*************************************************/
void calculateRPN(const string &input, stack<double> &rpnStack)
{
    double firstValue, secondValue, result;

    if (input == "-") //subtraction logic
    {
        if (!rpnStack.empty())
        {
            secondValue = rpnStack.top();
            rpnStack.pop();
            if (!rpnStack.empty())
            {
                firstValue = rpnStack.top();
                rpnStack.pop();

                result = firstValue - secondValue;
                rpnStack.push(result);
            }
            else if (rpnStack.empty())
            {
                cout << "Stack Underflow! Necesita más operandos para esta operación" << endl;
                while (!rpnStack.empty())
                {
                    rpnStack.pop();
                }
                cout << "Inserta de nuevo." << endl;
            }
        }

    }

    else if (input == "+") //addition logic
    {
        if (!rpnStack.empty())
        {
            secondValue = rpnStack.top();
            rpnStack.pop();
            if (!rpnStack.empty())
            {
                firstValue = rpnStack.top();
                rpnStack.pop();

                result = firstValue + secondValue;
                rpnStack.push(result);
            }
            else if (rpnStack.empty())
            {
                cout << "Stack Underflow! Necesita más operandos para esta operación" << endl;
                while (!rpnStack.empty())
                {
                    rpnStack.pop();
                }
                cout << "Inserta de nuevo" << endl;
            }
        }
    }

    else if (input == "*") //multiplication logic
    {
        if (!rpnStack.empty())
        {
            secondValue = rpnStack.top();
            rpnStack.pop();
            if (!rpnStack.empty())
            {
                firstValue = rpnStack.top();
                rpnStack.pop();

                result = firstValue * secondValue;
                rpnStack.push(result);
            }
            else if (rpnStack.empty())
            {
                cout << "Stack Underflow! Necesita más operandos para esta operación" << endl;
                while (!rpnStack.empty())
                {
                    rpnStack.pop();
                }
                cout << "Inserta de nuevo" << endl;
            }
        }
    }

    else if (input == "/") //division logic
    {
        if (!rpnStack.empty())
        {
            secondValue = rpnStack.top();
            rpnStack.pop();
            if (secondValue == 0)
            {
                cout << "Error: No se puede dividir por un valor por 0" << endl;

                while (!rpnStack.empty())
                {
                    rpnStack.pop();
                }
                cout << "Inserta de nuevo..." << endl;
            }
            else if (!rpnStack.empty())
            {
                firstValue = rpnStack.top();
                rpnStack.pop();

                result = firstValue / secondValue;
                rpnStack.push(result);
            }
            else if (rpnStack.empty())
            {
                cout << "Stack Underflow! Necesita más operandos para esta operación" << endl;

                while (!rpnStack.empty())
                {
                    rpnStack.pop();
                }

                cout << "Inserta de nuevo..." << endl;
            }
        }
    }

    else if (input == "sqrt") //square root logic
    {
        firstValue = rpnStack.top();
        rpnStack.pop();

        result = sqrt(firstValue);
        rpnStack.push(result);
    }
}