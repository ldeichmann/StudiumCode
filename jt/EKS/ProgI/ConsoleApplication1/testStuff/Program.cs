using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace testStuff
{
    class Program
    {

        public static void Square(ref int x)
        {
            x *= x;
        }

        public static void PrintNum(uint n, uint b = 2)
        {
            if (n == 0)
                return;
            PrintNum(n / b, b);
            Console.WriteLine("{0}", n % b);
        }

        //public static void PrintNum(uint n, uint b = 16)
        //{
        //    if (n == 0)
        //        return;
        //    PrintNum(n / b, b);
        //    Console.WriteLine("{0}", n % b);
        //}


        static void Main(string[] args)
        {

            //PrintNum(1213141516, 16);
            // Create a complex number by calling its class constructor.
            Complex c1 = new Complex(12, 6);
            //Console.WriteLine(c1);

            // Assign a Double to a complex number.
            Complex c2 = 3.14;
            //Console.WriteLine(c2);

            // Cast a Decimal to a complex number.
            Complex c3 = (Complex)12.3m;
            //Console.WriteLine(c3);

            // Assign the return value of a method to a Complex variable.
            Complex c4 = Complex.Pow(Complex.One, -1);
            //Console.WriteLine(c4);

            // Assign the value returned by an operator to a Complex variable.
            Complex c5 = Complex.One + Complex.One;
            //Console.WriteLine(c5);

            // Instantiate a complex number from its polar coordinates.
            Complex c6 = Complex.FromPolarCoordinates(10, .524);
            //Console.WriteLine(c6);

            int x = 4;
            //Console.WriteLine(Convert.ToString(1213141516,16));
            Square(ref x);
            //for (int i = 0; i <= 255; i++)
                //Console.Write("{0}    {1}     {2}\n",Convert.ToString(i, 2), Convert.ToString(i,16), i);

            Console.ReadLine();

            Pruefung mathe1 = new Pruefung();
            mathe1.Anmelden(256469);
            Console.WriteLine(mathe1.Teilnehmer);
        }
    }
}
