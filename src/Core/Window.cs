namespace Asciigine;

public static class Window
{
    public static int WinHeight = Console.WindowHeight;
    public static int WinWidth  = Console.WindowWidth;

    public static bool IsRenderable => WinHeight <= 0 || WinWidth <= 0 || WinWidth >= Buffer.GetSize().x || WinWidth >= Buffer.GetSize().y;
    public static int[] GetSize() => new int[2] { WinWidth, WinHeight };

    public static void SetSize(int x, int y)
    {
        Console.SetWindowSize(x, y);
        WinWidth = Console.WindowWidth;
        WinHeight = Console.WindowHeight;
    }

    public static void ChangeBackgroundColor(ConsoleColor color) => Console.BackgroundColor = color;
    public static void ChangeForegroundColor(ConsoleColor color) => Console.ForegroundColor = color;

}