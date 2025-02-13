#include<bits/stdc++.h>

using namespace std;


class IButton{
    public:
    virtual void press() = 0;
};
class WinButton : public IButton {
    public:
    void press(){
        cout << "Window button press" << endl;
    }
};
class MacButton : public IButton {
    public:
    void press(){
        cout << "Mac button press" << endl;
    }
};

class ITextBox{
    public:
    virtual void show() = 0;
};
class WinTextBox : public ITextBox {
    public:
    void show(){
        cout << "Window text box show" << endl;
    }
};
class MacTextBox : public ITextBox {
    public:
    void show(){
        cout << "Mac text box show" << endl;
    }
};


class IFactory{
    public:
    virtual IButton* createButton() = 0;
    virtual ITextBox* createTextBox() = 0;
};

class WindowsFactory : public IFactory {
    public:
    IButton* createButton(){
        return new WinButton();
    }
    ITextBox* createTextBox(){
        return new WinTextBox();
    }
};
class MacFactory : public IFactory {
    public:
    IButton* createButton(){
        return new MacButton();
    }
    ITextBox* createTextBox(){
        return new MacTextBox();
    }
};

class GUIFactory{
    public:
    static IFactory* CreateFactory(string os){
        if(os == "Windows")
            return new WindowsFactory();
        else if(os == "Max")
            return new MacFactory();
        else 
            return new MacFactory();
    }
};

int main(){
    cout << "Enter Os name" << endl;
    string os;
    cin >> os;

    IFactory * factory = GUIFactory::CreateFactory(os);

    IButton* button = factory->createButton();
    button->press();

    ITextBox* textBox = factory->createTextBox();
    textBox->show();

    return 0;
}