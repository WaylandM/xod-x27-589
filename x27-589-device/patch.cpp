
// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/clearwater/SwitecX25"

//Include C++ libraries
#include <SwitecX25.h>

node {

    meta {
        using Type = SwitecX25*;
    }

    static_assert(isValidDigitalPort(constant_input_PIN1), "must be a valid digital port");
    static_assert(isValidDigitalPort(constant_input_PIN2), "must be a valid digital port");
    static_assert(isValidDigitalPort(constant_input_PIN3), "must be a valid digital port");
    static_assert(isValidDigitalPort(constant_input_PIN4), "must be a valid digital port");

    // Number of steps = 315*3 = 945
    const uint16_t STEPS = 945;
    SwitecX25 gauge = SwitecX25(STEPS, constant_input_PIN1, constant_input_PIN2, constant_input_PIN3, constant_input_PIN4);

    void evaluate(Context ctx) {
        // It should be evaluated only once on the first (setup) transaction
        if (!isSettingUp())
            return;

        emitValue<output_DEV>(ctx, &gauge);
    }
}
