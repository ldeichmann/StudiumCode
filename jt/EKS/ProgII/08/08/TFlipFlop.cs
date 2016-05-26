namespace GatesSwitchesDelegates
{
    /// <summary>
    /// The TFlipFlop class models a TFlipFlop, i.e. a component 
    /// holding a value. The value can be changed by toggling.
    /// </summary>
    public class TFlipFlop
    {
        /// <summary>
        /// Delegate type to be called when the state of the flip changed
        /// </summary>
        /// <param name="sender">The TFlipFlop whose value has changed</param>
        public delegate void FlipFlopToggledHandler(TFlipFlop sender);

        /// <summary>
        /// Delegate instance for notification about state changes
        /// </summary>
        public FlipFlopToggledHandler FlipFlogToggled;

        private bool state = false;

        /// <summary>
        /// State of the TFlipFlop. 
        /// </summary>
        public bool State {
            get
            {
                return state;
            }
            set
            {
                state = value;
                if (FlipFlogToggled != null)
                    FlipFlogToggled(this);
            }
        }

        /// <summary>
        /// Toggles the state of the TFlipFlop
        /// </summary>
        public void toggle()
        {
            State = !State;
        }
    }
}
