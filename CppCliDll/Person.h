#pragma once

namespace CppCliDll {
	public ref class Person
	{
	private:
		System::String^ name;
		int age;

	public:
		Person(System::String^ name, int age) : name(name), age(age) {}

		~Person() {}
		!Person() {}

		property System::String^ Name { System::String^ get() { return name; } }
		property int Age { int get() { return age; } }

	};
}
