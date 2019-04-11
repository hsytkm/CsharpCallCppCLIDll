using CppCliDll;
using System;

namespace MixedLanguage
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine($"C++/CLIのDLLコール");
            using (var cli = new CppCliClass())
            {
                Console.WriteLine($"  From C++/CLI");

                var mul = cli.Multi(2, 3);      // 掛け算の取得
                var str = cli.ToUpper("abCde"); // 大文字の取得
                Console.WriteLine($"  Multi={mul} / Upper:{str}");
                Console.WriteLine($"  Name={cli.PersonName} / Age={cli.PersonAge}");

                var person = cli.PersonClass;
                Console.WriteLine($"  Name={person.Name} / Age={person.Age}");
            }
            Console.ReadKey();
        }
    }
}
