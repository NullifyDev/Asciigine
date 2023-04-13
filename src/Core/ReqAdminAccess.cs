using System.Runtime.InteropServices;
using System.Security.Principal;

namespace Asciigine
{
    public static class Administrator
    {
        #if (LINUX)
        [DllImport("libc")]
        public static extern uint getuid();
        #endif
            
         
        /// <summary>
        /// Asks for administrator privileges upgrade if the platform supports it, otherwise does nothing
        /// </summary>
        public static void Request()
        {
            string name = System.AppDomain.CurrentDomain.FriendlyName;
            try
            {
                if (RuntimeInformation.IsOSPlatform(OSPlatform.Windows))
                {
                    using (WindowsIdentity identity = WindowsIdentity.GetCurrent())
                    {
                        WindowsPrincipal principal = new WindowsPrincipal(identity);
                        if (!principal.IsInRole(WindowsBuiltInRole.Administrator)) throw new InvalidOperationException($"Application must be run as administrator. Right click the {name} file and select 'run as administrator'.");
                    }
                }
                #if (LINUX)
                if (getuid() != 0) throw new InvalidOperationException($"Application must be run as root/sudo. From terminal, run the executable as 'sudo {name}'");
                #endif
            }
            catch (System.Exception ex)
            {
                throw new ApplicationException("Unable to determine administrator or root status", ex);
            }
        }
    }
}
