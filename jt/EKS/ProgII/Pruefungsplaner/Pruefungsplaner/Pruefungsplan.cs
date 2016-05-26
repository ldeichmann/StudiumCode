﻿using System;

public class Pruefungsplan
{
    // 4 Zeitslots pro Tag
    private Pruefung[][] plan = new Pruefung[4][];

    public Pruefungsplan()
    {
        for (int i = 0; i < plan.Length; i++)
            plan[i] = new Pruefung[5];
    }

    public void PlanePruefung(Pruefung pruefung)
    {
        for (int i = 0; i < plan.Length; i++)
        {
            for (int j = 0; j < plan[i].Length; j++)
            {
                if (plan[i][j] == null)
                {
                    plan[i][j] = pruefung;
                    return;
                }
            }
        }
    }

    public void PlanePruefungen(params Pruefung[] pruefungen)
    {
        foreach (Pruefung pruefung in pruefungen)
        {
            PlanePruefung(pruefung);
        }
    }

    public void GibPlanAus()
    {
        foreach (Pruefung[] tag in plan)
        {
            foreach (Pruefung inSlot in tag)
                if (inSlot != null)
                    Console.Write(" {0} ", inSlot.Name);
                else
                    Console.Write(" --- ");
            Console.WriteLine();
        }
    }
}

