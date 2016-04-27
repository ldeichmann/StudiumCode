using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Gate
{
    class Program
    {
        static void Main(string[] args)
        {
            //Gatter def = new Gatter(true, true);
            Gatter Or = new OrGatter(true, false);
            Gatter And = new AndGatter(true, true);
            Console.WriteLine(And);
            Console.WriteLine(Or);
            Console.ReadLine();
        }
    }
}
