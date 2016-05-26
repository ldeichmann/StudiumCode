using System;
using System.Collections.Generic;
namespace GatesSwitchesDelegates
{
    class GateSimulator
    {
        static void Main(string[] args)
        {
            List<Gate> gates = new List<Gate>() { new AndGate(true,true, false), new AndGate(false, false, true, false), new OrGate(true, true)};
            List<TFlipFlop> inputs = new List<TFlipFlop>() { new TFlipFlop(), new TFlipFlop(), new TFlipFlop()};
            ConsoleKeyInfo input;

            // Verbinden von Gates und Switches
            gates[0].ports[0].connectPort(inputs[0]);
            gates[0].ports[1].connectPort(inputs[1]);
            gates[0].ports[2].connectPort(inputs[2]);

            gates[1].ports[0].connectPort(inputs[2]);
            gates[1].ports[1].connectPort(inputs[2]);
            gates[1].ports[2].connectPort(inputs[1]);

            gates[2].ports[0].connectPort(inputs[2]);
            gates[2].ports[1].connectPort(inputs[0]);
            gates[2].ports[2].connectPort(inputs[1]);


            do
            {
                Console.Clear();
                Console.WriteLine("Switches");
                for (int i = 0; i < inputs.Count; i++)
                    Console.WriteLine("{0} : {1}", i, inputs[i].State);
                Console.WriteLine("Gates");
                foreach (Gate gate in gates)
                    Console.WriteLine(gate);
                Console.WriteLine("Select switch to toggle or ESC to exit");
                input = Console.ReadKey(true);
                if (input.KeyChar - '0' >= 0 && input.KeyChar - '0' < inputs.Count)
                     inputs[(int) (input.KeyChar - '0')].toggle();
            } while (input.Key != ConsoleKey.Escape);
        }
    }
}
