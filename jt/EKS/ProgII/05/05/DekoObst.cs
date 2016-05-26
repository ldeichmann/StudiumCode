using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _05
{
    class DekoObst : Zutat
    {
        public DekoObst(string name) : base (1, "Stueck", name)
        {
            
        }

        public override void Jumbofizieren()
        {
            throw new NotImplementedException();
        }
    }
}
