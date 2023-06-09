﻿using static Asciigine.Utils;

namespace Asciigine.Core;
/// <summary>
/// TO DO: Find a way to constantly check for input without ever stopping or delaying the tick.
/// </summary>
public delegate void Keys();

public class InputEvent
{
    public EventHandler<Input.CustomArgs> KeyEvent;
    public void OnPress() => KeyEvent.Invoke(this, new Input.CustomArgs());
}

public class Input
{
    public static void KeyDown()
    {
        InputEvent iEvent = new();
        
        iEvent.KeyEvent += (s, args) => Outln($"[Button Press Found]");
        iEvent.OnPress();
    }

    public class CustomArgs: EventArgs
    {
        public object[] parameters { get; set; }
    }
}
