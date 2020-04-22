#include "control_keys.h"

#define ITEM(name, key) if (name == #key) return sf::Keyboard::key;

sf::Keyboard::Key ToSfKey(std::string name) {
    ITEM(name, A)
    ITEM(name, B)
    ITEM(name, C)
    ITEM(name, D)
    ITEM(name, E)
    ITEM(name, F)
    ITEM(name, G)
    ITEM(name, H)
    ITEM(name, I)
    ITEM(name, J)
    ITEM(name, K)
    ITEM(name, L)
    ITEM(name, M)
    ITEM(name, N)
    ITEM(name, O)
    ITEM(name, P)
    ITEM(name, Q)
    ITEM(name, R)
    ITEM(name, S)
    ITEM(name, T)
    ITEM(name, U)
    ITEM(name, V)
    ITEM(name, W)
    ITEM(name, X)
    ITEM(name, Y)
    ITEM(name, Z)
    ITEM(name, Num0)
    ITEM(name, Num1)
    ITEM(name, Num2)
    ITEM(name, Num3)
    ITEM(name, Num4)
    ITEM(name, Num5)
    ITEM(name, Num6)
    ITEM(name, Num7)
    ITEM(name, Num8)
    ITEM(name, Num9)
    ITEM(name, Escape)
    ITEM(name, LControl)
    ITEM(name, LShift)
    ITEM(name, LAlt)
    ITEM(name, LSystem)
    ITEM(name, RControl)
    ITEM(name, RShift)
    ITEM(name, RAlt)
    ITEM(name, RSystem)
    ITEM(name, Menu)
    ITEM(name, LBracket)
    ITEM(name, RBracket)
    ITEM(name, SemiColon)
    ITEM(name, Comma)
    ITEM(name, Period)
    ITEM(name, Quote)
    ITEM(name, Slash)
    ITEM(name, BackSlash)
    ITEM(name, Tilde)
    ITEM(name, Equal)
    ITEM(name, Dash)
    ITEM(name, Space)
    ITEM(name, Return)
    ITEM(name, BackSpace)
    ITEM(name, Tab)
    ITEM(name, PageUp)
    ITEM(name, PageDown)
    ITEM(name, End)
    ITEM(name, Home)
    ITEM(name, Insert)
    ITEM(name, Delete)
    ITEM(name, Add)
    ITEM(name, Subtract)
    ITEM(name, Multiply)
    ITEM(name, Divide)
    ITEM(name, Left)
    ITEM(name, Right)
    ITEM(name, Up)
    ITEM(name, Down)
    ITEM(name, Numpad0)
    ITEM(name, Numpad1)
    ITEM(name, Numpad2)
    ITEM(name, Numpad3)
    ITEM(name, Numpad4)
    ITEM(name, Numpad5)
    ITEM(name, Numpad6)
    ITEM(name, Numpad7)
    ITEM(name, Numpad8)
    ITEM(name, Numpad9)
    ITEM(name, F1)
    ITEM(name, F2)
    ITEM(name, F3)
    ITEM(name, F4)
    ITEM(name, F5)
    ITEM(name, F6)
    ITEM(name, F7)
    ITEM(name, F8)
    ITEM(name, F9)
    ITEM(name, F10)
    ITEM(name, F11)
    ITEM(name, F12)
    ITEM(name, F13)
    ITEM(name, F14)
    ITEM(name, F15)
    ITEM(name, Pause)
    ITEM(name, KeyCount)    
    return sf::Keyboard::Unknown;
}