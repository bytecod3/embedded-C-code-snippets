

enum {
    NO_CHANGE = 0xFF;
};

enum ExternalEvent_e {
    MOUSE_CURSOR_NEAR = 0,
    MOUSE_CURSOR_DISTANT,
    LEAF_NEAR,
    ARRIVED_HOME,
    EVENT_COUNT
};

enum AntBrainStateCode_e {
    FIND_LEAF = 0,
    RUN_AWAY,
    GO_HOME,
    STATE_COUNT
};

struct AntBrainState_t {
    enum AntBrainStateCode_e code;
    void (*stateFn)(void);
};

// state functions
void ant_brain_find_leaf(void);
void ant_brain_run_away(void);
void ant_brain_go_home(void);

enum ExternalEvent_e get_current_event(void);

void ant_brain_run(void) {
    struct AntBrainState_t find_leaf_state = {
            .code = FIND_LEAF,
            .stateFn = &ant_brain_find_leaf,
    };

    struct AntBrainState_t run_away_state = {
            .code = RUN_AWAY,
            .stateFn = &ant_brain_run_away
    };

    struct AntBrainState_t go_home_state = {
            .code = GO_HOME,
            .stateFn = &ant_brain_go_home
    };

    struct AntBrainState_t current_state  = find_leaf_source;

    for(;;) {
        current_state.stateFn();

        // get external event and check if it warrants state transition
        enum AntBrainState_t ext_event = get_current_event();
        struct AntBrainState_t next_state = {.code = NO_CHANGE};

        // handle state transitions
        switch (current_state.code) {
            case FIND_LEAF:
                if(ext_event == LEAF_NEAR) {
                    next_state = go_home_state;
                } else if(ext_event == MOUSE_CURSOR_NEAR) {
                    next_state = run_away_state;
                }
                break;
            case RUN_AWAY:
                if(ext_event == MOUSE_CURSOR_DISTANT) {
                    next_state = find_leaf_source
                }
                break;

            case GO_HOME:
                if(ext_event == ARRIVED_HOME) {
                    next_state = FIND_LEAF;
                }
                break;

            default:
                break;
        }


        // update state
        if(next_state.code != NO_CHANGE) {
            current_state = next_state;
        }

    }
}