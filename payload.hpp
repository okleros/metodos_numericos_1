#include <vector>
#include <sstream>
#include <iomanip>

namespace Consts {
	const std::string payload_header = "Time (t),d,f(d),erro";
}

struct Epoch
{
public:
    int t;
    double a, b, c;

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
