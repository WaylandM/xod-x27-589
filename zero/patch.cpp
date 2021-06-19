node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `SwitecX25` class instance
        auto gauge = getValue<input_DEV>(ctx);
        gauge -> zero();
        emitValue<output_DONE>(ctx, 1);
    }
}
