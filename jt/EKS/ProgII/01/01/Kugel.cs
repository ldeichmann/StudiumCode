using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _01
{
   public class Kugel {
    
	//privates Attribut 
	private double _kugelRadius;

	//Konstruktor mit Abfrage ob Radius kleiner als 0 ist
	public Kugel(double kRadius) {
        if (kRadius > 0)
            KugelRadius = kRadius;
        else
        {
            KugelRadius = 0;
            Console.WriteLine("Eingabe muss groesser als 0 sein (hier eigentlich try/catch benutzten)");
        }
	}
    
    //Getter und Setter über Properties mit privatem Setter
    public double KugelRadius { get; private set; }

    //Methode berechnet Volumen der Kugel
	public double BerechneVolumen() {
		
		return 4.0/3.0*Math.PI*KugelRadius*KugelRadius*KugelRadius;
	}
    
    //Methode berechnet Oberfläche der Kugel
	public double BerechneOberflaeche() {
		
		return 4.0*Math.PI*KugelRadius*KugelRadius;
	}
    
    //Methode vergrößert das Volumen Kugel um den Faktor 8
	public void Aufblasen() {
         KugelRadius *= 2;
	}
    
	//Methode zum Vergleichen ob die Kugel mit der die Methode aufgerufen wird
    //kleiner oder gleich des Radius der Kugel ist, der der Methode als 
    //Parameter zugeteilt wird
	public bool istKleinerGleich(Kugel k) {
        if (KugelRadius <= k.KugelRadius)
            return true;
        else 
            return false;
	}
   }
}
