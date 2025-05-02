#include <stdio.h>
#include <stdlib.h>

// define a simple event
typedef enum {
	EVENT_CLICK,
	EVENT_KEYPRESS,
	EVENT_TIMER
} EventType_t;

// event handlers 
static void onClick() {
	printf("Button clicked\n");
}

static void onKeyPress() {
	printf("Key pressed\n");
}

static void dispatchEvent(EventType_t event) {
	switch (event) {
		case EVENT_CLICK:
			onClick();
			break;
		case EVENT_KEYPRESS:
			onKeyPress();
			break;
		default:
			printf("Unknown event\n");

	}
}

EventType_t getNextEvent() {
	// simulate getting an event
	return rand() % 2 == 0 ? EVENT_CLICK : EVENT_KEYPRESS;
}



// event loop
static void eventLoop() {
	while(1) {
		EventType_t event = getNextEvent();
		dispatchEvent(event);
	}
}

// callback functions 
static void registerCallback() {
	// store the callback for later use
}

int main() {
	eventLoop();
	return 0;
}



