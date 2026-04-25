#include <iostream>
#include "Action.h"
#include "CastingTime.h"
#include "Spell.h"
#include "DNDTypes.h"

using namespace std;

int main()
{
    Action action("Bite", "The monster bites");
    action.displayInfo();
    string patear = "patear";
    string descripcion = "patea el mamahuevo";
    action.setName(patear);
    action.setDescription(descripcion);
    cout << action.getName() << action.getDescription() << endl;

    CastingTime cast(5, TimeUnit::Hour);
    cast.displayInfo();
    cast.setAmount(10);
    cast.setTimeUnit(TimeUnit::Day);
    cout << cast.getAmount() << static_cast<int>(cast.getTimeUnit());

}