using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _05
{
    class DekoObst : Zutat
    {

        //abgeleiteter Konstruktor fuer DekoObst
        public DekoObst(string name) : base (1, "Stueckzahl", name)
        {
            
        }
        
        //overwritten Methode fuer DekoObst (tut nichts)
        public override void Jumbofizieren()
        {
        }
    }
}
