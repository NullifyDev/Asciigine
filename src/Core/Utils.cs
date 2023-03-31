using System.Diagnostics;
using System.Net.Mime;
using System.Reflection;

namespace Asciigine;

public static class Utils
{
    public static void Out(string msg) => Console.Write(msg);
    public static void Outln(string msg) => Console.WriteLine($"{msg}");
    public static void Error(string msg) => Outln($"\u001b[38;2;230;0;250m{msg}");
    public static string Inln() => Console.ReadLine();
    public static int In() => Console.Read();

    public static void SWRestart()
    {
        Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
        Environment.Exit(0);
    }
    /*public static void Confirm(string msg, string def);
    {
        Outln($"{msg}");
        string input = Inln();
        if (input.ToLower() == "y") return;
        else if (input.ToLower() == def.ToLower()) Environment.Exit(0);
        else
        {
        }
    }*/

    public static void Crash(string msg)
    {
        Outln(msg);
        Environment.Exit(1); // Exception has been thrown
    }
    public static List<string> ReadLns(string path)
    {
        List<string> lines = new();
        foreach (var line in System.IO.File.ReadLines(@$"{path}"))
        {
            lines.Add(line);
        }
        return lines;
    }
}