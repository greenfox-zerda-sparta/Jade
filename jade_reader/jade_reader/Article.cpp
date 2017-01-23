#include "Article.h"



std::string Article::getImg()
{
	return img;
}

std::string Article::getTitle()
{
	return title;
}

std::string Article::getDescription()
{
	return description;
}

Article::Article(std::string img, std::string title, std::string description) : img(img), title(title), description(description){
	
}

Article::~Article()
{
}
