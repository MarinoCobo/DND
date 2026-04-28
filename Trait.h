#ifndef TRAIT_H
#define TRAIT_H
#include <string>

class Trait
{
    private:
        std::string name;
        std::string description;
    public:
        Trait(const std::string& name, const std::string& description);
                
        //Setters
        void setName(const std::string& name);
        void setDescription(const std::string& description);

        //Getters
        std::string getName() const;
        std::string getDescription() const;
        void displayInfo() const;


};

#endif