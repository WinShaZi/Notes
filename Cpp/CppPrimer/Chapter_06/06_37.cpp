/*

string (&add_1(string (&st)[10]))[10]
{
	for (auto &n : st)
		n = "AAA";

	return st;
}

auto add_2(string (&st)[10]) -> string *
{
	for (auto &n : st)
		n = "AAA";

	return st;
}

string st[10];
decltype(st) *add_3(string (&st)[10])
{
	for (auto &n : st)
		n = "AAA";

	return st;
}

*/