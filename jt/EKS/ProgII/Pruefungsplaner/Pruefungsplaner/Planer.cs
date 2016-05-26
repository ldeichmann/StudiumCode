﻿using System;

class Planer
{
    public static void Main(string[] args)
    {
        Pruefungsplan plan = new Pruefungsplan();
        Pruefung mathe2 = new Pruefung("Ma2");
        Pruefung ge2 = new Pruefung("GE2");
        Pruefung physik2 = new Pruefung("Ph2");
        //plan.PlanePruefung(mathe2);
        //plan.PlanePruefung(ge2);
        plan.PlanePruefungen(physik2, mathe2, ge2);
        plan.GibPlanAus();
        Console.ReadLine();
    }
}
