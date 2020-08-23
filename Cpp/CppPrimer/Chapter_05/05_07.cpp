/*

a:
if (ival1 != ival2)
    ival1 = ival2;
else
    ival1 = ival2 = 0;

b : 
if (ival1 < minval)
{
    minval = ival;
    occurs = 1;
}

c: 
int ival = 1;

if (ival == get_value())
    std::cout << "ival = " << ival << std::endl;
if(!ival)
    std::cout << "ival = " << ival << std::endl;

d : 
if (0 == ival)
    ival = get_value();

*/