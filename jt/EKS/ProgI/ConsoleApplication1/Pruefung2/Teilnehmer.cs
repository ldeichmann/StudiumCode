using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pruefung2
{
    class Teilnehmer
    {
        private int mnr;

        public Teilnehmer(int Mnr, int versuch)
        {
            // TODO: Complete member initialization
            this.Mnr = Mnr;
            this.Versuch = versuch;
        }
        public int Mnr{ get; set; }
        public int Versuch{ get; set; }       
    }
}
