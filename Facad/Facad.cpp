// Facad.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class ControlPanel {
public:
    void StartButton() {
        cout << "Start button has been pressed! " << endl;

    }
    void FastMode() {
        cout << "Fast mode has been activated! " << endl;
    }
    void EndButton() {
        cout << "End button has been pressed! " << endl;
    }
};

class InnerPart {
public:

    void Drum() {
        cout << "Drum rotates! " << endl;
    }
    void Motor() {
        cout << "Powers drum! " << endl;
    }
};

class EndOfWashing {
public:
    void DrainPump() {
        cout << "Removes water from the drum after the wash and rinse cycles " << endl;
    }
};

class WashMachineFacade {
    ControlPanel contr;
    InnerPart inn;
    EndOfWashing end;
public:
    WashMachineFacade(ControlPanel c, InnerPart i, EndOfWashing e) {
        contr = c;
        inn = i;
        end = e;
    }
    void Start() {
        contr.StartButton();
        contr.FastMode();
        inn.Motor();
        inn.Drum();
    }
    void End() {
        contr.EndButton();
        end.DrainPump();
    }
};

class User {
public:
    void Washing(WashMachineFacade facade) {
        facade.Start();
        facade.End();
    }
};

int main()
{
    ControlPanel con;
    InnerPart in;
    EndOfWashing en;
    WashMachineFacade action(con, in, en);
    User use;
    use.Washing(action);
}


