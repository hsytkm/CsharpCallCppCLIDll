using CppCliDll;
using System;

namespace MixedLanguage
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine($"純粋C++/CLIのDLLコール");
            using (var cli = new CppCliClass())
            {
                var mul = cli.Multi(2, 3);      // 掛け算の取得
                var str = cli.ToUpper("abCde"); // 大文字の取得
                var person = cli.GetPersonClass();

                Console.WriteLine($"  From C++/CLI");
                Console.WriteLine($"  Multi={mul} / Upper:{str}");
                Console.WriteLine($"  Name={cli.GetPersonName()} / Age={cli.GetPersonAge()}");
                Console.WriteLine($"  Name={person.GetName()} / Age={person.GetAge()}");
            }
            Console.ReadKey();
        }
    }
}
