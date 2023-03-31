using static Asciigine.Utils;
using System.Reflection;

namespace Asciigine;

public static class Project
{
    public static string ProjectName;
    public static readonly string RootProjectFolder = Path.Join(Directory.GetCurrentDirectory(), "/Projects");
    public static string ProjectFolder = RootProjectFolder + ProjectName;

    public delegate void CurrProject(string[] args);
    public static CurrProject GetDelegate(string projectName, string[]? args, string @class = "Main")
    {
        ProjectName = projectName;
        // common argument checks
        if (projectName == null) Exception.Throw.ProjectNameMissing();
        if (!Directory.Exists($"{RootProjectFolder}/{projectName}")) Exception.Throw.NoSuchProjectName(projectName);

        // find class
        Type type = Type.GetType($"{projectName}.Main");
        if (type == null) Exception.Throw.NoTypeFound(projectName);

        // find method
        MethodInfo methodInfo = type.GetMethod("Run");
        if (methodInfo == null) 
            Exception.Throw.NoStartingPoint(projectName);

        // create the delegate
        if (methodInfo.IsStatic) Exception.Throw.MainIsStatic(projectName);
        return (CurrProject)Delegate.CreateDelegate(typeof(CurrProject), methodInfo.IsStatic ? null : Activator.CreateInstance(type), methodInfo);
    }

    public static void Run(string projectName, params string[]? args) => GetDelegate(projectName, args).Invoke(args);
}