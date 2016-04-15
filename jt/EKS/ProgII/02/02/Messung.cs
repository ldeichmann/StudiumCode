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
        //private DateTime time;

                
        public bool Fieber { get; private set; }
        public DateTime Time { get; private set; }

        

        public Messung(int t, String n,  DateTime dt) {
            Temperature = t;
            Name = n;
            Time = dt;
        }
        public Messung(int t, String n)
        {
            Temperature = t;
            Name = n;
            Time = DateTime.UtcNow;
        }
         
        public Messung(String n, DateTime dt)
        {
            Name = n;
            Time = dt;
        }

        public Messung(String n)
        {
            Name = n;
            Time = DateTime.UtcNow;
        }

        public int Temperature 
        {
            get
            {
                return temperature;
            }
            private set
            {
                if((value <= 41) && (value >= 18))
                    temperature = value;
                if (value >= 38)
                    Fieber = true;
            }
        }

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

       public static bool Steigend(Messung m1, Messung m2)
        {

            if (DateTime.Compare(m1.Time, m2.Time) <= 0)
                return m1.Temperature > m2.Temperature;
            else
                return m1.Temperature < m2.Temperature;
        }
    }
}
