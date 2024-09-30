//
// Created by Keijo Länsikunnas on 5.3.2024.
//

#ifndef LAB12_INTEDIT_H
#define LAB12_INTEDIT_H
#include <string>
#include "MenuItem.h"

class IntEdit : public MenuItem {
public:
    explicit IntEdit(std::string menu_title);
    bool event(menuEvent e) override;
    void show() override;
protected:
    int value;
    int backup;
    bool changed;
};


#endif //LAB12_INTEDIT_H
