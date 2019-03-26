#include <Poco/Thread.h>
#include "src/MSSFMLView.h"
#include <iostream>
#include <string>
#include <unistd.h>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
const char slash = 0x5C;

#else
const char slash = 0x2F;

#endif

int lastslash(char findchar, std::string ourstring) {
	std::size_t temp;
	temp = ourstring.find_last_of(findchar);
	return temp;
}

void getexepath(const std::string lol, std::string &filelocation) {
	filelocation = lol;
	std::size_t whereami = lastslash(slash, filelocation);
	filelocation.erase(filelocation.begin() + (whereami + 1),
			filelocation.end());

}

int main(int argc, char **argv) {
	std::string s;

	getexepath(argv[0], s);
	std::cout << s + "config.conf" << std::endl;
	IO::FileManager settings(s + "config.conf");
	LFI(settings);
	sf::RenderWindow ref(
			sf::VideoMode(settings.value_INT(IO::Information::WIDTH),
					settings.value_INT(IO::Information::HEIGHT)),
			"Minesweeper");
	Graphic::MS_SFML_View Window(ref, settings,s);
	return 0;

}
