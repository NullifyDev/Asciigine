using System.Diagnostics;
using Microsoft.VisualBasic.CompilerServices;
using Microsoft.Win32;
using static Asciigine.Utils;

namespace Asciigine;

public class Program
{
    static void Main(string[] args)
    {
        //Optimize();
        //Administrator.Request();
        //Outln("Hello!");
        //SWRestart();
        //CheckRegistry();
        //if (OperatingSystem.IsWindows()) CheckRegistry();
        //Console.OutputEncoding = System.Text.Encoding.UTF8;

        Console.Clear();
        if (args.Length <= 0) Environment.Exit(0);
        switch (args[0]) {
            case "--version":
            case "-v":
                Outln("Asciigine v1.0");
                break;
            case "new":
                if (Directory.Exists(args[1]))
                {
                    Project.ProjectName = args[1];
                    string rootProjDir = $"{Project.ProjectFolder}\\{Project.ProjectName}";
                    Outln(rootProjDir);
                    Directory.CreateDirectory($"{rootProjDir}\\Scripts");
                    File.Create($"{rootProjDir}/Main.cs");
                } else Error($"Asciigine: {args[1]}: Project not found.");

                    break;
            
            case "run":
                Project.ProjectName = args[1];
                Project.Run(args[1], args[2..^0]);
                break;
        }
    }

    private static void Optimize()
    {
        Outln($"Window:{Window.GetSize()[0]}:{Window.GetSize()[1]}\nBuffer: {Buffer.GetSize().x}:{Buffer.GetSize().y}");
        Buffer.SetSize((short)Window.GetSize()[0], (short)Window.GetSize()[1]);
    }
    /*private static void CheckRegistry()
    {
        string[,] requiredReg = new string[,]
        {
            //        RegistryHive            KeyDir               SubKey            IntendedVal
            {     "HKEY_CURRENT_USER",     @"Console",     "VirtualTerminalLevel",      "1"         }
        };
        
        for (int i = 0; i < requiredReg.Length; i++)
        {
            if (i >= requiredReg.Length) continue;
            using (var hklm = requiredReg[i, 0] switch
                   {
                       "HKEY_CURRENT_USER"   =>  RegistryKey.OpenBaseKey(RegistryHive.CurrentUser,   Environment.Is64BitOperatingSystem ? RegistryView.Registry64 : RegistryView.Registry32),
                       "HKEY_CLASSES_ROOT"   =>  RegistryKey.OpenBaseKey(RegistryHive.ClassesRoot,   Environment.Is64BitOperatingSystem ? RegistryView.Registry64 : RegistryView.Registry32),
                       "HKEY_LOCAL_MACHINE"  =>  RegistryKey.OpenBaseKey(RegistryHive.LocalMachine,  Environment.Is64BitOperatingSystem ? RegistryView.Registry64 : RegistryView.Registry32), 
                       "HKEY_USER"           =>  RegistryKey.OpenBaseKey(RegistryHive.Users,         Environment.Is64BitOperatingSystem ? RegistryView.Registry64 : RegistryView.Registry32),
                       "HKEY_CURRENT_CONFIG" =>  RegistryKey.OpenBaseKey(RegistryHive.CurrentConfig, Environment.Is64BitOperatingSystem ? RegistryView.Registry64 : RegistryView.Registry32),
                   })
            using (var key = hklm.OpenSubKey(requiredReg[i, 1]))
            {
                if (key == null) {
                    string name = requiredReg[i, 2];
                    hklm.CreateSubKey(name);
                    hklm.SetValue(name, requiredReg[i, 3]);
                    hklm.Close();  
                } else
                {
                    Outln(key.GetValue(requiredReg[i, 2]).ToString());
                    if (int.Parse(key.GetValue(requiredReg[i, 2]).ToString()) != 1)
                    {
                        key.SetValue(requiredReg[i,2], int.Parse(requiredReg[i,3]), RegistryValueKind.DWord);
                    }
                    Outln(key.GetValue(requiredReg[i, 2]).ToString());
                    /*var names = key.GetValueNames();
                    foreach (var x in names)
                    {
                        Outln(x);
                    }#1#
                    // if (key.GetValue(requiredReg[i,2]))
                    /*if (key.GetValue(requiredReg[i,2]) != 1) 
                        key.OpenSubKey(requiredReg[i, 2]).SetValue(requiredReg[i, 2], requiredReg[i, 3]);#1#
                }
            }
        }
    }*/
}
