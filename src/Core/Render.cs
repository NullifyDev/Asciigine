using static Asciigine.Utils;
namespace Asciigine;

public static class Renderer
{
    public static int buffW = Console.BufferWidth;
    public static int buffH = Console.BufferHeight;
    public static Dictionary<string, Buffer> PrevLayers = new();
    public static Dictionary<string, Buffer> Layers = new();

    public static void PrintFrame()
    {
        if (buffH < Window.WinHeight) Console.BufferHeight = Window.WinHeight;
        if (buffW < Window.WinWidth)  Console.BufferWidth  =  Window.WinWidth;

        var now = Layers.Values;
        var then = PrevLayers.Values;
        
        for (int l = 0; l < Layers.Count(); l++)
        {
            for (int i = 0; i < Layers.ElementAt(l).Value.Frame.Count; i++)
            {
                if (Layers.ElementAt(l).Value.Frame[i].Pos.x > buffW || 
                    Layers.ElementAt(l).Value.Frame[i].Pos.x < 0) continue;
                
                if (Layers.ElementAt(l).Value.Frame[i].Pos.y > buffH || 
                    Layers.ElementAt(l).Value.Frame[i].Pos.y < 0) continue;
                
                if (Layers.ElementAt(l).Value.Frame[i].p == ' ') continue;

                Console.SetCursorPosition(
                    Layers.ElementAt(l).Value.Frame[i].Pos.x, 
                    Layers.ElementAt(l).Value.Frame[i].Pos.y
                );
                Out(Layers.ElementAt(l).Value.Frame[i].p.ToString());
            }
        }
    }
}