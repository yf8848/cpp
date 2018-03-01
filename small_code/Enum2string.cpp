#include <string>
#include <iostream>

template <typename Enum>
struct StringEnumEntry
{
	const char* string;
	Enum value;
};

enum EnumStaff
{
	kFoo,
	kBar,
	kLast,
};

const StringEnumEntry<EnumStaff> kStringTable[] = {
	{ "This is foo.", kFoo },
	{ "This is bar.", kBar },
	{ "This is last.", kLast },
};

template <typename Enum, int N>
std::string EnumToString(const StringEnumEntry<Enum>(&table)[N],
	Enum value)
{
	for (int i = 0; i < N; ++i)
	{
		if (table[i].value == value)
			return table[i].string;
	}
	return std::string();
}

template<typename Enum, int N>
Enum StringToEnum(const StringEnumEntry<Enum>(&table)[N],
	const std::string& string,
	Enum fallback)
{
	for (int i = 0; i < N; ++i)
	{
		if (table[i].string == string)
			return table[i].value;
	}
	return fallback;
}

int main()
{
    std::string str = EnumToString<>(kStringTable, kBar);
    std::cout << str << std::endl;

    EnumStaff value = StringToEnum(kStringTable, str, kFoo);;
    std::cout << value << std::endl;

    return 0;
}
