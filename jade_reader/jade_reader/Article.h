#pragma once
#include <string>

class Article {
private:
	std::string img;
	std::string title;
	std::string description;
public:
	std::string getImg();
	std::string getTitle();
	std::string getDescription();
	Article(std::string img, std::string title, std::string description);
	~Article();
};

