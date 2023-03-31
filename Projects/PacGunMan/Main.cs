using static Asciigine.Utils;
using Asciigine.Core;
using Asciigine;
using PacGunMan.maps;
using Buffer = Asciigine.Buffer;

namespace PacGunMan;

public class Main
{
    public void Run(string[] args)
    {
        Asciigine.MapBuilder map = new();
        var loadedMap = map.FromTxt("maps/TestMap.map");
        var player = new Player("deez", new Vector(3, 5), '@');

        Buffer.Add(loadedMap, "map");
        Buffer.Add(Buffer.ToBuffer(Pixel.ToPixel(player.Position, player.model)), "player");
        Renderer.PrintFrame();
        // Buffer.ListLayers();
        while (true)
        {
            switch (Console.ReadKey(true).Key)
            {
                case ConsoleKey.W:
                    player.Position.y -= 1;
                    Buffer.Update(new Buffer(player.Position, player.model),2);
                    break;
                case ConsoleKey.S:
                    player.Position.y += 1;
                    Buffer.Update(new Buffer(player.Position, player.model),2);
                    break;
                case ConsoleKey.A:
                    player.Position.x -= 1;
                    Buffer.Update(new Buffer(player.Position, player.model),2);
                    break;
                case ConsoleKey.D:
                    player.Position.x += 1;
                    Buffer.Update(new Buffer(player.Position, player.model),2);
                    break;
                case ConsoleKey.P:
                    Console.Clear();
                    Console.SetCursorPosition(0, 0);
                    Environment.Exit(0);
                    break;
            }
            // Buffer.ListLayers();
            // Renderer.PrintFrame();
        }
    }
}