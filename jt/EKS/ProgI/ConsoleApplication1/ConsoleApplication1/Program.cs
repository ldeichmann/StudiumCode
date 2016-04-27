using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;


//TODO: Nullstellen rechner, polydiv, square root, ableiten, integrieren, binary to hex, hex to binary
namespace ConsoleApplication1
{
    class Program
    {

        static int add(int a, int b)
        {
            return a + b;
        }

        static int sub(int a, int b) {
            return a - b;
        }

        static int mul(int a, int b) {
            return a*b;
        }

        static int div(int a, int b) {
            if (b != 0)
                return a / b;
            else return 0;
        }

        static int pow(int a, int b) { // a^b  b--... b==0 -> abbruch

            if (b == 0)
                return 1;
            else
                return a * pow(a, b-1);
        }

        static void Main(string[] args)
        {
            while (true)
            {
                String input = System.Console.ReadLine();

                string resultString = Regex.Match(input, @"-?\d+").Value;
                string resultString2 = Regex.Match(input, @"-?\d+", RegexOptions.RightToLeft).Value;
                int value1 = Int32.Parse(resultString);
                int value2 = Int32.Parse(resultString2);

                char[] SpecialChars = "+-*/^".ToCharArray();
                int indexCalcSign = input.IndexOfAny(SpecialChars);

                char calcSign = input[indexCalcSign];

                if (calcSign == 0)
                    break;

                switch (calcSign)
                {
                    case '+':
                        Console.WriteLine("ergebnis: {0,4}", add(value1, value2));
                        break;
                    case '-':
                        Console.WriteLine("ergebnis: {0,4}", sub(value1, value2));
                        break;
                    case '*':
                        Console.WriteLine("ergebnis: {0,4}", mul(value1, value2));
                        break;
                    case '/':
                        Console.WriteLine("ergebnis: {0,4}", div(value1, value2));
                        break;
                    case '^':
                        Console.WriteLine("ergebnis: {0,4}", pow(value1, value2));
                        break;
                    //case 'x':
                    //    Environment.Exit();
                    //    break;
                    default:
                        Console.WriteLine("default case");
                        break;
                }
            }
            Console.ReadLine();
        }
    }
}
