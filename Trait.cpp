#include "Trait.h"
#include <iostream>

Trait::Trait(const std::string& name, const std::string& description)
    : name(name), description(description)
{
}
        
//Setters
void Trait::setName(const std::string& name)
{
    this->name = name;
}
void Trait::setDescription(const std::string& description)
{
    this->description = description;
}

//Getters
std::string Trait::getName() const
{
    return name;
}
std::string Trait::getDescription() const
{
    return description;
}
void Trait::displayInfo() const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Description: " << description << std::endl;
}