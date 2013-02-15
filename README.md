README:
This is a interface for option parser.
It is easy to use this software to parse the options such as:
./demo --arg1=val1 --arg2=val2
There are two steps to use this software
1) in the initialization, regist the option keys and default values
2) and then, using Option::parseOption(argv) to parse the options
option which is not registed in the initialization are not allowed in the command line 

the options are storaged in the Option::opt as a std::map.
you can access the option via: map[key].

Author: Yinan Yu
Contact: bebekifis@gmail.com
