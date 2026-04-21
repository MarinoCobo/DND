#include "Action.h"
#include <iostream>

Action::Action(const std::string& name, const std::string& description)
    : name(name), description(description)
{
}
        
//Setters
void Action::setName(const std::string& name)
{
    this->name = name;
}
void Action::setDescription(const std::string& description)
{
    this->description = description;
}

//Getters
std::string Action::getName() const
{
    return name;
}
std::string Action::getDescription() const
{
    return description;
}
void Action::displayInfo() const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Description: " << description << std::endl;
}