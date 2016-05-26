//using _05;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _05
{
    class Program
    {
        static void Main(string[] args)
        {
            Cocktail ColaRum= new Cocktail();
            ColaRum.Name = "ColaRum";
            ColaRum.PlusZutat(new NonAlkoholZutat(20, "Cola"));
            ColaRum.PlusZutat(new AlkoholZutat(5, "Rum"));
            ColaRum.PlusZutat(new DekoObst("Limone"));
            Console.WriteLine(ColaRum);

            ColaRum.Jumbofizieren();

            Console.WriteLine("***jumbofiziert***\n" + ColaRum);

            Console.ReadLine();
        }
    }
}
