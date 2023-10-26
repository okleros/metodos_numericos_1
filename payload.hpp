#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>

namespace Consts {
	const std::string payload_header = "K,d,\tf(d),\terro";
}

struct Epoch
{
    double a, b, c;
    int t;

    Epoch(int t, double a, double b, double c) : a(a), b(b), c(c), t(t)
    {}

    std::string get_string()
    {
        std::stringstream ssa, ssb, ssc, sst, sab;

        sst << std::fixed << std::setprecision(6) << std::setw(2) << std::setfill('0') << t + 1;
        ssa << std::fixed << std::setprecision(6) << std::setw(9) << std::setfill('0') << a;
        ssb << std::fixed << std::setprecision(6) << std::setw(9) << std::setfill('0') << b;
        ssc << std::fixed << std::setprecision(6) << std::setw(9) << std::setfill('0') << c;

        std::string final_string = "T" + sst.str() + "," + ssa.str() + "," + ssb.str() + "," + ssc.str();

        return final_string;
    }
};


struct Payload
{
	std::vector<Epoch> epochs;

	void insert(Epoch e) { epochs.push_back(e); }
};

void print_test_table(Payload p)
{
    char char_to_replace = ',';
    char replacement_char = '\t';
    std::string dash = "-------------------------------------------------";

    std::string new_string = Consts::payload_header;

    std::replace_if(new_string.begin(), new_string.end(), [char_to_replace](char c) { 
            return c == char_to_replace; 
        }, 
        replacement_char);

    std::cout << dash << std::endl;
    std::cout << new_string << std::endl;
    std::cout << dash << std::endl;

    for (Epoch e : p.epochs)
    {
        new_string = e.get_string();

        std::replace_if(new_string.begin(), new_string.end(), [char_to_replace](char c) { 
            return c == char_to_replace; 
        }, 
        replacement_char);

        std::cout << new_string << std::endl;

    }

    std::cout << dash << std::endl;
}