using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _01
{
   class Kugel {
	
	private double _kugelRadius;
	
	public Kugel() {
		
	}

	public Kugel(double kRadius) {
		if(kRadius > 0)
			KugelRadius = kRadius;
		else
			System.Console.WriteLine("Radius muss größer als 0 sein");
	}

    public double KugelRadius { get; set; }

	public double BerechneVolumen() {
		
		return 4/3*Math.PI*KugelRadius*KugelRadius*KugelRadius;
	}

	public double BerechneOberflaeche() {
		
		return 4*Math.PI*KugelRadius*KugelRadius;
	}

	public void Aufblasen() {
        KugelRadius *= 8;
	}

	
	public bool istKleinerGleich(Kugel K) {
		if (KugelRadius <= K.KugelRadius)
            return true;
        else 
            return false;

	}
   }
}
