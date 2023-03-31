using Asciigine.Core;
using static Asciigine.Utils;
namespace Asciigine;

public static class Renderer
{
    public static int buffW = Console.BufferWidth;
    public static int buffH = Console.BufferHeight;
    public static void Render()
    {
        Console.CursorVisible = true;
        if (buffH < Window.WinHeight) Console.BufferHeight = Window.WinHeight;
        if (buffW < Window.WinWidth)  Console.BufferWidth  =  Window.WinWidth;

        var now = Layers.Current.GetContent();
        var then = Layers.Previous.GetContent();
        
        for (int l = 0; l < Layers.Current.Content.Count(); l++)
        {
            for (int i = 0; i < Layers.Current.Content.ElementAt(l).Value.Frame.Count; i++)
            {
                if (Layers.Current.Content.ElementAt(l).Value.Frame[i].Pos.x > buffW || 
                    Layers.Current.Content.ElementAt(l).Value.Frame[i].Pos.x < 0) continue;
                
                if (Layers.Current.Content.ElementAt(l).Value.Frame[i].Pos.y > buffH || 
                    Layers.Current.Content.ElementAt(l).Value.Frame[i].Pos.y < 0) continue;
                
                if (Layers.Current.Content.ElementAt(l).Value.Frame[i].p == ' ') continue;

                Console.SetCursorPosition(
                    Layers.Current.Content.ElementAt(l).Value.Frame[i].Pos.x, 
                    Layers.Current.Content.ElementAt(l).Value.Frame[i].Pos.y
                );
                Out(Layers.Current.Content.ElementAt(l).Value.Frame[i].p.ToString());
            }
        }
        Console.CursorVisible = false;
    }
}