#include "AppWindow.h"
int main() {
    AppWindow App;
    if (App.Init()) {
        while (App.isRunning()) {
            App.Broadcast();
        }
    }

    return 0;
}