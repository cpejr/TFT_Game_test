#ifndef JOYSTICK_
#define JOYSTICK_
#define DEAD_ZONE 10


class Joystick
{
    private:
        int pin_rX, pin_rY, pin_lX, pin_lY, button_l, button_r;
        int rX, rY, lX, lY;

    public:
        Joystick(int cpin_rX, int cpin_rY, int cpin_lX, int cpin_lY, int cbutton_l, int cbutton_r);
        int get_rX();
        int get_rY();
        int get_lX();
        int get_lY();
};


#endif