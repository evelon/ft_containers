#include "vector_common.hpp"

struct Leaky {
	std::string* a;
	Leaky();
	Leaky(std::string str);
	Leaky(const Leaky& a);
	Leaky&  operator=(const Leaky& a);
	~Leaky();
};

Leaky::Leaky() {
	a = new std::string("a");
}

Leaky::Leaky(std::string str) {
	a = new std::string(str + "a");
}

Leaky::Leaky(const Leaky& a) {
	this->a = new std::string(*a.a);
}

Leaky& Leaky::operator=(const Leaky& a) {
	delete this->a;
	this->a = new std::string(*a.a);
	return *this;
}

Leaky::~Leaky() {
	delete a;
}

int main() {
	{
		NS::vector<Leaky>	a(1, Leaky("default contructor"));
		a.clear();
		a = NS::vector<Leaky>(1, Leaky("copy contructor"));
		NS::vector<Leaky>	b(1, Leaky("overlap"));
		a = b;
		b.push_back(Leaky("resize"));
		b.resize(1);
		NS::vector<Leaky>	c(1, Leaky("reserve"));
		c.reserve(100);
		NS::vector<Leaky>	d(1, Leaky("iterator assignation"));
		d.assign(b.begin(), b.end());
		NS::vector<Leaky>	e(1, Leaky("value assignation"));
		e.assign(3, Leaky("value"));
		NS::vector<Leaky>	f(4, Leaky("pop_back"));
		f.pop_back();
		f.pop_back();
		f.pop_back();
		NS::vector<Leaky>	g;
		g.reserve(16);
		g.assign(16, Leaky("single insertion"));
		g.insert(g.begin(), Leaky("insertion"));
		g.reserve(32);
		g.assign(32, Leaky("multiple insertion"));
		g.insert(g.begin(), 3, Leaky("insertion"));
		g.reserve(64);
		g.assign(64, Leaky("iterator insertion"));
		g.insert(g.begin(), b.begin(), b.end());

		NS::vector<Leaky>	h(4, Leaky("erase"));
		h.erase(h.begin());
		h.erase(h.begin(), h.end());
	}
	system("leaks a.out | grep bytes)");
}