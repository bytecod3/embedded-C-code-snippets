
typedef enum {
    stopped,
    started
} State;

struct DigitalWatch {
    State state;
    Timesource source;
    Display watchDisplay;
};

void startWatch(DigitalStopWatch instance) {
    switch (instance->state) {
        case started:
            // already started, do nothing
            break;
        case stopped:
            instance->state = started;
            break;
        default:
            error("Illegal state");
            break;
    }
}

void stopWatch(DigitalStopWatchPtr instance) {
    switch(instance->state) {
        case started:
            instance->state = stopped;
            break;
        case stopped:
            // already stopped, do nothing
            break;
        default:
            error("Illegal state"); break;
    }
}
