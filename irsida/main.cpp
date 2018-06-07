#include <iostream>
#include "Program.h"

int main() {

    Student student("Irsida", "Mana", "white", "4324234", 18);
    Teacher teacher("Dushan", "Terzikj", "white", "42134123", 19);

    student.OutputIdentity();
    student.OutputAge();
    teacher.OutputIdentity();
    teacher.OutputAge();






    return 0;
}