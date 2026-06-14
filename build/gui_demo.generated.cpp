// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include "ui.hpp"
#include "str.hpp"

int main() {
    #line 1 "/home/maxime/AFRILANG/build/../examples/gui_demo.afr"
    afrilang::runtime::ui::openWindow("AFRILANG GUI", 640, 480);
    #line 11 "/home/maxime/AFRILANG/build/../examples/gui_demo.afr"
    while (afrilang::runtime::ui::isOpen()) {
        afrilang::runtime::ui::beginFrame();
        #line 4 "/home/maxime/AFRILANG/build/../examples/gui_demo.afr"
        afrilang::runtime::ui::clearBackground(28, 28, 36);
        #line 5 "/home/maxime/AFRILANG/build/../examples/gui_demo.afr"
        afrilang::runtime::ui::drawText("Bonjour depuis AFRILANG!", 60, 80, 32);
        #line 6 "/home/maxime/AFRILANG/build/../examples/gui_demo.afr"
        afrilang::runtime::ui::drawText("Cliquez sur Quitter pour fermer.", 60, 130, 20);
        #line 9 "/home/maxime/AFRILANG/build/../examples/gui_demo.afr"
        if (afrilang::runtime::ui::drawButton("Quitter", 220, 350, 200, 50)) {
            #line 8 "/home/maxime/AFRILANG/build/../examples/gui_demo.afr"
            afrilang::runtime::ui::closeWindow();
        }
        #line 10 "/home/maxime/AFRILANG/build/../examples/gui_demo.afr"
        afrilang::runtime::ui::showFrame();
    }
    return 0;
}
