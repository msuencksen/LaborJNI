//
// Created by Admin on 06.05.2017.
//

#include "AppendText.h"

void AppendText::doAppendSomeText(std::string* currentText)
{
    std::string helloStr = " ... and from JNI C++";
    currentText->append(helloStr);
}
