using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _02
{

    class Messung
    {
        private int temperature;
        private string name;
        private bool fieber;

        public Messung(int t, String n) {
            Temperature = t;
            Name = n;
        }

        public Messung(String n)
        {
            Name = n;
        }

        public int Temperature 
        {
            get
            {
                return temperature;
            }
            protected set
            {
                if((value <= 41) && (value >= 18))
                    temperature = value;
                if (value >= 38)
                    Fieber = true;
            }
        }

        public bool Fieber{ get; private set; }

        public string Name
        {
            get
            {
                return name;
            }
            protected set
            {
                if(value != "")
                    name = value;
            }
        }

        public bool Steigend(Messung m)
        {
            if (m.Temperature > Temperature)
                return true;
            else
                return false;
        }
}
}
